#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string a;
    cin >> a;
    vector<array<int, 2>> dp(n + 1);
    for (int i = 2; i <= n; i += 2)
    {
        if (a[i - 1] == a[i - 2])
        {
            dp[i / 2][0] = dp[i / 2 - 1][0], dp[i / 2][1] = dp[i / 2 - 1][1];
        }
        else if (a[i - 1] == 'G')
        {
            dp[i / 2][0] = min(dp[i / 2 - 1][0], dp[i / 2 - 1][1] + 1),
                   dp[i / 2][1] = min(dp[i / 2 - 1][1] + 2, dp[i / 2 - 1][0] + 1);
        }
        else
            dp[i / 2][0] = min(dp[i / 2 - 1][0] + 2, dp[i / 2 - 1][1] + 1),
                   dp[i / 2][1] = min(dp[i / 2 - 1][1], dp[i / 2 - 1][0] + 1);
    }
    cout << dp[n / 2][0] << endl;
    return 0;
}