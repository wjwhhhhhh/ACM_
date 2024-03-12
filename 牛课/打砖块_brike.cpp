#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 55;
int dp[N][N][N];
int w[N][N];
int sum[N][N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = n; j >= i; j--)
            cin >> w[j][i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            sum[i][j] = w[i][j] + sum[i][j - 1];
    memset(dp, -0x3f, sizeof dp);
    for (int i = 0; i <= n; i++)
        dp[0][i][0] = 0;
    int ans = -0x3f3f3f3f;
    for (int k = 1; k <= m; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= min(i, k); j++)
            {
                for (int z = j - 1; z <= min(i - 1, k - j); z++)
                {
                    dp[k][i][j] = max(dp[k][i][j], dp[k - j][i - 1][z] + sum[i][j]);
                    ans = max(ans, dp[k][i][j]);
                }
            }
        }
    }
    cout << ans << endl;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= i; j++)
    //         cout << w[i][j] << " ";
    //     cout << endl;
    // }
    return 0;
}