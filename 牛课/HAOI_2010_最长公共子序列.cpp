#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int M = 1e8;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    a.pop_back(), b.pop_back();
    vector dp(a.size() + 1, vector<int>(b.size() + 1, -0x3f3f3f3f));
    vector f(a.size() + 1, vector<int>(b.size() + 1, 0));
    dp[0][0] = 0, f[0][0] = 1;
    int n = a.size(), m = b.size();
    a = " " + a, b = " " + b;
    vector<pair<int, int>> w(m+1, make_pair(0, 1)), alone(m+1, make_pair(0, 0));
    alone[0] = {0, 1};
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i] == b[j])
            {
                dp[i][j] = w[j - 1].first + 1, f[i][j] = w[j - 1].second;
                if (dp[i][j] == alone[j].first)
                {
                    (alone[j].second += f[i][j])%=M;
                }
                else
                    alone[j] = {dp[i][j], f[i][j]};
                res = max(res, dp[i][j]);
            }
        }
        int ans = 0, sum = 1;
        for (int j = 1; j <= m; j++)
        {
            if (alone[j].first == ans)
            {
                (sum += alone[j].second)%=M;
            }
            else if (alone[j].first > ans)
            {
                ans = alone[j].first, sum = alone[j].second;
            }
            w[j] = {ans, sum};
        }
    }
    int cnt = 0;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
        {
            if (dp[i][j] == res)
                (cnt += f[i][j]) %= M;
        }
    cout << res << '\n' << cnt << endl;
    return 0;
}