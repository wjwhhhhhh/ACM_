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
    cout << setprecision(6) << fixed;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        int r = (i + 1) % n;
        double tem = 0;
        for (int j = 1; j <= a[r]; j++)
        {
            if (j > a[i])
                continue;
            tem += 1.0 / a[i];
        }
        tem /= a[r];
        ans += tem;
    }
    cout << ans << endl;
    return 0;
}