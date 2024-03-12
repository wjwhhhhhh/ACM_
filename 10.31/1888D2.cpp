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
    vector<int> aa(n), a(n), bb(n), b(n);
    fir(i, 1, n) cin >> aa[i];
    fir(i, 0, n) cin >> bb[i];
    int l = 0, r = n;
    auto check = [&](int len) {
        fir(i, 0, n - len)
        {
            if (a[i] >= b[len + i])
                return false;
        }
        return true;
    };
    map<int, int> mp;
    auto solve = [&](int x) {
        if (mp.find(x) != mp.end())
            return mp[x];
        int l = 0, r = n;
        a = aa, b = bb;
        a[0] = x;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        while (l < r)
        {
            int mid = l + r >> 1;
            if (check(mid))
                r = mid;
            else
                l = mid + 1;
        }
        return mp[x] = l;
    };
    int ing = 1;
    i64 ans = 0;
    while (ing <= m)
    {
        int l = ing, r = m;
        int ch = solve(ing);
        // cout << ch << "ok" << endl;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (ch == solve(mid))
                l = mid;
            else
                r = mid - 1;
        }
        ans += 1ll * (l - ing + 1) * ch;
        ing = l + 1;
    }
    cout << ans << endl;
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