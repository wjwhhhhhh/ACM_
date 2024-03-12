#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
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
    int get_ring(vector<int> &cir, vector<int> &en)
    {
        int cir_size = 0, cnt = 0;
        cir.resize(2 * node_size), en.resize(2 * node_size);
        vector<int> fa(node_size), in(node_size), v(idx), st(node_size);
        function<void(int, int)> dfs_h = [&](int u, int fath) {
            st[u] = in[u] = true;
            for (int i = h[u]; ~i; i = ne[i])
            {
                // cerr << i << endl;
                if (v[i])
                    continue;
                v[i] = v[i ^ 1] = true;
                int j = e[i];
                fa[j] = u;
                if (!st[j])
                    dfs_h(j, u);
                else if (in[j])
                {
                    // cerr << "ok" << endl;
                    cir[cnt++] = fa[j];
                    for (int k = u; k != j; k = fa[k], cnt++)
                    {
                        cir[cnt] = fa[k];
                    }
                    en[cir_size++] = cnt;
                    cir[cnt++] = u;
                }
            }
            in[u] = false;
        };
        for (int i = 0; i < node_size; i++)
        {
            if (!st[i])
                dfs_h(i, -1);
        }
        return cir_size;
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
void solve()
{
    int n;
    cin >> n;
    UNdigraph gra(n, n);
    vector<int> deg(n);
    vector<int> fa(n);
    for (int i = 0; i < n; i++)
    {
        int b;
        cin >> b;
        b--;
        fa[i] = b;
        deg[b]++;
        gra.insert(i, b);
    }
    // cerr << "ok" << endl;
    vector<int> cir, en;
    int cir_size = gra.get_ring(cir, en);
    // cerr << cir_size << endl;
    vector<int> w(n);
    for (int i = 0; i < n; i++)
        cin >> w[i];
    vector<int> ans;

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (deg[i] == 0)
            q.push(i);
    }
    while (q.size())
    {
        auto x = q.front();
        q.pop();
        ans.push_back(x);
        for (int i = gra.h[x]; ~i; i = gra.ne[i])
        {
            int j = gra.e[i];
            deg[j]--;
            if (deg[j] == 0)
                q.push(j);
        }
    }
    for (int i = 0; i < cir_size; i++)
    {
        int l, r;
        if (i == 0)
        {
            l = 0, r = en[i];
        }
        else
            l = en[i - 1] + 1, r = en[i];
        // cerr << l << r << endl;
        vector<int> has;
        for (int i = l; i < r; i++)
            has.push_back(cir[i]);
        sort(has.begin(), has.end(), [&](int x, int y) { return w[x] > w[y]; });
        int ing = has.back(), cnt = fa[ing];
        while (1)
        {
            ans.push_back(cnt);
            if (cnt == ing)
                break;
            cnt = fa[cnt];
        }
    }

    for (auto x : ans)
        cout << x + 1 << " ";
    cout << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}