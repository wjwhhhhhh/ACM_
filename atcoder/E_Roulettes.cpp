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
const int N = 110;
double g[N][N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        int len;
        cin >> len;
        vector<int> a(len);
        for (int i = 0; i < len; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        for (auto ch : a)
        {
            g[i][ch] += 1.0 / len;
        }
        for (int j = N - 2; j >= 0; j--)
            g[i][j] += g[i][j + 1];
        for (int j = N - 2; j >= 0; j--)
        {
            if (g[i][j] == 0)
                g[i][j] = 1e9;
            else
                g[i][j] = 1.0 * v[i] / g[i][j];
        }
    }
    vector<double> dp(m + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j < i; j++)
        {
            for (int k = 0; k < n; k++)
            {
                chkmin(dp[i], dp[j] + g[k][i - j]);
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}