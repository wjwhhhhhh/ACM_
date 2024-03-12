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
void solve()
{
    int n, m;
    cin >> n >> m;
    Graph gra(n, m);
    vector<pair<int, int>> cnt;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        cnt.push_back({a, b});
        gra.add(a, b);
    }
    vector<int> dist(n), vis(n);
    queue<int> q;
    q.push(0);
    while (q.size())
    {
        auto u = q.front();
        q.pop();
        vis[u] = true;
        for (int i = gra.h[u]; ~i; i = gra.ne[i])
        {
            int j = gra.e[i];
            if (vis[j])
                continue;
            dist[j] = dist[u] + 1;
            q.push(j);
        }
    }
    for (auto [x, y] : cnt)
    {
        if (dist[x] > dist[y])
            continue;
        if (dist[x] + 1 != dist[y])
        {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}