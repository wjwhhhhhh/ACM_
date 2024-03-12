#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
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
const int N=1e6+10;
UNdigraph gra;
int in[N];
bool use[N];
map<int,int>f;
stack<pair<int,int> >st;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    gra.init(n*2);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        in[a]++,in[b]++;
        gra.insert(a,b);
    }
    for(int i=1;i<=n;i++)
    {
        if(f.find(in[i])==f.end())f[in[i]]=i;
        else {st.push({f[in[i]],i}),f.erase(in[i]);}
    }
    while(st.size())
    {
        auto [x,y]=st.top();
        st.pop();
    }
    return 0;
}