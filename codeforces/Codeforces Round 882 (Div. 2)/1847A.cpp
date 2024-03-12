#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int dp[110][110];
void solve()
{
    int n, k;
    cin >> n >> k;
    memset(dp, 0x3f, sizeof dp);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dp[0][0] = 0;
    for (int i = 1; i <= k; i++)
        for (int j = i; j <= n; j++)
        {
            int res = 0;
            for (int z = j; z >= 1; z--)
            {
                dp[i][j] = min(dp[i][j], dp[i - 1][z - 1] + res);
                res += abs(a[z] - a[z - 1]);
            }
        }
    cout << dp[k][n] << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}