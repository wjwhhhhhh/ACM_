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
// 1820;
void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    double ans = 1;
    double pa = 1.0 * a / 16, pb = 1.0 * b / 16, pc = 1.0 * c / 16;
    for (int i = 0; i < 12; i++)
        ans *= pa;
    ans *= (pow(pa, 4) + 1820 * pow(pb, 4) + 1820 * pow(pc, 4));
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