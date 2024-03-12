#include <bits/stdc++.h>
//#define int long long
using namespace std;
const int N=1e7+10,M=998244353;
int f[6][N],a[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,a1,x,y,m,k;
    cin>>n>>a1>>x>>y>>m>>k;
    a[1]=a1;
    for(int i=2;i<=n;i++)a[i]=(1ll*a[i-1]*x+y)%m;
    for(int i=1;i<=n;i++)f[0][i]=(f[0][i-1]+a[i])%M;
    for(int i=1;i<=k;i++)for(int j=1;j<=n;j++)
    {
        f[i][j]=(f[i-1][j-1]+f[i][j-1]+(i==1?a[j]:0))%M;
    }
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        ans^=(1ll)*f[k][i]*i;
    }
    cout<<ans<<endl;
    return 0;
}