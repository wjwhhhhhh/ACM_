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
const int N = 310;
i64 dp[N][N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    string a;
    cin >> a;
    int n = a.size();
    a = " " + a;
    int kk;
    cin >> kk;

    for (int i = 1; i <= n; i++)
        dp[i][i] = 1;
    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;
            dp[i][j] = dp[i + 1][j] + 1;
            if (a[i] != 'o')
                continue;
            for (int k = i + 1; k <= j; k++)
            {
                if (a[k] == 'f' && dp[i + 1][k - 1] == 0)
                {
                    chmin(dp[i][j], max(dp[k + 1][j] - kk, 0ll));
                }
            }
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}