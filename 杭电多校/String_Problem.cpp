#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    string a;
    cin >> a;
    int ans = 0;
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] == a[i - 1])
            ans++;
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