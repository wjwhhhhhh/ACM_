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
const int M = 998244353, N = 2e5 + 10;
i64 dp[N][4];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;

    dp[0][0] = 1;
    for (int i = 1; i < N; i++)
    {
        dp[i][0] = (25 * dp[i - 1][0] + 24 * dp[i - 1][1] + 25 * dp[i - 1][2]) % M;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % M;
        dp[i][2] = dp[i - 1][1];
        dp[i][3] = (dp[i - 1][3] * 26 + dp[i - 1][2]) % M;
    }
    int t;
    cin >> t;
    while (t--)
    {
        int a;
        cin >> a;
        cout << dp[a][3] << '\n';
    }
    return 0;
}