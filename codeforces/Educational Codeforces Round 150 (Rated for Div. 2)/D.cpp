#include <bits/stdc++.h>
using namespace std;
using i64=long long;
void solve()
{
    int n;
    cin>>n;
    vector<pair<int,int> > a(n+1);
    vector<vector<int> > dp(n+1,vector<int>(2,1e9));
    for(int i=1;i<=n;i++)cin>>a[i].first>>a[i].second;
    std::vector<int> v;
    for(int i=1;i<=n;i++)
    {
        v.push_back(a[i].first);
        v.push_back(a[i].second);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    int idx=1;
    map<int,int>  mp;
    for(auto i:v)mp[i]=idx++;
    for(int i=1;i<=n;i++)a[i].first=mp[a[i].first],a[i].second=mp[a[i].second];
    sort(a.begin()+1,a.begin()+1+n);
    dp[0][1]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i-1;~j;j--)
        {
            if(a[j].second>=a[i].first)dp[i][1]=min(dp[i][1],dp[j][0]+i-j-1);
            else dp[i][0]=min(dp[i][0],dp[j][1]+i-j-1);
        }
    }
    int ans=n ;
    for(int i=1;i<=n;i++)
    {
        ans=min(ans,dp[i][1]+n-i);
    }
    cout<<ans<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}