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
const int N = 3e5 + 10;
vector<int> edge[N];
int w[N];
two dp[N]; // 有几个，和最近的距离
int ans[N];
int all = 0;
void dfs(int u, int fa)
{
    // cout << u << endl;
    dp[u] = {0, 0x3f3f3f3f};
    for (auto c : edge[u])
    {
        if (c == fa)
            continue;
        dfs(c, u);
        dp[u][0] += dp[c][0];
        chmin(dp[u][1], dp[c][1] + 1);
    }
    if (w[u] == 1)
    {
        dp[u][0]++;
        dp[u][1] = 0;
        ans[u] = true;
    }
    else
    {
        for (auto c : edge[u])
        {
            if (c == fa)
                continue;
            if (dp[c][0] == 0)
                continue;
            else if (dp[c][0] == 1)
            {
                if (w[c] == 1)
                    ans[u] = true;
            }
            else
            {
                if (ans[c] == true)
                    ans[u] = true;
            }
        }
    }
}
void dfs1(int u, int fa)
{
    if (w[u] == 1)
    {
        for (auto c : edge[u])
        {
            if (c == fa)
                continue;
            ans[c] = true;
            dfs1(c, u);
        }
    }
    else
    {
        for (auto c : edge[u])
        {
            if (c == fa)
                continue;

            int cnt = all - dp[c][0];
            if (cnt == 1)
            {
                if (w[u])
                    ans[c] = true;
            }
            else if (cnt >1)
            {
                if (ans[u])
                    ans[c] = true;
            }
            dfs1(c, u);
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> w[i];
    for (int i = 0; i < n; i++)
        all += (w[i] == 1);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    dfs(0, -1);
    // cout << ans[5] << endl;
    int cnt = 0;
    dfs1(0, -1);
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    return 0;
}