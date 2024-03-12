#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n, m;
    cin >> n >> m;
    Graph gra(n, m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        gra.add(a, b);
    }
    vector<int> v(n);
    vector<array<int, 2>> f(n);
    function<void(int)> dfs = [&](int u) {
        if (v[u])
            return;
        v[u] = true;
        for (int i = gra.h[u]; ~i; i = gra.ne[i])
        {
            int j = gra.e[i];
            dfs(j);
            f[u][0]++;
            f[u][1] += f[j][0];
        }
    };
    for (int i = 0; i < n; i++)
    {
        if (!v[i])
            dfs(i);
        cout << f[i][1] << " ";
    }
    return 0;
}