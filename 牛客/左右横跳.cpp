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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> s(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> s[i][j];
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int j = 1; j <= m; j++)
        dp[1][j] = s[1][j];
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            chkmax(dp[i][j], dp[i - 1][j]);
        if (i >= (k + 1))
        {
            int res = 0;
            for (int j = 1; j <= m; j++)
                chkmax(res, dp[i - k][j]);
            for (int j = 1; j <= m; j++)
                chkmax(dp[i][j], res + s[i][j]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++)
        chkmax(ans, dp[n][i]);
    cout << ans << endl;
    return 0;
}