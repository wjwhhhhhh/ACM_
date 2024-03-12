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
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    i64 ans = 1e18;
    for (int i = 0; i <= min(n, m); i++)
    {
        i64 ing = 0;
        for (int j = 0; j < i; j++)
        {
            ing += a[j] * b[j];
        }
        i64 tem = 2 * i, sh = max(0ll, x - ing);
        for (int j = i; j < m && sh; j++)
        {
            sh = max(0ll, sh - b[j]);
            tem++;
        }
        if (sh == 0)
            chmin(ans, tem);
    }
    cout << ans << endl;
    return 0;
}