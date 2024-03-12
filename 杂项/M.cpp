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
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), w(m);
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        g[t].push_back(i);
    }
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        w[t] = 1;
    }
    function<void(int)> dfs = [&](int u) {
        for (auto x : g[u])
        {
            dfs(x);
            w[u] += w[x];
        }
        return;
    };
    dfs(0);
    string ans(n, '0');
    function<void(int)> dfs2 = [&](int u) {
        sort(g[u].begin(), g[u].end(), [&](int x, int y) { return w[x] > w[y]; });
        for (int i = 0; i < g[u].size(); i++)
            ans[g[u][i] - 1] = ('a' + i);
        for (auto x : g[u])
        {
            dfs2(x);
        }
        return;
    };
    dfs2(0);
    cout << ans << endl;
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