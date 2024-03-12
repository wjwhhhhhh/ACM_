// #pragma GCC optimize(1)
// #pragma GCC optimize(2)
// #pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using ll = long long;

constexpr int N = 2e6 + 3, inf = 1e9 + 1;

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
std::set<int> st;
std::vector<int> ch;
int q[N], tt = 0;
HLD hld;
int f[N];
bool cmp(int x, int y)
{
    return hld.in[x] < hld.in[y];
}
void build()
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
                hld.addEdge(q[tt], q[tt - 1]), tt--;
            }
            if (l != q[tt - 1])
            {
                hld.g[l].clear(), hld.addEdge(l, q[tt]), q[tt] = l;
            }
            else
            {
                hld.addEdge(l, q[tt--]);
            }
        }
        hld.g[ch[i]].clear();
        q[++tt] = ch[i];
    }
    for (int i = 1; i < tt; i++)
    {
        hld.addEdge(q[i], q[i + 1]);
    }
}
void dfs(int u, int fa)
{
    f[u] = 0;
    for (auto i : hld.g[u])
    {
        if (i != fa)
        {
            dfs(i, u);
            if (st.find(i) != st.end())
            {
                f[u] += hld.queryPath(i, u);
            }
            else
                f[u] += std::min(f[i], hld.queryPath(i, u));
            // std::cout<<hld.queryPath(i,u)<<"\n";
        }
    }
}
signed main()
{
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);

    int n, m;
    std::cin >> n;

    hld.init(n + 1);

    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        edge.push_back({u, v, w});
        hld.addEdge(u, v);
    }

    hld.work(1);
    // std::cout<<hld.queryPath(1, 2)<<"\n";
    std::cin >> m;
    while (m--)
    {
        st.clear();
        ch.clear();
        int len;
        std::cin >> len;
        for (int i = 1; i <= len; i++)
        {
            int tem;
            std::cin >> tem;
            st.insert(tem);
            ch.push_back(tem);
        }
        ch.push_back(1);
        build();
        dfs(1, -1);
        std::cout << f[1] << '\n';
    }
    return 0;
}