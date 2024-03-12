#include <bits/stdc++.h>
struct ST
{
    std::vector<std::vector<int>> f, g, h;
    ST() :
    {
    }
    void init(int n, int m, std::vector<int> a) : f(n), g(n), h(n)
    {
        for (int i = 1; i <= n; i++)
        {
            f[i].resize(m), g[i].resize(m), h[i].resize(m);
            f[i][0] = g[i][0] = h[i][0] = a[i];
        }
        for (int j = 1; j <= m; j++)
        {
            for (int i = 1; i + (1ll << j) - 1 <= n; i++)
            {
                f[i][j] = std::max(f[i][j - 1], f[i + (1ll << (j - 1))][j - 1]);
                g[i][j] = std::min(g[i][j - 1], g[i + (1ll << (j - 1))][j - 1]);
                h[i][j] = std::gcd(h[i][j - 1], h[i + (1ll << (j - 1))][j - 1]);
            }
        }
    }
    int askMax(int l, int r)
    {
        int k = std::__lg(r - l + 1);
        return std::max(f[l][k], f[r - (1ll << k) + 1][k]);
    }
    int askMin(int l, int r)
    {
        int k = std::__lg(r - l + 1);
        return std::min(g[l][k], g[r - (1ll << k) + 1][k]);
    }
    int askGcd(int l, int r)
    {
        int k = std::__lg(r - l + 1);
        return std::gcd(h[l][k], h[r - (1ll << k) + 1][k]);
    }
};
struct Virtual_tree
{
    std::vector<std::vector<int>> Edge, Edge2, f;
    std::vector<std::pair<std::pair<int, int>, int>> edge;
    std::vector<int> dfn, po, dist, q;
    std::map<int, int> mp;
    ST st;
    int timestamp;
    int N, K, root;
    Virtual_tree()
    {
    }
    Virtual_tree(int n, int k = 25, int ro = 0)
    {
        N = n, K = k, root = ro;
        Edge.resize(n);
        dist.resize(n);
        timestamp = 0;
        dfn.resize(n * 2);
        po.resize(n * 2);
        q.reserve(n * 2);
    }
    void addEdge(int a, int b, std::vector<int> &Edge = Edge)
    {
        Edge[a].push_back(b), Edge[b].push_back(a);
    }
    void addEdgenum(int a, int b, int c)
    {
        edge.push_back({{a, b}, c});
    }
    void dfs(int u, int fa)
    {
        dfn[++timestamp] = u, po[u] = timestamp, mp[po[u]] = u;
        for (auto i : Edge[u])
        {
            if (fa != i)
            {
                dfs(i, u);
                dfn[++timestamp] = u;
            }
        }
    }
    void weightint()
    {
        for (auto i : edge)
        {
            int a = i.first.first, b = i.first.second, c = i.second;
            if (po[a] > po[b])
                std::swap(a, b);
            dist[a] += c;
        }
    }
    void init()
    {
        std::vector<int> a(2 * N);
        for (int i = 1; i <= timestamp; i++)
            a[i] = po[dfs[i]];
        dfs(root, -1);
        weightint();
        st.init(2 * N, m, a);
    }
    void build(std::vector<int> ch)
    {
        int qq = 0, tt = 0;
        auto cmp = [&](int x, int y) { return po[x] < po[y]; };
        sort(ch.begin(), ch.end(), cmp);
        q[++tt] = ch[0];
        Edge.[ch[0]].clear();
        for (int i = 1; i < ch.size(); i++)
        {
            int l = lca(ch[i], q[tt]);
            if (l != q[tt])
            {
                while (po[l] < po[q[tt - 1]])
                {
                    addEdge(q[tt], q[tt - 1]), tt--;
                }
                if (l != q[tt - 1])
                {
                    g[l].clear(), addEdge(l, q[tt]), q[tt] = l;
                }
                else
                {
                    addEdge(l, q[tt--]);
                }
            }
            Edge[ch[i]].clear();
            q[++tt] = ch[i];
        }
        for (int i = 1; i < tt; i++)
        {
            addEdge(q[i], q[i + 1]);
        }
    }
    int lca(int l, int r)
    {
        int tem = st.askMin(po[l], po[r]);
        return mp[tem];
    }
};
int main()
{
}