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
    int n, k;
    cin >> n >> k;
    int ans = 0;
    int last = 1;
    for (int i = k; i <= n; i += k)
    {
        cout << "? " << i - (k - 1) << endl;
        int a;
        last = i - (k - 1);
        cin >> a;
        ans ^= a;
    }
    if (n % k == 0)
    {
        cout << "! " << ans << endl;
    }
    else
    {
        int si = n % k;
        int kai = last;
        cout << "? " << kai + si / 2 << endl;
        int a;
        cin >> a;
        ans ^= a;
        cout << "? " << kai + si << endl;
        cin >> a;
        ans ^= a;
        cout << "! " << ans << endl;
    }
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