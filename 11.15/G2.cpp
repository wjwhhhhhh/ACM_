#include <bits/stdc++.h>
using namespace std;
const int maxn = 1003;
string s;
int n, p, dp[maxn][maxn];
int main()
{
    cin >> s >> p;
    n = s.size();
    s = " " + s;
    for (int i = 1; i <= n; ++i)
        dp[i][i] = 1;
    for (int len = 2; len <= n; ++len)
    {
        for (int i = 1; i <= n + len - 1; ++i)
        {
            int j = i + len - 1;
            dp[i][j] = 1 + dp[i + 1][j];
            if (s[i] != 'o')
                continue;
            for (int k = i + 1; k <= j; ++k)
                if (s[k] == 'f' && dp[i + 1][k - 1] == 0)
                    dp[i][j] = min(dp[i][j], max(dp[k + 1][j] - p, 0));
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}