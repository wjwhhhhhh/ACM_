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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    vector<int> o(n);
    iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(),
         [&](int x, int y) { return a[x] + max(b[x], a[y]) + b[y] < a[y] + max(b[y], a[x]) + b[x]; });
    i64 ans = a[o[0]], xu = b[o[0]];
    for (int i = 1; i < n; i++)
    {
        ans += a[o[i]];
        if (xu <= a[o[i]])
            xu = 0;
        else
            xu -= a[o[i]];
        xu += b[o[i]];
    }
    ans += xu;
    cout << ans << endl;
    for (int i = 0; i < n; i++)
        cout << o[i] + 1 << " ";
    return 0;
}
m