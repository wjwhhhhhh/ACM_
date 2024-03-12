#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
#define fir(a, b, c) for (int a = b; a < c; a++)
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    a[0] = 1;
    fir(i, 1, n) cin >> a[i];
    fir(i, 0, n) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int l = 0, r = n;
    auto check = [&](int len) {
        fir(i, 0, n - len)
        {
            if (a[i] >= b[len + i])
                return false;
        }
        return true;
    };
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
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