#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n, q, k;
    cin >> n >> q >> k;
    vector<i64> dp(n + 1);
    vector<int> a(n + 1), h(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    vector<i64> s(n + 1);
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    vector<int> f(n + 1);
    f[0] = 0;
    h[0] = -1;
    for (int i = 1; i <= n; i++)
    {
        if (h[i] != h[i - 1])
            f[i] = i - 1;
        else
            f[i] = f[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        if (i - f[i] >= k)
        {
            dp[i] = s[i] - s[i - k];
        }
        else
        {
            dp[i] = s[i] - s[f[i]] + dp[f[i]];
        }
    }
    while (q--)
    {
        int x;
        cin >> x;
        cout << dp[x] << '\n';
    }
    return 0;
}