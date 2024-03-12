#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M=998244353,N=1e5+10;
int qmi(int k, int p = M - 2)
{
    int res = 1;
    while (p)
    {
        if (p & 1)
            res = res * k % M;
        k = k * k % M;
        p >>= 1;
    }
    return res;
}
int dp[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    int tem=qmi(m-1,n);
    tem=qmi(tem);
    for(int i=1;i<=m;i++)
    {
        int ans=qmi(m-i,n);
        ans=(ans*tem)%M;
        cout<<ans<<' ';
    }
    //cout<<l<<endl;

    return 0;
}