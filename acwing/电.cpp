#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
struct Graph // 有向图
{
    std::vector<int> e, ne, h, w;
    int idx = 0;
    int node_size;
    Graph()
    {
    }
    Graph(int n)
    {
        init(n);
    }
    Graph(int n, int m)
    {
        init(n, m);
    }
    void init(int n)
    {
        node_size = n;
        idx = 0;
        e.resize(2 * n), ne.resize(2 * n), w.resize(2 * n);
        h.resize(n, -1);
    }
    void init(int n, int m)
    {
        node_size = n;
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
struct UNdigraph : Graph // 无向图
{
    UNdigraph()
    {
    }
    UNdigraph(int a) : Graph(a)
    {
    }
    UNdigraph(int n, int m) : Graph(n, m)
    {
    }
    void insert(int a, int b)
    {
        add(a, b), add(b, a);
    }
    void insert(int a, int b, int c)
    {
        add(a, b, c), add(b, a, c);
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<int> w(n);
    for (int i = 0; i < n; i++)
        cin >> w[i];
    UNdigraph gra(n);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        gra.insert(a, b);
    }
    vector<int> dp(n);
    function<void(int, int)> dfs = [&](int u, int fa) {
        dp[u] = 1;
        for (int i = gra.h[u]; ~i; i = gra.ne[i])
        {
            int j = gra.e[i];
            if (j == fa)
                continue;
            dfs(j, u);
            if (w[u] > w[j])
                dp[u] += dp[j];
        }
    };
    function<void(int, int)> dfs2 = [&](int u, int fa) {
        for (int i = gra.h[u]; ~i; i = gra.ne[i])
        {
            int j = gra.e[i];
            if (j == fa)
                continue;
            if (w[j] > w[u])
                dp[j] += dp[u];
            dfs2(j, u);
        }
    };
    dfs(0, -1);
    dfs2(0, -1);
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, dp[i]);
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++)
    {
        cout << "Case #" << tt + 1 << ": ";
        solve();
    }
    return 0;
}