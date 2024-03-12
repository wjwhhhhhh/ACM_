#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int> >g(n+5,vector<int> (m+5)) ;
    vector<int>w(m + 5);
    for (int i = 1; i <= m; i++)cin >> w[i];
    bitset <5001> adj[n+2]={};
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
    {
        cin>>g[i][j];
    }
    for (int i = 1; i <= n; i++)
        adj[i].set();
    for(int i=1;i<=n;i++)
    {
        bitset<5001>b[n+2]={};
        for(int j=1;j<=m;j++)b[g[i][j]][j]=1;
        for(int i=n-1;i>0;i++)b[i]|=b[i+1];
        for(int j=1;j<=n;j++)
        {
            adj[i]&=b[g[i][j]+1];
        }
    }
    vector<int> dp(m+5);
    function<long long(int)> dfs = [&](int root)
    {
        if(dp[root]>0)return dp[root];
        for(int i=1;i<=m;i++)
        {
            if(adj[root][i])
            {
                dp[root]=max(dfs(i),dp[root]);
            }
        }
        return dp[root];
    };
    int ans=0;
    for(int i=1;i<=m;i++)ans=max(ans,dfs(i));
        cout<<ans<<endl;

}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    //cin >> t;
    t=1;
    while (t--)
    {
        solve();
    }
    return 0;
}