#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    i64 n, t;
    cin >> n >> t;
    vector<array<int, 35>> fa(n);
    vector<array<int, 35>> mi(n);
    vector<array<i64, 35>> su(n);
    for (int i = 0; i < n; i++)
    {
        cin >> fa[i][0];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> mi[i][0];
        su[i][0] = mi[i][0];
    }
    for (int k = 1; k < 35; k++)
    {
        for (int i = 0; i < n; i++)
        {
            fa[i][k] = fa[fa[i][k - 1]][k - 1];
        }
    }
    for (int k = 1; k < 35; k++)
    {
        for (int i = 0; i < n; i++)
        {
            mi[i][k] = min(mi[i][k - 1], mi[fa[i][k - 1]][k - 1]);
            su[i][k] = su[i][k - 1] + su[fa[i][k - 1]][k - 1];
        }
    }
    for (int i = 0; i < n; i++)
    {
        i64 x = i, si = t;
        i64 m = 0x3f3f3f3f, ans = 0;
        for (int k = 34; k >= 0; k--)
        {
            if ((1ll << k) <= si)
            {
                si -= (1ll << k);
                m = min(m, 1ll * mi[x][k]);
                ans += su[x][k];
                x = fa[x][k];
            }
        }
        cout << ans << " " << m << endl;
    }
    return 0;
}