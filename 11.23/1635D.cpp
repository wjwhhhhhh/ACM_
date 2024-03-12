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
const int M = 1e9 + 7;
void solve()
{
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    set<int> has;
    vector<int> fac(p + 1);
    fac[0] = fac[1] = 1;
    for (int i = 2; i <= p; i++)
        fac[i] = (fac[i - 1] + fac[i - 2]) % M;
    for (int i = 1; i <= p; i++)
        fac[i] = (fac[i - 1] + fac[i]) % M;
    auto check = [&](int x, int wei) {
        int si = 0;
        for (int j = 0; j < wei; j++)
        {
            if (x >> j & 1)
            {
                if (si & 1)
                    return false;
                si = 0;
            }
            else
                si++;
        }
        if (si & 1)
            return false;
        return true;
    };
    auto get = [&](int x) {
        // cout << x << endl;
        int si = 0;
        while (x)
        {
            si++;
            x >>= 1;
        }
        if (p - si < 0)
            return 0;
        return fac[p - si];
    };
    i64 ans = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        bool fl = true;
        for (int j = 0; j < 30; j++)
        {
            if (has.find(a[i] >> j) != has.end())
            {
                if (check(a[i], j))
                    fl = false;
            }
        }
        if (fl)
        {
            ans += get(a[i]);
            ans %= M;
            has.insert(a[i]);
        }
    }
    cout << ans << endl;
    // cout << (1 << 30) << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}