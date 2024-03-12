#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1e4 + 10;
int dp[2][N][3]; // 1有最大
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> l(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> l[i];
    memset(dp, -0x3f, sizeof dp);
    int inf = dp[1][0][0];
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        memset(dp[i % 2], -0x3f, sizeof dp[i % 2]);
        for (int j = 0; j < i; j++)
        {
            if (dp[(i + 1) % 2][j][0] >= inf)
            {
                dp[i % 2][j][0] = max(dp[i % 2][j][0], dp[(i + 1) % 2][j][0]);
                dp[i % 2][j + 1][0] = max(dp[i % 2][j + 1][0], dp[(i + 1) % 2][j][0]);
                dp[i % 2][j + 1][1] = max(dp[i % 2][j + 1][1], dp[(i + 1) % 2][j][0] + l[i]);
                dp[i % 2][j + 1][2] = max(dp[i % 2][j + 1][2], dp[(i + 1) % 2][j][0] - l[i]);
            }
            if (dp[(i + 1) % 2][j][1] >= inf)
            {
                dp[i % 2][j][1] = max(dp[i % 2][j][1], dp[(i + 1) % 2][j][1]);
                dp[i % 2][j][0] = max(dp[i % 2][j][0], dp[(i + 1) % 2][j][1] - l[i]);
            }
            if (dp[(i + 1) % 2][j][2] >= inf)
            {
                dp[i % 2][j][0] = max(dp[i % 2][j][0], dp[(i + 1) % 2][j][2] + l[i]);
                dp[i % 2][j][2] = max(dp[i % 2][j][2], dp[(i + 1) % 2][j][2]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << dp[n % 2][i][0] << endl;
    return 0;
}