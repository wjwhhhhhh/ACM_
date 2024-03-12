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
    string a;
    cin >> a;
    a = " " + a;
    i64 ans = 0x3f3f3f3f;
    vector<two> edge(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> edge[i][0] >> edge[i][1];
    vector<i64> dp(n + 1, 0x3f3f3f3f);
    function<void(int)> dfs = [&](int u) {
        if (edge[u][0] == 0 && edge[u][1] == 0)
        {
            chmin(ans, dp[u]);
            return;
        }
        if (a[u] == 'U')
        {
            for (auto c : edge[u])
            {
                if (c != 0)
                {
                    dp[c] = dp[u] + 1;
                    dfs(c);
                }
            }
        }
        else if (a[u] == 'L')
        {
            if (edge[u][0] != 0)
            {
                dp[edge[u][0]] = dp[u];
                dfs(edge[u][0]);
            }
            if (edge[u][1] != 0)
            {
                dp[edge[u][1]] = dp[u] + 1;
                dfs(edge[u][1]);
            }
        }
        else
        {
            if (edge[u][0] != 0)
            {
                dp[edge[u][0]] = dp[u] + 1;
                dfs(edge[u][0]);
            }
            if (edge[u][1] != 0)
            {
                dp[edge[u][1]] = dp[u];
                dfs(edge[u][1]);
            }
        }
    };
    dp[1] = 0;
    dfs(1);
    cout << ans << endl;
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