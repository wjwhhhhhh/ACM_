#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    i64 n, k, m, a, b;
    cin >> n >> k >> m >> a >> b;
    // n = 1e18, m = 1e9 - 1, a = 1e9, b = 1e9, k = 10;
    if (k == 1)
    {
        if (n % m == 0)
        {
            cout << "0" << '\n';
        }
        else
            cout << "-1" << '\n';
        return;
    }
    i64 ans;
    i64 tem = n;
    i64 si = 0;
    while (tem)
    {
        tem /= k;
        si++;
    }
    ans = si * b;
    auto check = [&](i64 n) {
        i64 si = 0;
        array<i64, 2> x, y;
        x[0] = n / m, x[1] = n % m;
        y[0] = n / m, y[1] = n % m;
        while (x[1] && y[1] && x[0] == y[0])
        {

            si++;
            x[0] = x[0] * k + x[1] * k / m, x[1] = x[1] * k % m;
            y[0] = y[0] * k + (y[1] * k + k - 1) / m, y[1] = (y[1] * k + k - 1) % m;
        }
        return si * a;
    };
    for (i64 i = 0; n; i++)
    {
        i64 tem = check(n);
        if (tem != -1)
            ans = min(ans, tem + i * b);
        n /= k;
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}