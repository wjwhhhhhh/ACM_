#include <bits/stdc++.h>
using namespace std;
const int M=998244353,N=3010;
long long dp[2*N][N];
long long qmi(long long k, long long p = M - 2)
{
    long long res = 1;
    while (p)
    {
        if (p & 1)
            res = res * k % M;
        k = k * k % M;
        p >>= 1;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    long long ans=1,tem=1;
    for(int i=1;i<=n+1;i++)tem=tem*i%M;
    for(int i=n+1;i<=2*n;i++)ans=ans*i%M;
        ans=ans*qmi(tem)%M;
    dp[0][0]=1;
    for(int i=1;i<=2*n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%M;

            if(j+k<=n&&i>k)dp[i][j]=(dp[i][j]-dp[i-k][j+k]+M)%M;
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    //cout<<(ans-dp[2*n][0]+M)%M;
    return 0;
}