#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    std::vector<std::vector<std::tuple<int, int, int>>> adj(n);
    while (m--)
    {
        int a, b, x, y;
        scanf("%d%d%d%d", &a, &b, &x, &y);
        a--, b--;
        adj[a].emplace_back(b, x, y);
        adj[b].emplace_back(a, -x, -y);
    }

    std::queue<int> q;
    q.push(0);

    std::vector<std::pair<i64, i64>> dis(n, {-1, -1});
    dis[0] = {};

    while (!q.empty())
    {
        auto u = q.front();
        q.pop();

        for (auto [v, dx, dy] : adj[u])
        {
            if (dis[v] == std::pair(-1LL, -1LL))
            {
                dis[v] = {dis[u].first + dx, dis[u].second + dy};
                q.push(v);
            }
        }
    }

    for (auto [x, y] : dis)
    {
        if (x == -1 && y == -1)
        {
            puts("undecidable");
        }
        else
        {
            printf("%lld %lld\n", x, y);
        }
    }

    return 0;
}