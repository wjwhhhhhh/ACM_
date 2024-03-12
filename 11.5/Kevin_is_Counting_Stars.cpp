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
    int n;
    cin >> n;
    vector<i64> a(n);
    fir(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());
    if (a[0] == a.back())
    {
        cout << a[0] * (n - 2) << endl;
    }
    else
    {
        bool fl = false;
        for (int i = 1; i < n - 1; i++)
        {
            if (a[i] != a[0] && a[i] != a[n - 1])
                fl = true;
        }

        if (count(a.begin(), a.end(), a[0]) > 1)
            fl = true;
        cout << accumulate(a.begin() + 1, a.begin() + a.size() - 1, 0ll) + fl << endl;
    }
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