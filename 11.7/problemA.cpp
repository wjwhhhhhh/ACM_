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
const int K = 12, N = 2e5+10;
i64 dp[2 * N][K][K];
int n, k;
i64 xa[N], xb[N];
i64 dfs(int i, int t1, int t2)
{
    if (i == 2 * n)
        return 0ll;
    if (dp[i][t1][t2] != -1e18)
        return dp[i][t1][t2];
    if (i & 1)
    {
        dp[i][t1][t2] = 1e18;
        if (t2 + 1 <= k && i / 2 + 1 - t1 + t2 + 1 <= n)
        {
            chmin(dp[i][t1][t2], dfs(i + 1, t1, t2 + 1) - xb[i / 2 + 1 - t1 + t2 + 1]);
        }
        if (t1 + i / 2 - t2 < n)
        {
            chmin(dp[i][t1][t2], dfs(i + 1, t1, t2));
        }
    }
    else
    {
        if (t1 + 1 <= k && i / 2 - t2 + t1 + 1 <= n)
        {
            chmax(dp[i][t1][t2], dfs(i + 1, t1 + 1, t2) + xa[i / 2 - t2 + t1 + 1]);
        }
        if (t2 + i / 2 - t1 < n)
            chmax(dp[i][t1][t2], dfs(i + 1, t1, t2));
    }
    return dp[i][t1][t2];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    priority_queue<int> a, b;
    cin >> n >> k;
    fir(i, 1, n + 1) cin >> xa[i];
    fir(i, 1, n + 1) cin >> xb[i];
    sort(xa + 1, xa + 1 + n, greater<int>());
    sort(xb + 1, xb + 1 + n, greater<int>());
    for (int i = 0; i < N; i++)
        for (int t1 = 0; t1 < K; t1++)
            for (int t2 = 0; t2 < K; t2++)
            {
                dp[i][t1][t2] = -1e18;
            }
    // cout << dfs(0, 0, 0);
    cout << dfs(0, 0, 0) << endl;
    // cout << dp[1][1][0] << endl;
    return 0;
}