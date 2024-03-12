#include <bits/stdc++.h>
#define int long long
using namespace std;
using i64 = long long;
i64 dp[5100][5100];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, t;
    cin >> n >> t;
    vector<i64> x(n + 1);
    vector<vector<int>> c(n + 1);
    int sum = 0;
    vector<int> from, heg;
    from.push_back(0);
    heg.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        int len;
        cin >> x[i] >> len;
        sum += len;
        for (int j = 0; j < len; j++)
        {
            int a;
            cin >> a;
            c[i].push_back(a);
        }
    }
    vector<int> o(n + 1);
    iota(o.begin() + 1, o.end(), 1);
    sort(o.begin() + 1, o.end(), [&](int a, int b) { return x[a] < x[b]; });
    for (int i = 1; i <= n; i++)
    {
        int j = o[i];
        for (auto x : c[j])
        {
            from.push_back(j);
            heg.push_back(x);
        }
    }
    memset(dp, 0x3f, sizeof dp);
    int ans = 0;
    dp[0][0] = 0;
    for (int i = 1; i <= sum; i++)
    {
        i64 res = dp[i - 1][0] - x[from[0]];
        for (int j = 1; j <= sum; j++)
        {
            dp[i][j] = min(dp[i][j], x[from[j]] + heg[j] + res);
            if (dp[i][j] <= t)
                ans = max(ans, i);
            res = min(res, dp[i - 1][j] - x[from[j]]);
        }
    }
    cout << ans << endl;
    return 0;
}