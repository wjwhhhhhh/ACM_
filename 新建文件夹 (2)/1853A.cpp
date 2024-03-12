#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans = 1e9;
    for (int i = 1; i < n; i++)
    {
        ans = min(ans, (a[i] - a[i - 1]) / 2 + 1);
        if (a[i] < a[i - 1])
            ans = 0;
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}