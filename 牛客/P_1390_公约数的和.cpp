#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl;
using namespace std;
using i64 = long long;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    i64 n;
    cin >> n;
    vector<i64> f(n + 1);
    for (i64 i = n; i; i--)
    {
        f[i] = (n / i > 1 ? (n / i * (n / i - 1)) / 2 : 0);
        for (int j = i + i; j <= n; j += i)
            f[i] -= f[j];
    }
    i64 ans = 0;
    for (int i = 1; i <= n; i++)
        ans += 1ll * i * f[i];
    cout << ans << endl;
    return 0;
}