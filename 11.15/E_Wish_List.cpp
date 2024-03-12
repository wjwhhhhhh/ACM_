#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
#define fir(a, b, c) for (int a = b; a < c; a++)
using namespace std;
using i64 = long long;
using two = array<int, 2>;
template <class T> bool chmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
    return a == b;
}
template <class T> bool chmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
    return a == b;
}
const int N = 5100;
i64 dp[N][N];
i64 a[N], c[N];
bool fl[N];
i64 sa[N][N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i <= n; i++)
        sa[i][i] = c[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
            sa[i][j] = min(sa[i][j - 1], c[j]);
    }
    memset(dp, 0x7f, sizeof dp);
    dp[0][0] = 0;
    for (int i = 0; i < m; i++)
    {
        int tem;
        cin >> tem;
        fl[tem] = true;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            // cerr << "ok" << endl;
            if (fl[i])
            {
                chmin(dp[i][j], a[i] + sa[j + 1][i] + dp[i - 1][j]);
            }
            else
            {
                chmin(dp[i][j], a[i] + sa[j + 1][i] + dp[i - 1][j]);
                chmin(dp[i][j + 1], dp[i - 1][j]);
            }
        }
    }
    i64 ans = 1e18;
    for (int i = 0; i <= n; i++)
        chmin(ans, dp[n][i]);
    cout << ans << endl;
    return 0;
}