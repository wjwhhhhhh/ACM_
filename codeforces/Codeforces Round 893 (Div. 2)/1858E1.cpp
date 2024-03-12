#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
template <class T> void chkmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
}
template <class T> void chkmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
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
            int a, b;
            cin >> a >> b;
            a--, b--;
            gra.insert(a, b);
        }
        return in;
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin >> n;
    UNdigraph gra(n + 1, n - 1);
    vector<pair<char, int>> add;
    int ing = 0;
    vector<int> que;
    vector<int> all;
    vector<array<int, 20>> fa(n + 1);
    all.push_back(0);
    for (int i = 0; i < n; i++)
    {
        cout << ing << endl;
        char a;
        cin >> a;
        if (a == '+')
        {
            int b;
            cin >> b;
            add.push_back({a, b});
            gra.insert(ing, add.size());
            fa[add.size()][0] = ing;
            for (int i = 1; i < 20; i++)
                fa[add.size()][i] = fa[fa[add.size()][i - 1]][i - 1];
            ing = add.size();
            all.push_back(ing);
        }
        else if (a == '?')
        {
            que.push_back(ing);
        }
        else if (a == '-')
        {
            int b;
            cin >> b;
            for (int i = 19; i >= 0; i--)
            {
                if (b >= (1 << i))
                {
                    ing = fa[ing][i];
                    b -= (1 << i);
                }
            }
            all.push_back(ing);
        }
        else
        {
            all.pop_back();
            ing = all.back();
        }
    }
    vector<int> mp(1000100);
    int res = 0;
    vector<int> ans(n + 1);
    function<void(int, int)> dfs = [&](int u, int fa) {
        ans[u] = res;
        for (int i = gra.h[u]; ~i; i = gra.ne[i])
        {
            int j = gra.e[i];
            if (j == fa)
                continue;
            if (mp[add[j - 1].second] == 0)
                res++;
            mp[add[j - 1].second]++;
            dfs(j, u);
            mp[add[j - 1].second]--;
            if (mp[add[j - 1].second] == 0)
                res--;
        }
    };
    dfs(0, -1);
    // for (auto ch : que)
    //     cout << ans[ch] << '\n';
    return 0;
}