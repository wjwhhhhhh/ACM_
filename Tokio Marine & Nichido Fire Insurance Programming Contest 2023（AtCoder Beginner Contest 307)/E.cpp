#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int M = 998244353;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    i64 n, m;
    cin >> n >> m;
    i64 x = 0, y = 1;
    for (int i = 2; i <= n; i++)
    {
        int r = x * (m - 1) % M, l = (y + (m - 2) * x) % M;
        x = l, y = r;
        // cout << x << " " << y << endl;
    }
    i64 ans = x * (m - 1) % M;
    ans = (ans * m) % M;
    cout << ans << endl;
    return 0;
}