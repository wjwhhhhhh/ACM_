#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void solve()
{
    int n, m;
    cin >> m >> n;

    int p[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> p[i];

    int r[m + 1][n + 1];
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> r[i][j];
    bitset<5001> adj[n + 1] = {};
    for (int i = 1; i <= n; i++)
        adj[i].set();
    for (int i = 1; i <= m; i++)
    {
        bitset<5001> b[n + 2] = {};
        for (int j = 1; j <= n; j++)
        {
            b[r[i][j]].set(j);
        }
        for (int j = n - 1; j >= 1; j--)
        {
            b[j] |= b[j + 1];
        }
        for (int j = 1; j <= n; j++)
        {
            adj[j] &= b[r[i][j] + 1];
        }
    }

    vector<long long> dp(n + 1, 0);
    vector<bool>st(n+3,0);
    function<long long(int)> dfs = [&](int now) {
        if (st[now])
            return dp[now];
        dp[now] = p[now];
        for (int i = 1; i <= n; i++)
        {
            if (adj[now][i])
            {
                dp[now] = max(dp[now], dfs(i) + p[now]);
            }
        }
        st[now]=true;
        return dp[now];
    };
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, dfs(i));
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}