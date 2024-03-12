#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int>a(n + 1);
    for (int i = 1; i <= n; i++)cin >> a[i];
    int m;
    cin >> m;
    vector<pair<int, int> > tt(m);
    for (int i = 0; i < m; i++)cin >> tt[i].first >> tt[i].second;
    sort(tt.begin(), tt.end(), [&](pair<int, int> x, pair<int, int> y)
    {
        return x.second < y.second;
    });
    int t = 0;
    int l = 1;
    vector<int> p(n+1);
    for (int i = 1; i <= n; i++)
    {
        while (t<tt.size()&&tt[t].second < i)
        {
            l = max(tt[t].first, l);
            t++;
        }
        p[i]=l;
    }
    vector<int> dp(n+1);
    vector<int> q(n+1);
    int hh=0,th=-1;
    for(int i=1;i<=n;i++)
    {
        while(th>=hh&&q[hh]<p[i])hh++;
        dp[i]=dp[hh>th?0:q[hh]]+a[i];
        while(th>=hh&&dp[i]<dp[q[th]])th--;
        q[++th]=dp[i];
    }
    cout<<dp[n]<<'\n';

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}