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
    int n, L, k;
    cin >> n >> L >> k;
    vector<i64> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    i64 ans = 0;
    for (int i = 0; i < n; i++)
    {
        int l = (i - 1 + n) % n, r = (i + k) % n;
        chmax(ans, (a[r] - a[l] + L) % L);
    }
    cout << ans << endl;
    return 0;
}