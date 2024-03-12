#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr int mod = 1000000007;
int N, T, seed, vmax;
int rnd(int &seed)
{
    int ret = seed;
    seed = (7LL * seed + 13) % mod;
    return ret;
}

struct DSU
{
    std::vector<int> p;
    DSU(int n) : p(n)
    {
        std::iota(p.begin(), p.end(), 0);
    }
    int find(int x)
    {
        if (p[x] == x)
        {
            return x;
        }
        return p[x] = find(p[x]);
    }
    bool merge(int x, int y)
    {
        x = find(x), y = find(y);
        if (x == y)
        {
            return false;
        }
        p[y] = x;
        return true;
    }
};

DSU f(3e5 + 10);
std::pair<int, int> getEdge(int n, int &seed, DSU &dsu)
{
    int x = rnd(seed) % n, y = rnd(seed) % n;
    while (!dsu.merge(x, y))
    {
        x = rnd(seed) % n, y = rnd(seed) % n;
    }
    return {x, y};
}
struct Graph // 有向图
{
    std::vector<int> e, ne, h, w;
    int idx = 0;
    int node_size, edge_size;
    Graph()
    {
    }
    Graph(int n, int m)
    {
        init(n, m);
    }
    void init(int n, int m)
    {
        node_size = n;
        edge_size = m;
        idx = 0, e.resize(m), ne.resize(m), w.resize(m);
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
        idx = 0;
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
    static const int W = 25;
    vector<array<int, W>> fa;
    vector<int> depth;
    bool is_use;
    int root;
    UNdigraph()
    {
    }
    UNdigraph(int n, int m) : Graph(n, 2 * m)
    {
        node_size = n, edge_size = m;
        is_use = false;
        root = 0;
    }
    void dfs(int u, int fath)
    {
        fa[u][0] = fath, depth[u] = depth[fath] + 1;
        // cerr<<depth[u]<<" "<<u<<endl;
        for (int i = 1; i < W; i++)
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        for (int i = h[u]; ~i; i = ne[i])
        {
            int j = e[i];
            if (j != fath)
            {
                dfs(j, u);
            }
        }
    }
    int lca(int x, int y)
    {
        if (!is_use)
        {
            // cerr<<node_size;
            depth.resize(node_size);
            fa.resize(node_size);
            dfs(root, root);
            is_use = true;
        }
        if (depth[x] < depth[y])
            swap(x, y);
        for (int i = __lg(depth[x]); ~i; i--)
        {
            if (depth[fa[x][i]] >= depth[y])
                x = fa[x][i];
        }
        // cout<<x<<y<<endl;
        if (x == y)
            return x;
        for (int i = __lg(depth[x]); ~i; i--)
        {
            if (fa[x][i] != fa[y][i])
            {
                x = fa[x][i], y = fa[y][i];
            }
        }
        return fa[x][0];
    }
    void insert(int a, int b)
    {
        add(a, b), add(b, a);
    }
    void insert(int a, int b, int c)
    {
        add(a, b, c), add(b, a, c);
    }

    vector<int> cut_point() // 割点
    {
        vector<int> dfn(node_size), low(node_size), vis(node_size), flag(node_size);
        int inde, res;

        function<void(int, int)> Tarjan = [&](int u, int father) { // u 当前点的编号，father 自己爸爸的编号
            vis[u] = true;                                         // 标记
            low[u] = dfn[u] = ++inde;                              // 打上时间戳
            int child = 0;                                         // 每一个点儿子数量
            for (int i = h[u]; ~i; i = ne[i])
            {
                int v = e[i];
                if (!vis[v])
                {
                    child++;                      // 多了一个儿子
                    Tarjan(v, u);                 // 继续
                    low[u] = min(low[u], low[v]); // 更新能到的最小节点编号
                    if (father != u && low[v] >= dfn[u] && !flag[u])
                    {
                        flag[u] = true;
                        res++; // 记录答案
                    }
                }
                else if (v != father)
                    low[u] = min(low[u], dfn[v]); // 如果这个点不是自己，更新能到的最小节点编号
            }
            if (father == u && child >= 2 && !flag[u])
            {
                flag[u] = true;
                res++; // 记录答案
            }
        };
        for (int i = 0; i < node_size; i++)
        {
            if (!vis[i])
            {
                inde = 0;
                Tarjan(i, i);
            }
        }
        vector<int> p;
        for (int i = 0; i < node_size; i++)
            if (flag[i])
                p.push_back(i);
        return p;
    };
    vector<int> cut_edge()
    {
        vector<int> dfn(node_size), low(node_size), vis(node_size), bridge(edge_size);
        int inde, res;
        function<void(int, int)> tarjan = [&](int x, int in_edge) {
            dfn[x] = low[x] = ++inde;
            for (int i = h[x]; ~i; i = ne[i])
            {
                int y = e[i];
                if (!dfn[y])
                {
                    tarjan(y, i);
                    low[x] = min(low[x], low[y]);
                    if (low[y] > dfn[x])
                        bridge[i / 2] = true;
                }
                else if (i != (in_edge ^ 1))
                    low[x] = min(low[x], dfn[y]);
            }
        };
        for (int i = 0; i < node_size; i++)
        {
            if (!vis[i])
            {
                inde = 0;
                tarjan(i, i);
            }
        }
        vector<int> p;
        for (int i = 0; i < edge_size; i++)
            if (bridge[i])
                p.push_back(i);
        return p;
    }
    friend istream &operator>>(istream &in, UNdigraph &gra)
    {
        // TODO: 在此处插入 return 语句
        for (int i = 0; i < gra.edge_size; i++)
        {
            auto [x, y] = getEdge(N, seed, f);
            // std::cerr << x << " " << y << std::endl;
            gra.insert(x, y);
        }
        return in;
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;

    cin >> N >> T >> seed >> vmax;
    UNdigraph gra(N, N - 1);
    cin >> gra;
    gra.depth.resize(gra.node_size);
    gra.fa.resize(gra.node_size);
    gra.dfs(0, 0);
    vector<int> val(N, 0);
    i64 ans = 0;
    function<void(int, int)> get = [&](int u, int fa) {
        ans += val[u];
        for (int i = gra.h[u]; ~i; i = gra.ne[i])
        {
            int j = gra.e[i];
            if (j != fa)
                get(j, u);
        }
    };
    function<void(int, int, int)> add = [&](int u, int fa, int x) {
        val[u] += x;
        for (int i = gra.h[u]; ~i; i = gra.ne[i])
        {
            int j = gra.e[i];
            if (j != fa)
                add(j, u, x);
        }
    };
    function<void(int, int, int)> modd = [&](int u, int fa, int x) {
        (val[u] %= x);
        for (int i = gra.h[u]; ~i; i = gra.ne[i])
        {
            int j = gra.e[i];
            if (j != fa)
                modd(j, u, x);
        }
    };
    for (int t = 1; t <= T; t++)
    {
        int opt, u, x, p;
        opt = rnd(seed) % 5 + 1;
        u = rnd(seed) % N;
        if (opt == 3)
        {
            x = rnd(seed) % vmax + 1;

            add(u, gra.fa[u][0], x);
        }
        else if (opt == 4)
        {
            p = rnd(seed) + 1;

            modd(u, gra.fa[u][0], p);
        }
        else if (opt == 1)
        {
            x = rnd(seed) % vmax + 1;
            val[u] += x;
            for (int i = gra.h[u]; ~i; i = gra.ne[i])
            {
                int j = gra.e[i];
                val[j] += x;
            }
        }
        else if (opt == 2)
        {
            x = rnd(seed) % vmax + 1;
            if (u == 0)
                val[u] += x;
            else
            {
                u = gra.fa[u][0];
                for (int i = gra.h[u]; ~i; i = gra.ne[i])
                {
                    int j = gra.e[i];
                    if (j != gra.fa[u][0])
                        val[j] += x;
                }
            }
        }
        else
        {
            ans = 0;

            get(u, gra.fa[u][0]);
            cout << ans << '\n';
        }
    }
    return 0;
}