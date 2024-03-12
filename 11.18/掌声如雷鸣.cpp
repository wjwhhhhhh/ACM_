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
const int N = 510, M = 998244353;
i64 dp[2][N][2 * N];
i64 he[N][N];
int depth[N];
int siz[N];
i64 tem[2 * N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < N; i++)
        dp[0][i][0] = 1;
    if (k > 2 * n)
    {
        cout << "0" << endl;
        return 0;
    }
    vector<vector<int>> edge(n);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    function<void(int, int)> dfs = [&](int u, int fa) {
        siz[u] = 1;
        for (auto c : edge[u])
        {
            if (c == fa)
                continue;
            depth[c] = depth[u] + 1;
            dfs(c, u);
            siz[u] += siz[c];
            for (int i = depth[u] + 1; i <= depth[u] + siz[c]; i++)
            {
                he[u][i] += he[c][i];
            }
        }
        for (auto c : edge[u])
        {
            if (c == fa)
                continue;
            for (int i = 0; i <= 2 * siz[u]; i++)
                tem[i] = 0;
            for (int i = 1; i <= siz[c]; i++)
            {
                for (int j = 2 * siz[u] - i; j >= 0; j--)
                {
                    tem[i + j] += dp[0][u][j] * he[c][i + depth[u]] % M;
                    tem[i + j] += dp[1][u][j] * he[c][i + depth[u]] % M;
                }
            }
            // if (u == 0)
            //     cout << tem[1] << endl;
            for (int j = 1; j < 2 * siz[c]; j++)
            {
                for (int i = 2 * siz[u] - j - 2; i >= 0; i--)
                {
                    dp[0][u][j + i + 2] += (dp[0][c][j] + dp[1][c][j]) * dp[0][u][i];
                    dp[0][u][j + i + 2] %= M;
                    dp[1][u][j + i + 2] +=
                        (dp[0][c][j] + dp[1][c][j]) * dp[1][u][i] + (dp[0][c][j] + dp[1][c][j]) * dp[0][u][i];
                }
            }
            for (int i = 0; i <= 2 * siz[u]; i++)
                dp[1][u][i] += tem[i];
        }
        he[u][depth[u]]++;
    };
    dfs(0, -1);

    for (int i = 0; i <= 2 * n; i++)
        cout << dp[1][1][i] << endl;
    cout << 2 * dp[1][0][k] << endl;
    return 0;
}