#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Graph // 有向图
{
    std::vector<int> e, ne, h, w;
    int idx = 0;
    int node_size;
    Graph()
    {
    }
    Graph(int n)
    {
        init(n);
    }
    Graph(int n, int m)
    {
        init(n, m);
    }
    void init(int n)
    {
        node_size = n;
        idx = 0;
        e.resize(2 * n), ne.resize(2 * n), w.resize(2 * n);
        h.resize(n, -1);
    }
    void init(int n, int m)
    {
        node_size = n;
        idx = 0, e.resize(m), ne.resize(m), w.resize(2 * n);
        h.resize(n, -1);
    }
    void add(int a, int b)
    {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }
    void add(int a, int b, int c)
    {
        w[idx] = c, e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }
    void clear(int si = 0) // 清空图
    {
        if (si == 0)
            si = node_size;
        fill(h.begin(), h.begin() + si, -1);
        idx=0;
    }
    void dfs(int u,int fath=-1)
    {
        for(int i=h[u];~i;i=ne[i])
        {
            int j=e[i];
            if(j!=fath)
            {
                dfs(j,u);
            }
        }
    }
};
struct UNdigraph : Graph // 无向图
{
    UNdigraph()
    {
    }
    UNdigraph(int a) : Graph(a)
    {
    }
    UNdigraph(int n, int m) : Graph(n, m)
    {
    }
    void insert(int a, int b)
    {
        add(a, b), add(b, a);
    }
    void insert(int a, int b, int c)
    {
        add(a, b, c), add(b, a, c);
    }
};
const int N=1e4+10;
int f[N],w[N],son[N];
UNdigraph gra;
void dfs1(int u,int fa)
{
    son[u]=1;
    int tem=0;
    for(int i=gra.h[u];~i;i=gra.ne[i])
    {
        int j=gra.e[i];
        if(j==fa)continue;
        dfs1(j,u);
        son[u]+=son[j];
    }
}
void dfs2(int u,int fa)
{
    for(int i=gra.h[u];~i;i=gra.ne[i])
    {
        int j=gra.e[i];
        if(j==fa)continue;
        w[i/2]=gra.w[i];
        f[i/2]=son[j];
        dfs1(j,u);
    }
}
void solves()
{
    int n,k;
    cin>>n>>k;
    memset(f,0,sizeof int*(n+5));
    memset(w,0,sizeof int*(n+5));
    memset(w,0,sizeof int*(n+5));
    gra.clear(n+5);
    for(int i=1;i<n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        gra.insert(a,b,c);
    }
    dfs1(1,-1);
    dfs2(1,-1);
    int ans=0;
    priority_queue<pair<int,int> > h;
    for(int i=0;i<=gra.idx/2;i++)
    {
        ans+=w[i]*f[i];
        h.push({w[i]/2*f[i],i});
    }
    while(k--&&h.size())
    {
        auto i=h.top();
        ans-=i.first;
        int x=i.first,y=i.second;
        w[y]-=w[y]/2;
        if(w[y])
        {
            h.push({w[y]/2*f[y],y});
        }
    }
    cout<<ans<<'\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin>>t;
    while (t--)
    {
        solves();
    }
    return 0;
}