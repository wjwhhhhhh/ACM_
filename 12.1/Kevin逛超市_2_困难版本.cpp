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
    int n, x, y, a, b;
    cin >> n >> a >> b >> x >> y;
    vector<double> w(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    sort(w.begin() + 1, w.end(), [&](double x, double y) { return x > y; });
    vector<double> sy(2 * n + 1), s(2 * n + 1);
    for (int i = 1; i <= n; i++)
    {
        sy[i] = sy[i - 1] + max(0.0, w[i] - y);
        s[i] = s[i - 1] + w[i];
    }
    for (int i = n + 1; i <= 2 * n; i++)
        sy[i] = sy[i - 1], s[i] = s[i - 1];
    double ans = 1e18;
    for (int i = 0; i <= a && i <= n; i++)
    {
        int r = min(n, i + b);
        double tem = s[i] + s[a - i + r] - s[r];
        // cout << s[a - i + r] << " " << r << endl;
        chmin(ans, tem * x / 100 + sy[r] - sy[i]);
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}