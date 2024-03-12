
#include <bits/stdc++.h>
#define int long long
using namespace std;
struct DSU
{
    std::vector<int> f, siz;

    DSU()
    {
    }
    DSU(int n)
    {
        init(n);
    }

    void init(int n)
    {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }

    int find(int x)
    {
        while (x != f[x])
        {
            x = f[x] = f[f[x]];
        }
        return x;
    }

    bool same(int x, int y)
    {
        return find(x) == find(y);
    }

    bool merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
        {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }

    int size(int x)
    {
        return siz[find(x)];
    }
};
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
DSU f;
bool fl=true;
void dfs(int u, int fa, UNdigraph &gra)
{

    for(int i=gra.h[u];~i;i=gra.ne[i])
    {
        int j=gra.e[i];
        if(j==fa)continue;
        dfs(j,u,gra);
        if(f.size(j)!=3)f.merge(j,u);
    }
}
void dfs2(int u, int fa, UNdigraph &gra, vector<int>&ans)
{
    if(f.size(u)!=3)fl=false;
    for (int i = gra.h[u]; ~i; i = gra.ne[i])
    {
        int j = gra.e[i];
        if (j == fa)continue;
        dfs2(j, u, gra, ans);
        if(!f.same(u,j))ans.push_back(i/2);
    }
}
void solves()
{
    int n;
    cin >> n;
    fl=true;
    UNdigraph gra(n);
    for (int i = 2; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        gra.insert(a - 1, b - 1);
    }
    f.init(n);
    dfs(0, -1, gra);
    vector<int> ans;
    dfs2(0, -1, gra, ans);
    if(fl)
    {
        cout<<ans.size()<<endl;
        for(auto i:ans)cout<<i+1<<' ';
        cout<<endl;
    }
    else cout<<"-1"<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solves();
    }
    return 0;
}