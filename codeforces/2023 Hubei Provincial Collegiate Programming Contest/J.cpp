#include <bits/stdc++.h>
#define int long long
const int N=1e5+10;
using namespace std;
int a[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,res=0;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)res+=a[i];
    if(res<0||a[1]<0)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    int Max=-0x3f3f3f3f3f3f3f3f,sum=0,ans=0,shen=0;
    for(int i=1;i<=n;i++)
    {
        ans++;
        sum+=a[i];
        shen+=sum;
        if(shen<0)
        {
            if(Max<=0)
            {
                cout<<"-1"<<endl;
                return 0;
            }
            int tem=-shen;
            tem=(tem+Max-1)/Max;
            ans+=tem;
            shen+=tem*Max;
        }
        Max=max(Max,sum);
    }
    cout<<ans<<endl;
    return 0;
}