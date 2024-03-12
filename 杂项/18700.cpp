#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
template <class T> void chkmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
}
template <class T> void chkmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
}
void solve()
{
    int n, k, x;
    cin >> n >> k >> x;
    if (k - 1 > x || n < (k))
    {
        cout << "-1" << endl;
        return;
    }
    i64 ans = 0;
    for (int i = 0; i < k; i++, n--)
        ans += i;
    if (k == x)
    {
        for (int i = x - 1; n; n--)
            ans += i;
        cout << ans << endl;
        return;
    }
    for (int i = x; n; n--)
        ans += i;
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