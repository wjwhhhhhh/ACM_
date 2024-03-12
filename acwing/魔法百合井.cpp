#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
vector<i64> divisor(i64 n)
{
    vector<i64> p;
    for (i64 i = 1; i <= n / i; i++)
    {
        if (n % i == 0)
        {
            p.push_back(i), p.push_back(n / i);
        }
    }
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    return p;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1] + 1;
        auto p = divisor(i);
        for (int j : p)
        {
            dp[i] = min(dp[i], dp[j] + 4 + i / j * 2 - 2);
        }
    }
    cout << dp[n] << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}