#include <bits/stdc++.h>
using namespace std;
using i64=long long;
void solve()
{
    int n;
    cin>>n;
    std::vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    vector<double> dp(n);
    for(int i=0;i<n;i++)dp[i]+=v[i];
    for(int i=0;i<n;i++)
    {
        int len=min(6,n-1-i);
        for(int j=1;j<=len;j++)
        {
            dp[j+i]+=1.0/len*dp[i];
        }
    }
    cout<<dp[n-1]<<endl;
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