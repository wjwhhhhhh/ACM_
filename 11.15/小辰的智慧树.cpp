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
    i64 n, m;
    cin >> n >> m;
    vector<i64> a(n), c(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> c[i];
    vector<int> o(n);
    iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](int x, int y) { return a[x] > a[y]; });
    i64 ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (m)
        {
            i64 si = min(a[i] - c[i], m);
            ans += 2 * a[i] * si - si * si;
            m -= si;
        }
    }
    /*19
36
51
64
75*/
    for (int i = 1; i <= 6; i++)
    {
        cout << 2 * i - i * i << endl;
    }
    return 0;
}