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
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> edge(n);
    vector<array<int, 20>> w(n);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        for (int j = 0; j < 20; j++)
        {
            w[i][j] = a >> j & 1;
            // cout << w[i][j] << endl;
        }
    }
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    vector<i64> ans(n);
    for (int i = 0; i < 1; i++)
    {
        vector<array<int, 2>> dp(n);
        vector<int> siz(n);
        function<void(int, int)> dfs = [&](int u, int fa) {
            int si = 0;
            siz[u] = 1;
            for (auto c : edge[u])
            {
                if (c == fa)
                    continue;
                dfs(c, u);
                siz[u] += siz[c];
                si++;
            }
            if (si == 0)
            {
                dp[u][w[u][i]] = 0;
                dp[u][!w[u][i]] = 1;
            }
            else
            {
                dp[u][0] = dp[u][1] = 0;
                for (auto c : edge[u])
                {
                    if (c == fa)
                        continue;
                    dp[u][w[u][i]] += dp[c][w[u][i]];
                }
                dp[u][!w[u][i]] = dp[u][w[u][i]] + siz[u];
            }
        };
        dfs(0, -1);
        function<void(int, int, array<int, 2>)> dfs1 = [&](int u, int fa, array<int, 2> cnt) {
            for (auto c : edge[u])
            {
                if (c == fa)
                    continue;
                cnt[0] += dp[c][0];
                cnt[1] += dp[c][1];
            }
            ans[u] += (1ll << i) * cnt[w[u][i]];
            for (auto c : edge[u])
            {
                if (c == fa)
                    continue;
                array<int, 2> ing{};

                dfs1(c, u, ing);
            }
        };
        array<int, 2> cnt{0, 0};
        dfs1(0, -1, cnt);
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
3 -4 2 -3 4 -2 0