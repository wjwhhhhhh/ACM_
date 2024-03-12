#pragma GCC optimize(3, "Ofast")

#include <bits/stdc++.h>

using ll = long long;

// assume -mod <= x < 2mod
constexpr int mod = 998244353;

int norm(int x)
{
    if (x < 0)
    {
        x += mod;
    }
    if (x >= mod)
    {
        x -= mod;
    }
    return x;
}
template <class T> T power(T a, ll b)
{
    T res = 1;
    for (; b; b /= 2, a *= a)
    {
        if (b % 2)
        {
            res *= a;
        }
    }
    return res;
}
struct Z
{
    int x;
    Z(int x = 0) : x(norm(x))
    {
    }
    Z(ll x) : x(norm(x % mod))
    {
    }
    int val() const
    {
        return x;
    }
    Z operator-() const
    {
        return Z(norm(mod - x));
    }
    Z inv() const
    {
        assert(x != 0);
        return power(*this, mod - 2);
    }
    Z &operator*=(const Z &rhs)
    {
        x = ll(x) * rhs.x % mod;
        return *this;
    }
    Z &operator+=(const Z &rhs)
    {
        x = norm(x + rhs.x);
        return *this;
    }
    Z &operator-=(const Z &rhs)
    {
        x = norm(x - rhs.x);
        return *this;
    }
    Z &operator/=(const Z &rhs)
    {
        return *this *= rhs.inv();
    }
    friend Z operator*(const Z &lhs, const Z &rhs)
    {
        Z res = lhs;
        res *= rhs;
        return res;
    }
    friend Z operator+(const Z &lhs, const Z &rhs)
    {
        Z res = lhs;
        res += rhs;
        return res;
    }
    friend Z operator-(const Z &lhs, const Z &rhs)
    {
        Z res = lhs;
        res -= rhs;
        return res;
    }
    friend Z operator/(const Z &lhs, const Z &rhs)
    {
        Z res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, Z &a)
    {
        ll v;
        is >> v;
        a = Z(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Z &a)
    {
        return os << a.val();
    }
};

struct HLD
{
    int n;
    std::vector<int> siz, top, fa, in, out, dep, seq;
    std::vector<std::vector<int>> g;
    std::vector<std::array<Z, 51>> pw;
    std::array<std::vector<Z>, 51> c;
    int cur;
    int maxdep;

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
        for (auto &it : c)
        {
            it.assign(n, 0);
        }
    }
    void addEdge(int u, int v)
    {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    void work(int root = 0)
    {
        maxdep = 0;
        top[root] = root;
        dep[root] = 0;
        fa[root] = -1;
        dfs1(root);
        dfs2(root);
        pw.resize(maxdep + 1);

        for (int i = 1; i <= maxdep; i++)
        {
            pw[i][1] = i;
            for (int j = 2; j <= 50; j++)
            {
                pw[i][j] = 1;
                pw[i][j] *= pw[i][j - 1] * i;
            }
        }
        for (int i = 1; i <= 50; i++)
        {
            for (int j = 1; j < n; j++)
            {
                c[i][j] = c[i][j - 1] + pw[dep[seq[j]]][i];
            }
        }
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
            maxdep = std::max(maxdep, dep[v]);
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
        seq[in[u]] = u;
        for (auto v : g[u])
        {
            top[v] = v == g[u][0] ? top[u] : v;
            dfs2(v);
        }
        out[u] = cur;
    }

    Z queryPath(int u, int v, int k)
    {
        Z ans = 0;
        while (top[u] != top[v])
        {
            if (dep[top[u]] < dep[top[v]])
            {
                std::swap(u, v);
            }
            ans += c[k][in[u]] - c[k][in[top[u]] - 1];
            u = fa[top[u]];
        }
        if (dep[v] < dep[u])
        {
            std::swap(u, v);
        }
        ans += c[k][in[v]] - c[k][in[u] - 1];
        return ans;
    }
};

int main()
{
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);

    int n, m;
    std::cin >> n;

    HLD hld(n + 1);

    for (int i = 1; i < n; i++)
    {
        int u, v;
        std::cin >> u >> v;
        hld.addEdge(u, v);
    }

    hld.work(1);

    std::cin >> m;
    while (m--)
    {
        int u, v, k;
        std::cin >> u >> v >> k;
        std::cout << hld.queryPath(u, v, k) << "\n";
    }

    return 0;
}
