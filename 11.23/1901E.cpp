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
    vector<int> w(n);
    for (int i = 0; i < n; i++)
        cin >> w[i];
    vector<vector<int>> edge(n);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    vector<i64> dp(n);
    function<void(int, int)> dfs = [&](int u, int fa) {
        dp[u] = w[u];
        int si = 0;
        vector<i64> all;
        for (auto c : edge[u])
        {
            if (c == fa)
                continue;
            dfs(c, u);
            all.push_back(dp[c]);
        }
        sort(all.rbegin(), all.rend());
        if (all.size())
        {
            chmax(dp[u], all[0]);
        }
        if (all.size() > 1)
        {
            i64 res = all[0];
            for (int i = 1; i < all.size(); i++)
            {
                res += all[i] + w[u];
                chmax(dp[u], res);
            }
        }
    };
    dfs(0, -1);
    i64 ans = dp[0];
        function<void(int, int,i64)> dfs = [&](int u, int fa,i64 tem) {
        chmax(ans,tem);
        vector<int> all;
        for(auto c:edge[u])
        {
            if(c==fa)continue;
            all.push_back(c);
            chmax(ans,dp[c]);
        }
        sort(all.begin(),all.end(),[&](int x,int y)
        {
            return dp[x]>dp[y];
        });
        i64 cnt=tem;
        for(int i=0;i<all.size();i++)
        {
            
        }
       
    };
    dfs1(0,-1,0);
    cout << ans << '\n';
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