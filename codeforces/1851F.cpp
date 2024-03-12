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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> o(n);
    iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](int x, int y) { return a[x] < a[y]; });
    int ans = 2e9, x, y;
    for (int i = 1; i < n; i++)
    {
        if (ans > (a[o[i]] ^ a[o[i - 1]]))
        {
            ans = a[o[i]] ^ a[o[i - 1]];
            x = o[i - 1], y = o[i];
        }
    }
    int res = 0;
    for (int i = k - 1; i >= 0; i--)
    {
        if (!(a[y] >> i & 1))
        {
            res += 1 << i;
        }
    }
    if (x > y)
        swap(x, y);
    cout << x + 1 << " " << y + 1 << " " << res << endl;
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