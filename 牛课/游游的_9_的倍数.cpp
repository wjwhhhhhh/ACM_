#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int M = 1e9 + 7;
const int N = 2e5 + 10;
i64 dp[N][9];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a;
    cin >> a;
    i64 ans = 0;
    vector<int> sum(9);
    sum[0] = 1;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < 9; j++)
        {
            (dp[i][(j * 10 + a[i] - '0') % 9] += sum[j]) %= M;
        }
        (ans += dp[i][0]) %= M;
        for (int j = 0; j < 9; j++)
            (sum[j] += dp[i][j]) %= M;
    }
    cout << ans << endl;
    return 0;
}