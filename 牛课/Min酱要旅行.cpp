#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 10;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    while (cin >> n >> m)
    {
        vector<int> dp(m + 1);
        vector ans(n, vector<int>(m + 1));
        vector<int> w(n);
        for (int i = 0; i < n; i++)
            cin >> w[i];
        dp[0] = 1;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = m; j >= w[i]; j--)
                dp[j] = (dp[j] + dp[j - w[i]]) % N;
        }
        for (int i = 1; i <= m; i++)
            ans[n - 1][i] = dp[i];
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = w[i]; j <= m; j++)
                dp[j] = (dp[j] + N - dp[j - w[i]]) % N;
            // cout << w[i] << endl;
            for (int j = m; j >= w[i + 1]; j--)
                dp[j] = (dp[j] + dp[j - w[i + 1]]) % N;
            for (int j = 1; j <= m; j++)
                ans[i][j] = dp[j];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j <= m; j++)
                cout << ans[i][j];
            cout << '\n';
        }
    }
    return 0;
}