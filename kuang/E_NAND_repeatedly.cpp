#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin >> n;
    string a;
    cin >> a;
    a = " " + a;
    vector<array<int, 2>> dp(n + 1);
    i64 ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int t = a[i] - '0';
        if (t == 0)
        {
            dp[i][1] += dp[i - 1][0] + dp[i - 1][1];
            dp[i][0] = 1;
            ans += dp[i][1];
        }
        else
        {
            dp[i][1] = dp[i - 1][0] + 1;
            dp[i][0] = dp[i - 1][1];
            ans += dp[i][1];
        }
    }
    cout << ans << endl;
    return 0;
}