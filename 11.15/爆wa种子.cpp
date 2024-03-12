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
    cout << setprecision(15) << fixed;
    int t;
    cin >> t;
    double ans = 1e9;
    vector<array<int, 3>> a(t);
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < 3; j++)
            cin >> a[i][j];
        if (a[i][0] <= 0)
            ans = -1000000000;
        else
        {
            double tr = -a[i][1] / (2.0 * a[i][0]);
            chmin(ans, a[i][0] * tr * tr + a[i][i] * tr + a[i][2]);
        }
    }
    cout << ans << endl;
    return 0;
}