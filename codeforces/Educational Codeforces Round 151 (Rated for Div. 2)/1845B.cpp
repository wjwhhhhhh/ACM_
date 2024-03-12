#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    int a1, b1, a2, b2, a3, b3;
    cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
    int ans = 0;
    bool fl = false;
    if (a2 > a3)
        swap(a2, a3);
    if (a1 < a2)
        ans += (a2 - a1), fl = true;
    if (a1 > a3)
        ans += (a1 - a3), fl = true;
    if (b2 > b3)
        swap(b2, b3);
    if (b1 < b2)
        ans += (b2 - b1), fl = true;
    if (b1 > b3)
        ans += (b1 - b3);
    cout << ans + 1 << endl;
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