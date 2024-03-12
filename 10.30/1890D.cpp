#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
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
    int n, c;
    cin >> n >> c;
    vector<i64> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> o(n - 1);
    iota(o.begin(), o.end(), 1);
    sort(o.begin(), o.end(), [&](int x, int y) { return 1ll * (x + 1) * c - a[x] < 1ll * (y + 1) * c - a[y]; });
    i64 sum = a[0];
    for (int i = 0; i < n - 1; i++)
    {
        if (sum + a[o[i]] < 1ll * (o[i] + 1) * c)
        {
            cout << "No" << endl;
            return;
        }
        sum += a[o[i]];
    }
    cout << "Yes" << endl;
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