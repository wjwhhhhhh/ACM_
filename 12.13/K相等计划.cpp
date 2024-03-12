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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    vector<i64> s(n + 1);
    for (int i = 1; i <= n; i++)
        s[i] = a[i - 1] + s[i - 1];
    i64 ans = 1e18;
    for (int i = k; i <= n; i++)
    {
        chmin(ans, 1ll * a[i - 1] * k - (s[i] - s[i - k]));
    }
    cout << ans << endl;
    return 0;
}