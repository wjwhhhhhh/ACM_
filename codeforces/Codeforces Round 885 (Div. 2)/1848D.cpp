#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    i64 ans;
    i64 s, k;
    cin >> s >> k;
    ans = s * k;
    if (s % 2 && k)
    {
        s += s % 10;
        k--;
        ans = max(ans, s * k);
    }
    if (s % 10 == 0)
    {
        ans = max(ans, s * k);
        cout << ans << endl;
        return;
    }
    for (int i = 0; i < 4 && k; i++)
    {
        auto f = [&](i64 x, i64 y, i64 k) { return (x + 20 * k) * (y - 4 * k); };
        auto get = [&](i64 x, i64 y) {
            int l = 0, r = y / 4;
            while (l < r)
            {
                int mid = l + r >> 1;
                if (f(x, y, mid) < f(x, y, mid + 1))
                    l = mid + 1;
                else
                    r = mid;
            }
            // cout << x << y << endl;
            return f(x, y, l);
        };
        auto tem = get(s, k);
        // cout << s << k << endl;
        ans = max(ans, tem);
        s += s % 10;
        k--;
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