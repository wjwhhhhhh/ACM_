#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    int n;
    cin >> n;
    std::vector<int> v(n + 2);
    for (int i = 1; i <= n; i++)cin >> v[i];
    v[n + 1] = n + 1;
    vector<vector<int> > dp(n + 2, vector<int> (n + 1, n));
    for (int i = 0; i <= n; i++)dp[0][i] = 0;
    for (int i = 1; i <= n+1; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[j] < v[i])
            {
                if (j + 1 == i)
                {
                    for (int k = 0; k <= n; k++)
                    {
                        dp[i][k] = min(dp[i][k], dp[j][k]);
                    }
                }
                else
                {
                    for (int k = 0; k < n; k++)
                    {
                        dp[i][k + 1] = min(dp[i][k + 1], dp[j][k] + i - j - 1);
                    }
                }
            }
        }
        for (int j = 1; j <= n; j += 1)
        {
            dp[i][j] = min(dp[i][j], dp[i][j - 1]);
        }
    }
    for (int i = 1; i <= n; i += 1)
    {
        cout << dp[n + 1][i] << " ";
    }
    cout << "\n";

}
int main()
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