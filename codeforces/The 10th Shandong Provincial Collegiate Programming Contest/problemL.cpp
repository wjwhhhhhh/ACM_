#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector g(n + 1, vector<int>(n + 1, 0));
    bool fl = true;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a][b] = 1;
    }
    for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            
            {
                g[i][j] |= (g[i][k] & g[k][j]);
            }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (g[i][j] & g[j][i])
                fl = false;
        }
    int si = (n + 1) / 2, a1, a2;
    string ans;
    for (int i = 1; i <= n; i++)
    {
        a1 = a2 = 0;
        for (int j = 1; j <= n; j++)
        {
            if (g[j][i])
                a1++;
            if (g[i][j])
                a2++;
        }
        if (a1 < si && a2 < si && fl && a1 + a2 < n)
            ans += "1";
        else
            ans += "0";
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