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
    while (t--)
    {
        i64 p, m;
        cin >> p >> m;
        i64 ans = m / p;
        for (int i = m / p; i < (m + p - 1) / p; i++)
        {
            if ((i * p + 1) ^ (p - 1) <= m)
                ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}