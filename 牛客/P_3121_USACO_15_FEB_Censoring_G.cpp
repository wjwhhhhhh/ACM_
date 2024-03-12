#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 dp[510][510];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<i64> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    k = n - 2 - k;
    if (k == 0)
    {
        cout << (a[n - 1] - a[0]) * (a[n - 1] - a[0]) << endl;
        return 0;
    }
    else
    {
        for (int i = 1; i < n; i++)
            dp[1][i] = (a[i] - a[0]) * (a[i] - a[0]);
        for (int z = 2; z <= k; z++)
        {

            for (int i = z; i < n; i++)
            {
                for (int j = z - 1; j < i; j++)
                {
                    dp[z][i] = max(dp[z][i], dp[z - 1][j] + (a[i] - a[j]) * (a[i] - a[j]));
                }
            }
        }
        i64 ans = 0;
        for (int i = k; i < n - 1; i++)
            ans = max(ans, dp[k][i] + (a[n - 1] - a[i]) * (a[n - 1] - a[i]));
        cout << ans << endl;
    }
    return 0;
}