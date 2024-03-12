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
    int n, k;
    cin >> n >> k;
    vector<vector<vector<i64>>> dp(2, vector<vector<i64>>(2 * n, vector<i64>(2 * n)));
    vector<vector<i64>> s(n + 1, vector<i64>(2 * n));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            cin >> s[i][j + n - i];
        }
    }
    for (int j = 1; j < 2 * n; j++)
        fill(dp[1][j].begin(), dp[1][j].end(), -1e16);
    dp[1][n][n - 1] = s[1][n];
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < 2 * n; j++)
            fill(dp[(i + 1) % 2][j].begin(), dp[(i + 1) % 2][j].end(), -1e16);
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            int ing = j + n - i;
            for (int z = 0; z < 2 * n; z++)
                chkmax(dp[(i + 1) % 2][ing][z], dp[i % 2][ing][z] + s[i + 1][ing]);
            for (int z = 0; z < 2 * n - 1; z++)
                chkmax(dp[(i + 1) % 2][ing - 1][z + 1], dp[i % 2][ing][z] + s[i + 1][ing - 1]);
            for (int z = 1; z < 2 * n; z++)
                chkmax(dp[(i + 1) % 2][ing + 1][z - 1], dp[i % 2][ing][z] + s[i + 1][ing + 1]);
        }
    }
    i64 ans = -1e16;
    for (int i = 1; i < 2 * n; i++)
        for (int z = n - 1 - k; z <= n - 1 + k; z++)
            chkmax(ans, dp[n % 2][i][z]);
    cout << ans << endl;
    return 0;
}