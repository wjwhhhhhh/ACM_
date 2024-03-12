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
    int M1, M2, L, m;
    cin >> M1 >> M2 >> L >> m;
    // double l = 0, r = 1e9;
    double l = 0, r = L;
    while (r - l >= 1e-6)
    {
        double mid = (l + r) / 2;
        double ans = M2 / (L - mid) / (L - mid) - M1 / mid / mid;
        if (ans < 0)
            l = mid;
        else
            r = mid;
    }
    cout << l << endl;
    return 0;
}