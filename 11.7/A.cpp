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
    vector<int> a(4);
    fir(i, 0, 4) cin >> a[i];
    vector<int> o(4);
    iota(o.begin(), o.end(), 0);
    i64 ans = 0;
    do
    {
        int l = min(a[o[0]], a[o[2]]);
        int r = min(a[o[1]], a[o[3]]);
        chmax(ans, 1ll * l * r);
    } while (next_permutation(o.begin(), o.end()));
    cout << ans << endl;
    return 0;
}
