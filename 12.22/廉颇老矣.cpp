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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(3) << fixed;
    int n;
    cin >> n;
    double ansx = 0, ansy = 0;
    while (n--)
    {
        int x, y, f;
        cin >> x >> y >> f;
        double len = sqrt((x * x) + (y * y));
        if (len == 0)
            continue;
        double pei = f / len;
        x *= pei, y *= pei;
        ansx += x, ansy += y;
    }
    cout << ansx << " " << ansy << endl;
    return 0;
}