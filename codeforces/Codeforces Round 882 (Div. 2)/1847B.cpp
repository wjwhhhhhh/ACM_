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
    int res = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (res == 0)
            res = a[i];
        else
            res &= a[i];
        if (res == 0)
            ans++;
    }
    ans = max(ans, 1);
    cout << ans << endl;
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