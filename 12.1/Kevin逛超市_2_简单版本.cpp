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
    int n, x, y;
    cin >> n >> x >> y;
    vector<double> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a.begin() + 1, a.end(), [&](int x, int y) { return x > y; });
    if (n == 1)
    {
        cout << min(max(0.0, a[1] - y), a[1] * x / 100);
        return;
    }
    double ans = 0;
    // cout << a[3] << endl;
    for (int i = 3; i <= n; i++)
        ans += a[i];
    auto get = [&](double val) { return max(0.0, val - y); };
    cout << ans + min(get(a[1]) + a[2] * x / 100, get(a[2]) + a[1] * x / 100) << endl;
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