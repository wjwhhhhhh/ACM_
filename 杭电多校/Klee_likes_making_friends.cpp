// #pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 50010, M = 2020;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (n < m)
    {
        cout << "0" << '\n';
        return;
    }
    vector<vector<int>> dp(m, vector<int>(m, 1e9));
    dp[0][m - 1] = 0;
    int res = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++)
    {
        for (int j = m - 2; j >= 0; j--)
            dp[(i - 1) % m][j] = min(dp[(i - 1) % m][j + 1], dp[(i - 1) % m][j]);
        fill(dp[i % m].begin(), dp[i % m].end(), 1e9);
        for (int j = i - 1; j > i - m && j >= 0; j--)
        {
            dp[i % m][j + m - i] = min(dp[i % m][j + m - i], dp[j % m][i - j] + a[i]);
            if (j + m > n)
                res = min(dp[i % m][j + m - i], res);
        }
    }
    cout << res << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}