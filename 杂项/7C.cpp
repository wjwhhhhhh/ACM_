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
i64 exgcd(i64 a, i64 b, i64 &x, i64 &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }
    i64 d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    i64 a, b, c;
    cin >> a >> b >> c;
    if (c % __gcd(a, b) != 0)
    {
        cout << "-1" << endl;
        return 0;
    }
    i64 x, y;
    exgcd(a, b, x, y);
    x = x * (c / __gcd(a, b));
    y = y * (c / __gcd(a, b));
    cout << -1 * x << " " << -1 * y << endl;
    return 0;
}