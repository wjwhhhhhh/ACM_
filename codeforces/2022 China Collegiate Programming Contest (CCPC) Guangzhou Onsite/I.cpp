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
    }
    void dfs(int u, int fath = -1)
    {
        for (int i = h[u]; ~i; i = ne[i])
        {
            int j = e[i];
            if (j != fath)
            {
                dfs(j, u);
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
const int M=1e9+7,N=2100;
int a[N];
int qmi(int k, int p = M - 2)
{
    int res = 1;
    while (p)
    {
        if (p & 1)
            res = res * k % M;
        k = k * k % M;
        p >>= 1;
    }
    return res;
}
int g[N][N],f[N][N];//没 有
int p[N],ro[N];//传染 源
int ans[N];
int  fa[N];
UNdigraph gra(N);
int si[N];
void dfs(int u,int fath)
{
    si[u]=1;
    fa[u]=fath;
    g[u][1]=p[u];
    f[u][1]=a[u];
    g[u][0]=(1-p[u]+M)%M;
    f[u][0]=0;
    for(int i=gra.h[u];~i;i=gra.ne[i])
    {
        int j=gra.e[i];
        if(j==fath)continue;
        dfs(j,u);
        int tem[2][N];
        memset(tem,0,sizeof tem);
        for(int t=1;t<=si[u];t++)
        {
            for(int k=0;k<=si[j];k++)
            {
                tem[0][t+k]=(tem[0][t+k]+g[u][t]*g[j][k])%M;
                tem[1][t+k]=(tem[1][t+k]+f[u][t]*g[j][k])%M;
                if(k)tem[1][t+k]=(tem[1][t+k]+g[u][t]*f[j][k])%M;
            }
        }
        si[u]+=si[j];
        for(int t=0;t<=si[u];t++)
        {
            g[u][t]=tem[0][t];
            f[u][t]=tem[1][t];
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;

    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        gra.insert(a,b);
    }
    int tem=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        tem+=a[i];
        int x,y;
        cin>>x>>y;
        ro[i]=x*qmi(y)%M;
    }
    tem=qmi(tem);
    for(int i=1;i<=n;i++)
    {
        p[i]=tem*a[i]%M;
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j==1)
            {
                ans[i]=(ans[i]+g[j][i])%M;
            }
            else ans[i]=(ans[i]+g[j][i]*(1-p[fa[j]]))%M;
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<(ans[i]+M)%M<<"\n";
    }
    return 0;
}