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
    vector<int> a(n + 1), b(n + 1);
    fir(i, 1, n + 1) cin >> a[i];
    fir(i, 1, n + 1) cin >> b[i];
    vector<i64> s(n + 1), val(n + 1);
    for (int i = 1; i <= n; i++)
    {
        val[i] = abs(a[i] - b[i]);
        s[i] = s[i - 1] + abs(a[i] - b[i]);
    }
    array<i64, 4> cnt;
    fill(cnt.begin(), cnt.end(), -1e18);
    i64 sum = s[n];
    for (int i = 1; i <= n; i++)
    {
        array<i64, 4> ing = {a[i] + b[i], a[i] - b[i], -a[i] + b[i], -a[i] - b[i]};
        chmax(sum, ing[0] + cnt[3] + s[i - 1] + s[n] - s[i]);
        chmax(sum, ing[1] + cnt[2] + s[i - 1] + s[n] - s[i]);
        chmax(sum, ing[2] + cnt[1] + s[i - 1] + s[n] - s[i]);
        chmax(sum, ing[3] + cnt[0] + s[i - 1] + s[n] - s[i]);
        for (int j = 0; j < 4; j++)
            chmax(cnt[j], ing[j] + s[i - 1] - s[i]);
    }
    cout << sum << endl;
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