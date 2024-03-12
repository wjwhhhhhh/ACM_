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
    int x, y;
    cin >> x >> y;
    if (y < x)
        swap(x, y);
    if (x == 1)
        cout << "1" << endl;
    else if (x == 2)
        cout << (y + 1) / 2 << endl;
    else if (x == 3)
    {
        if (y == 3)
            cout << "8" << endl;
    }
    else
        cout << 1ll * x * y << endl;
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