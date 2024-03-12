#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int f[510][510];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    int ans = 0;
    vector<int> b(n + 2);
    for (int i = 0; i < n; i++)
    {
        int tem;
        cin >> tem;
        ans += tem;
    }
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    memset(f, 0x3f, sizeof f);
    for (int i = 0; i + 1 <= n + 1; i++)
        f[i][i + 1] = 0;
    for (int len = 3; len <= n + 2; len++)
    {
        for (int i = 0; i + len - 1 <= n + 1; i++)
        {
            int j = i + len - 1;
            for (int k = i + 1; k < j; k++)
            {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j] + b[i] + b[j]);
            }
        }
    }
    cout << ans + f[0][n+1] << endl;
    // cout << ans << endl;
    return 0;
}