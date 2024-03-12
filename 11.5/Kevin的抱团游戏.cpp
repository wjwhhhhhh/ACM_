#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
#define fir(a, b, c) for (int a = b; a < c; a++)
using namespace std;
using i64 = long long;
using two = array<int, 2>;
template <class T> bool chmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
    return a == b;
}
template <class T> bool chmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
    return a == b;
}
void solve()
{
    i64 n, m, k;
    cin >> n >> m >> k;
    i64 ans = 0;
    if (k == 1)
    {
        cout << m << endl;
        return;
    }
    i64 si = 0;
    if (k & 1)
    {
        si = min(n, (n + 2 * m) / k);
    }
    else
        si = (n + 2 * m) / k;
    si = (n + 2 * m) - si * k;
    i64 th = min(si / 2, m);
    ans += th;
    si = max(si - 2 * th, 0ll);
    ans += si;
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