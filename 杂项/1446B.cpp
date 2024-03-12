#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
template <class T> void chkmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
}
template <class T> void chkmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n, m;
    cin >> n;
    cin >> m;
    string a;
    cin >> a;
    string b;
    cin >> b;
    vector<vector<i64>> dp(n + 1, vector<i64>(m + 1));
    i64 ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (a[i] == b[j])
            {
                chkmax(dp[i][j], dp[i + 1][j + 1] + 2);
            }
            else
                chkmax(dp[i][j], dp[i + 1][j + 1] - 2);
            chkmax(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}