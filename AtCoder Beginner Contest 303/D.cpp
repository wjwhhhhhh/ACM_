#include <bits/stdc++.h>
using namespace std;
using i64=long long;
const int N=3e5+10;
i64 dp[N][2];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    i64 x,y,z;
    cin>>x>>y>>z;
    string a;
    cin>>a;
    a=" "+a;
    dp[0][0]=0,dp[0][1]=z;
    int n=a.size()-1;
    for(int i=1;i<a.size();i++)
    {
        if(a[i]=='A')
        {
            dp[i][1]=min(dp[i-1][0]+y+z,min(dp[i-1][1]+x,dp[i-1][0]+z+x));
            dp[i][0]=min(dp[i-1][0]+y,min(dp[i-1][1]+z+x,dp[i-1][1]+y+z));
        }
        else
        {
            dp[i][1]=min(dp[i-1][1]+y,min(dp[i-1][0]+z+x,dp[i-1][0]+y+z));
            dp[i][0]=min(dp[i-1][1]+z+x,min(dp[i-1][0]+x,dp[i-1][1]+y+z));
        }
    }
    cout<<min(dp[n][1],dp[n][0])<<endl;
    return 0;
}