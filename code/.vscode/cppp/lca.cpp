// #pragma GCC optimize(3, "Ofast", "inline")
#pragma comment(linker, "/STACK:2000000")
#include <bits/stdc++.h>

#define int long long

using ll = long long;

constexpr int N = 2e5 + 3, inf = 1e9 + 1;

int n;

struct Info
{
    int min;
    Info(int min = inf) : min(min)
    {
    }
};

Info operator+(const Info &a, const Info &b)
{
    return std::min(a.min, b.min);
}

template <class Info> struct SegmentTree
{
    int n;
    std::vector<Info> tr;

    SegmentTree()
    {
    }
    SegmentTree(int n)
    {
        init(n);
    }
    SegmentTree(std::vector<Info> w)
    {
        init(w);
    }

    void init(int n)
    {
        this->n = n;
        tr.resize(4 << std::__lg(n));
    }

    void init(std::vector<Info> w)
    {
        init(w.size());
        auto build = [&](auto self, int p, int l, int r) {
            if (r - l == 1)
            {
                tr[p] = w[l];
                return;
            }
            int m = l + r >> 1;
            self(self, 2 * p, l, m);
            self(self, 2 * p + 1, m, r);
            pull(p);
        };
        build(build, 1, 0, n);
    }

    void pull(int p)
    {
        tr[p] = tr[2 * p] + tr[2 * p + 1];
    }

    void modify(int p, int l, int r, int x, const Info &v)
    {
        if (r - l == 1)
        {
            tr[p] = v;
            return;
        }
        int m = (l + r) / 2;
        if (x < m)
        {
            modify(2 * p, l, m, x, v);
        }
        else
        {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }

    void modify(int p, const Info &v)
    {
        modify(1, 0, n, p, v);
    }

    Info rangeQuery(int p, int l, int r, int x, int y)
    {
        if (l >= y || r <= x)
        {
            return Info();
        }
        if (l >= x && r <= y)
        {
            return tr[p];
        }
        int m = (l + r) / 2;
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }

    Info rangeQuery(int l, int r)
    {
        return rangeQuery(1, 0, n, l, r);
    }
};

struct HLD
{
    int n;
    std::vector<int> siz, top, dep, fa, in, out, a;
    std::vector<std::vector<int>> g, adj;
    std::vector<std::array<int, 3>> e; // e[i] 代表第i条边
    int cur;
    std::vector<Info> seq;
    SegmentTree<Info> seg; // 线段树

    HLD()
    {
    }
    HLD(int n)
    {
        init(n);
    }
    void init(int n)
    {
        this->n = n;
        siz.resize(n);     // siz[u] : 以u为根的子树大小
        top.resize(n);     // top[u] : u所在的重链顶部的点
        dep.resize(n);     // dep[u] : 点u的深度
        fa.resize(n);      // fa[u] : 点u的父亲节点
        in.resize(n);      // in[u] : 点u的dfs序
        out.resize(n);     // 没用对过
        seq.resize(n);     // 理论上是有 seq[in[u]] = u的, 实际可以看情况变换
        a.resize(n);       // 点u的权值
        cur = 0;           // 时间戳的初始化
        adj.assign(n, {}); // 原图
        g.assign(n, {});   // dfs1之后删掉父亲节点之后的图
    }
    void addEdge(int u, int v, int w = 0)
    {
        e.push_back({u, v, w});
        g[u].push_back(v);
        g[v].push_back(u);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void addEdge2(int u, int v)
    {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    void work(int root = 0)
    {
        top[root] = root;
        dep[root] = 0;
        fa[root] = -1;
        dfs1(root);
        for (auto &[u, v, w] : e)
        {
            if (fa[u] != v)
            {
                std::swap(u, v);
            }
            a[u] = w;
        }
        dfs2(root);
        seg.init(seq);
    }
    void dfs1(int u)
    {
        if (fa[u] != -1)
        {
            g[u].erase(std::find(g[u].begin(), g[u].end(), fa[u]));
        }
        siz[u] = 1;
        for (auto &v : g[u])
        {
            assert(v >= 0 && v < n);
            assert(u >= 0 && u < n);
            fa[v] = u;
            dep[v] = dep[u] + 1;
            dfs1(v);
            assert(0);
            siz[u] += siz[v];

            if (siz[v] > siz[g[u][0]])
            {
                std::swap(v, g[u][0]);
            }
        }
    }
    void dfs2(int u)
    {
        in[u] = cur++;
        seq[in[u]] = a[u];
        for (auto v : g[u])
        {
            top[v] = v == g[u][0] ? top[u] : v;
            dfs2(v);
        }
        out[u] = cur;
    }

    int lca(int u, int v)
    {
        while (top[u] != top[v])
        {
            if (dep[top[u]] > dep[top[v]])
            {
                u = fa[top[u]];
            }
            else
            {
                v = fa[top[v]];
            }
        }
        return dep[u] < dep[v] ? u : v;
    }

    int dist(int u, int v)
    {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }

    int queryPath(int u, int v)
    {
        int ans = inf;
        while (top[u] != top[v])
        {
            if (dep[top[u]] < dep[top[v]])
            {
                std::swap(u, v);
            }
            ans = std::min(ans, seg.rangeQuery(in[top[u]], in[u] + 1).min);
            u = fa[top[u]];
        }
        if (dep[u] < dep[v])
        {
            std::swap(u, v);
        }
        return std::min(ans, seg.rangeQuery(in[v] + 1, in[u] + 1).min);
    }
};

std::set<int> st;
std::vector<int> ch;
int q[N], tt = 0;
HLD hld;
int f[N];
int k;
bool cmp(int x, int y)
{
    return hld.in[x] < hld.in[y];
}
int build()
{
    tt = 0;
    sort(ch.begin(), ch.end(), cmp);
    q[++tt] = ch[0];

    hld.g[ch[0]].clear();
    for (int i = 1; i < ch.size(); i++)
    {
        int l = hld.lca(ch[i], q[tt]);
        if (l != q[tt])
        {
            while (hld.in[l] < hld.in[q[tt - 1]])
            {
                hld.addEdge2(q[tt], q[tt - 1]), tt--;
            }
            if (l != q[tt - 1])
            {
                hld.g[l].clear(), hld.addEdge2(l, q[tt]), q[tt] = l;
            }
            else
            {
                hld.addEdge2(l, q[tt--]);
            }
        }
        hld.g[ch[i]].clear();
        q[++tt] = ch[i];
    }
    for (int i = 1; i < tt; i++)
    {
        hld.addEdge2(q[i], q[i + 1]);
    }
    return ch[0];
}
void dfs(int u, int fa)
{
    for (auto i : hld.g[u])
    {
        if (i != fa)
        {
            f[u]--, f[i]++;
            dfs(i, u);
        }
    }
}
std::vector<int> ans;
std::map<int, int> mp;
void dfs2(int u, int fa)
{
    for (auto i : hld.adj[u])
    {
        if (i != fa)
        {
            dfs2(i, u);
            f[u] += f[i];
        }
    }
    if (f[u] >= k)
        ans.push_back(mp[u]);
}

void get_bian()
{
    int l = 1;
    for (auto &i : hld.e)
    {
        if (hld.in[i[0]] > hld.in[i[1]])
            std::swap(i[0], i[1]);
        mp[i[1]] = l++;
    }
}
signed main()
{
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    freopen("test.txt", "r", stdin);
    int n, m;
    std::cin >> n >> m >> k;

    hld.init(n + 1);

    for (int i = 1; i < n; i++)
    {
        int u, v;
        std::cin >> u >> v;
        hld.addEdge(u, v);
    }
    hld.work(1);
    assert(0);
    // std::cerr << m << "Jkl" << '\n';
    get_bian();

    for (int t = 1; t <= m; t++)
    {
        ch.clear();
        int len;
        std::cin >> len;
        // std::cout<<len<<'\n';
        for (int i = 1; i <= len; i++)
        {
            int tem;
            std::cin >> tem;
            ch.push_back(tem);
        }
        int root = build();
        dfs(root, -1);
    }

    dfs2(1, -1);
    std::cout << ans.size() << '\n';
    std::sort(ans.begin(), ans.end());
    for (auto i : ans)
        std::cout << i << ' ';
    return 0;
}