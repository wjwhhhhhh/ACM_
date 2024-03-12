#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    int n, d, h;
    cin >> n >> d >> h;
    double ans = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        auto last = upper_bound(a.begin(), a.end(), a[i]);
        if (last == a.end() || (*last) - a[i] >= h)
        {
            ans += 0.5 * d * h;
        }
        else
        {
            ans += 0.5 * d * h * (1.0 - (h - (1.0 * (*last) - a[i])) / h * (h - (1.0 * (*last) - a[i])) / h);
        }
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cout << fixed;
    cout.precision(12);
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}