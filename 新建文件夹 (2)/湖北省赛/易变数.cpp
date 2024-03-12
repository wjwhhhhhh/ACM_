#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
template <class T> void chmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
}
template <class T> void chmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
}
int dfs(int x)
{
    if (x == 1)
        return 0;
    else
    {
        return 1 + dfs(__builtin_popcount(x));
    }
}
const int N = 1100, M = 1e9 + 7;
int dp[N + 1][N + 1];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int fa[N];
    for (int i = 1; i < N; i++)
    {
        fa[i] = dfs(i);
        fa[i]++;
    }
    dp[1][1] = 1, dp[1][0] = 1;

    for (int i = 2; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dp[i][j] = ((i64)dp[i][j] + dp[i - 1][j] + M) % M;
            if (j + 1 < N)
            {
                dp[i][j + 1] += dp[i - 1][j];
                dp[i][j + 1] %= M;
            }
        }
    }

    for (int i = 1; i < N; i++)
        dp[i][0]--;
    string a;
    cin >> a;
    int n = a.size();
    int k;
    cin >> k;
    if (k == 0)
    {
        cout << "1" << endl;
        return 0;
    }
    else if (k == 1)
    {
        cout << n - 1 << endl;
        return 0;
    }
    i64 ans = 0;
    int si = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '1')
        {
            for (int j = 0; j < N; j++)
            {

                if (fa[j + si] == k)
                {
                    ans += dp[n - i - 1][j];
                    ans %= M;
                }
            }
            si++;
            ans += (fa[si] == k);
            ans %= M;
        }
    }
    cout << ans << endl;
    return 0;
}