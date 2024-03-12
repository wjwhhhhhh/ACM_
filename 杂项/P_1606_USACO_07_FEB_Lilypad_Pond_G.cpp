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
int dx[8] = {1, 1, 2, 2, -2, -2, -1, -1}, dy[8] = {2, -2, 1, -1, 1, -1, 2, -2};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    int s, t;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 3)
                s = i * m + j;
            else if (a[i][j] == 4)
                t = i * m + j;
        }
    vector<vector<int>> g(n * m);
    for (int u = 0; u < n * m; u++)
    {
        int x = u / m, y = u % m;
        if (a[x][y] != 0 && a[x][y] != 3)
            continue;
        vector<int> vis(n * m);
        function<void(int)> dfs = [&](int xt) {
            vis[xt] = true;
            for (int i = 0; i < 8; i++)
            {
                int aa = xt / m + dx[i], bb = xt % m + dy[i];
                if (aa < 0 || bb < 0 || aa >= n || bb >= m || vis[aa * m + bb])
                    continue;
                if (a[aa][bb] == 1)
                    dfs(aa * m + bb);
                else if (a[aa][bb] != 2)
                    vis[aa * m + bb] = 1, g[u].push_back(aa * m + bb);
            }
        };
        dfs(u);
    }
    priority_queue<pair<i64, int>> p;
    vector<i64> fr(n * m), dist(n * m, 1e9), vis(n * m);
    dist[s] = 0;
    fr[s] = 1;
    p.push({0, s});
    while (p.size())
    {
        auto u = p.top().second;
        p.pop();
        if (vis[u])
            continue;
        vis[u] = true;
        for (auto x : g[u])
        {
            if (dist[x] == dist[u] + 1)
            {
                fr[x] += fr[u];
            }
            else if (dist[x] > dist[u] + 1)
            {
                fr[x] = fr[u];
                dist[x] = dist[u] + 1;
            }
            p.push({-1 * dist[x], x});
        }
    }
    if (dist[t] == 1e9)
    {
        cout << "-1" << endl;
        return 0;
    }
    cout << dist[t] - 1 << endl;
    cout << fr[t] << endl;
    return 0;
}