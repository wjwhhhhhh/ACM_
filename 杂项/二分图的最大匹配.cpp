#include <bits/stdc++.h>
using i64 = long long;
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
int main()
{
    int n1, n2, m;
    scanf("%d%d%d", &n1, &n2, &m);
    int s = 0, t = n1 + n2 + 1;
    Flow<int> flow(t + 1);
    while (m--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        flow.addEdge(x, n1 + y, 1);
    }
    for (int i = 1; i <= n1; i++)
    {
        flow.addEdge(s, i, 1);
    }
    for (int i = n1 + 1; i <= n1 + n2; i++)
    {
        flow.addEdge(i, t, 1);
    }
    printf("%d\n", flow.maxFlow(s, t));
    return 0;
}