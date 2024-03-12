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
const int N = 1100;
i64 dp[N][N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    i64 n;
    cin >> n;
    vector<i64> d(n + 1);
    fir(i, 1, n + 1) cin >> d[i];
    i64 l1, c1, k1, l2, c2, k2;
    cin >> l1 >> c1 >> k1 >> l2 >> c2 >> k2;
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int z = 0; z < N; z++)
            {
                if (j + z >= N)
                    continue;
                chmin(dp[i][j + z], dp[i - 1][j] + max(0ll, (d[i] - z * l1 + l2 - 1) / l2));
            }
        }
    }
    i64 ans = -1;
    for (int i = 0; i <= k1; i++)
    {
        if (dp[n][i] <= k2)
        {
            if (ans == -1 || i * c1 + dp[n][i] * c2 < ans)
            {
                ans = i * c1 + dp[n][i] * c2;
            }
        }
    }
    cout << ans << endl;
    return 0;
}