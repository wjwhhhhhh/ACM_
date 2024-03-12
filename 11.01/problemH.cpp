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
    int t;
    cin >> t;
    while (t--)
    {
        i64 a, b;
        cin >> a >> b;
        a *= 2;
        i64 x, y;
        i64 d = exgcd(a, 360 * b, x, y);
        x *= 360 / d;
        b = abs(b / d);
        if (b)
            (x % b + b) % b;
        cout << x - 1 << '\n';
    }

    return 0;
}