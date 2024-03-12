#include <bits/stdc++.h>

using ll = long long;

constexpr int N = 1e5 + 3, inf = 1e9 + 1;

struct Edge
{
    int u, v, w;
};

int n;
int a[N];
std::vector<Edge> edge;

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
    std::vector<int> siz, top, dep, fa, in, out;
    std::vector<std::vector<int>> g;
    std::vector<Info> seq;
    int cur;
    SegmentTree<Info> seg;

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
        siz.resize(n);
        top.resize(n);
        dep.resize(n);
        fa.resize(n);
        in.resize(n);
        out.resize(n);
        seq.resize(n);
        cur = 0;
        g.assign(n, {});
    }
    void addEdge(int u, int v)
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
        for (auto &[u, v, w] : edge)
        {
            if (fa[u] == v)
            {
                a[u] = w;
            }
            else
            {
                a[v] = w;
            }
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
            fa[v] = u;
            dep[v] = dep[u] + 1;
            dfs1(v);
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

int main()
{
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);

    int n, m;
    std::cin >> n;

    HLD hld(n);

    edge.resize(n - 1);

    for (int i = 1; i < n; i++)
    {
        int p, w;
        std::cin >> p >> w;
        edge.emplace_back(i, p, w);
        hld.addEdge(i, p);
    }

    hld.work();

    while (q--)
    {
        int u, v;
        std::cin >> u >> v;
        std::cout << hld.queryPath(u, v) << "\n";
    }

    return 0;
}