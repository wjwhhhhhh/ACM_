#include <bits/stdc++.h>
using namespace std;
#define int long long
using i64 = long long;
const int N = 510;
long long dp[2][N][N];
const int M = 1024523;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    string up, down;
    cin >> up >> down;
    reverse(up.begin(), up.end());
    reverse(down.begin(), down.end());
    dp[0][0][0] = 1;
    for (int k = 0; k < n + m; k++)
    {
        memset(dp[(k + 1) % 2], 0, sizeof dp[(k + 1) % 2]);
        for (int j = max(0ll, k - m); j <= min(k, n); j++)
        {
            for (int z = max(0ll, k - m); z <= min(k, n); z++)
            {
                if (j < n && z < n && up[j] == up[z])
                    dp[(k + 1) % 2][j + 1][z + 1] = (dp[(k + 1) % 2][j + 1][z + 1] + dp[(k) % 2][j][z]) % M;
                if (j < n && (k - z) < m && up[j] == down[k - z])
                    dp[(k + 1) % 2][j + 1][z] = (dp[(k + 1) % 2][j + 1][z] + dp[(k) % 2][j][z]) % M;
                if ((k - j) < m && z < n && down[k - j] == up[z])
                    dp[(k + 1) % 2][j][z + 1] = (dp[(k + 1) % 2][j][z + 1] + dp[(k) % 2][j][z]) % M;
                if ((k - j) < m && (k - z) < m && down[k - j] == down[k - z])
                    dp[(k + 1) % 2][j][z] = (dp[(k + 1) % 2][j][z] + dp[(k) % 2][j][z]) % M;
            }
        }
    }
    cout << dp[(n + m) % 2][n][n] << endl;
    return 0;
}