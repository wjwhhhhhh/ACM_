#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64=long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<i64> a(n+1),s(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)s[i]=a[i]+s[i-1];
    bitset<210000> f={};
    f[1]=1;
    i64 ans=0;
    for(int i=1;i<=n;i++)
    {
        f|=f<<a[i];
        if(f[i])
        {
            ans=max(ans,s[i]-i+1);
            f[i]=0;
        }
    }
    for(int i=n;i<=2*n;i++)if(f[i])ans=max(ans,s[n]-i+1);
        cout<<ans<<endl;
    return 0;
}