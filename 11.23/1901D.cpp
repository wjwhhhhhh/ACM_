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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    fir(i, 1, n + 1) cin >> a[i];
    vector<int> l(n + 1), r(n + 1);
    int tem = 0;
    for (int i = 1; i <= n; i++)
    {
        int ans = max(a[i], tem + (n - i + 1));
        tem++;
        l[i] = ans;
        tem = max(a[i], tem);
    }
    tem = 0;
    for (int i = n; i > 0; i--)
    {
        int ans = max(a[i], tem + i);
        tem++;
        r[i] = ans;
        tem = max(a[i], tem);
    }
    int ans = 2e9;
    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, max(l[i], r[i]));
    }
    cout << ans << endl;
    return 0;
}