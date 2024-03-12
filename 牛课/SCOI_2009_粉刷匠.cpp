#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int M = 2500, N = 55;
int dp[M][N][N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, t;
    cin >> n >> m >> t;
    vector<string> mp(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> mp[i];
    for (int i = 1; i < n; i++)
        mp[i] = " " + mp[i];
    for (int k = 1; k <= t; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j < m; j++)
            {
            }
        }
    }
    return 0;
}