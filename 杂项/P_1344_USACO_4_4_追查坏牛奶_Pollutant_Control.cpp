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
template <typename T> struct Flow
{
    const int n;
    static constexpr T inf = std::numeric_limits<T>::max();
    struct Edge
    {
        int to;
        T cap;
        Edge(int to, T cap) : to(to), cap(cap)
        {
        }
    };
    std::vector<Edge> e;
    std::vector<std::vector<int>> g;
    std::vector<int> cur, d;
    Flow(int n) : n(n), g(n)
    {
    }

    void addEdge(int u, int v, T c, T d = 0)
    {
        g[u].push_back(e.size());
        e.emplace_back(v, c);
        g[v].push_back(e.size());
        e.emplace_back(u, d);
    }

    bool bfs(int s, int t)
    {
        d.assign(n, -1);
        std::queue<int> q;
        d[s] = 0;
        q.push(s);
        while (!q.empty())
        {
            auto u = q.front();
            q.pop();
            for (int i : g[u])
            {
                auto [v, c] = e[i];
                if (c && d[v] == -1)
                {
                    d[v] = d[u] + 1;
                    if (v == t)
                        return true;
                    q.push(v);
                }
            }
        }
        return false;
    }

    T dfs(int u, int t, T f)
    {
        if (u == t)
            return f;
        auto r = f;
        for (int &i = cur[u]; i < g[u].size(); i++)
        {
            auto j = g[u][i];
            auto &[v, c] = e[j];
            auto &[_, rc] = e[j ^ 1];
            if (c && d[v] == d[u] + 1)
            {
                auto a = dfs(v, t, std::min(r, c));
                c -= a;
                rc += a;
                r -= a;
                if (!r)
                    return f;
            }
        }
        return f - r;
    }

    T maxFlow(int s, int t)
    {
        T ans = 0;
        while (bfs(s, t))
        {
            cur.assign(n, 0);
            ans += dfs(s, t, inf);
        }
        return ans;
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n, m;
    cin >> n >> m;
    Flow<i64> flow(n);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        flow.addEdge(a, b, 1ll * c * 1001 + 1);
    }
    i64 res = flow.maxFlow(0, n - 1);
    cout << res / 1001 << " ";

    std::cout << res % 1001 << "\n";

    return 0;
}