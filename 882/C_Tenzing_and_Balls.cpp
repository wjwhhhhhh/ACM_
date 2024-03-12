#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> st[n];
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int tem;
        cin >> tem;
        tem--;
        dp[i] = dp[i - 1] + 1;
        if (st[tem].size() != 0)
            dp[i] = min(dp[i], st[tem].top());
        st[tem].push(dp[i - 1]);
    }
    cout << n - dp[n] << '\n';
}
signed main()
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