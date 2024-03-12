#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 2e5 + 10;
int dp[N][2][1 << 3];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    string len;
    cin >> len;
    len = " " + len;
    i64 ans = 0;
    vector<int> need(1 << 3);
    memset(dp, 0, sizeof dp);
    for (int i = 0; i < 1 << 3; i++)
    {
        int tem = 0;
        int si = i;
        while (si & 1)
        {
            tem++;
            si /= 2;
        }
        need[i] = tem;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < 1 << 3; j++)
        {
            dp[i][0][j] = dp[i - 1][0][j];
            dp[i][1][j] = dp[i - 1][1][j];
        }
        if (len[i] == 'M')
        {
            dp[i][0][1 << w[i]]++;
        }
        else if (len[i] == 'E')
        {
            for (int j = 1; j < 1 << 3; j++)
            {
                dp[i][1][j | (1 << w[i])] += dp[i - 1][0][j];
            }
        }
        else
        {
            for (int j = 1; j < 1 << 3; j++)
            {
                ans += dp[i - 1][1][j] * need[j | (1 << w[i])];
            }
        }
    }
    cout << ans << endl;
    return 0;
}