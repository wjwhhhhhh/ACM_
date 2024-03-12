#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
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
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    a = ' ' + a, b = ' ' + b;
    vector<array<long long, 3> >dp(n + 1);
    dp[0][1] = 1;
    long long ans = 0,si=0;
    for (int i = 1; i < a.size(); i++)
    {
        si+=(a[i]=='?'),si+=(b[i]=='?');
        if (a[i] == '?' && b[i] == '?')
        {
            dp[i][0] = (dp[i - 1][0] * 55ll + dp[i - 1][1] * 45ll) % M;
            dp[i][1] = (dp[i - 1][1] * 10) % M;
            dp[i][2] = (dp[i - 1][2] * 55ll + dp[i - 1][1] * 45ll) % M;;
        }
        else if (a[i] == '?')
        {
            int tem = b[i] - '0';
            ans = (ans + 10 + dp[i - 1][0] * (9 - tem) + dp[i - 1][2] * (tem)) % M;
            dp[i][0] = (dp[i - 1][0] * (tem + 1) + dp[i - 1][1] * (tem)) % M;
            dp[i][1] = dp[i - 1][1] % M;
            dp[i][2] = (dp[i - 1][2] * (10 - tem) + dp[i - 1][1] * (9 - tem)) % M;
        }
        else if (b[i] == '?')
        {
            int tem = a[i] - '0';
            ans = (ans + 10 + dp[i - 1][0] * (tem) + dp[i - 1][2] * (9 - tem)) % M;
            dp[i][0] = (dp[i - 1][0] * (10 - tem) + dp[i - 1][1] * (9 - tem)) % M;
            dp[i][1] = dp[i - 1][1] % M;
            dp[i][2] = (dp[i - 1][2] * (tem + 1) + dp[i - 1][1] * (tem)) % M;
        }
        else
        {
            if(a[i]>b[i])dp[i][0]=0,dp[i][1]=0,dp[i][2]=(dp[i-1][2]+dp[i-1][1])%M;
            else if(a[i]<b[i])dp[i][2]=0,dp[i][1]=0,dp[i][0]=(dp[i-1][0]+dp[i-1][1])%M;
            else if(a[i]==b[i])dp[i][0]=dp[i-1][0],dp[i][1]=dp[i-1][1],dp[i][2]=dp[i-1][2];
        }
    }
    ans=si!=0?qmi(10,si):1;
    //cout<<dp[2][0];
    ans-=(dp[n][0]+dp[n][1]+dp[n][2])%M;
    cout<<(ans+M)%M;
    return 0;
}