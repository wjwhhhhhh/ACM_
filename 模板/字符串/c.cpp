#include <bits/stdc++.h>
#define int long long
using namespace std;
using i64 = long long;
void slove()
{
    string a;
    cin>>a;
    int mp[5];
    mp[0]=1,mp[1]=10,mp[2]=100,mp[3]=1000,mp[4]=10000;
    int n=a.size();
    std::vector<std::vector<int> >dp(n+1,vector<int>(5,0));
    std::vector<std::vector<int> >f(n+1,vector<int>(5,0));
    for(int i=n-1;~i;i--)
    {
        int si=a[i]-'A';
        for(int j=0;j<5;j++)
        {
            if(si>=j)dp[i][si]=max(dp[i][si],dp[i+1][j]+mp[si]);
            else dp[i][j]=max(dp[i][j],dp[i+1][j]-mp[si]);
        }
        for(int j=0;j<5;j++)
        {
            for(int k=0;k<5;k++)
            {
                if(j>=k)
                {
                    dp[i][j]=max(dp[i][j],f[i+1][k]+mp[j]);
                }
                else dp[i][k]=max(dp[i][k],f[i+1][k]-mp[j]);

            }
        }
        for(int j=0;j<5;j++)
        {
            if(si>=j)f[i][si]=max(f[i][si],f[i+1][j]+mp[si]);
            else f[i][j]=max(f[i][j],f[i+1][j]-mp[si]);
        }
    }
    int ans=0;
    for(int j=0;j<5;j++)
    {
        ans=max(ans,f[0][j]);
        ans=max(ans,dp[0][j]);
    }
    cout<<ans<<endl;

}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        slove();
    }
    return 0;
}