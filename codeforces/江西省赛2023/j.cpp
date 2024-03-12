#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
void ch(vector<ll>&a,int l,long long b)
{
    a[l]=min(a[l],b);
    for(int i=l-1,j=1;i>0&&j<=370;j++,i--)
    {
        a[i]=min(a[i],1ll*j*j+b);
    }
    for(int i=l+1,j=1;i<=n&&j<=370;j++,i++)
    {
        a[i]=min(a[i],1ll*j*j+b);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    vector<ll> a(n+1,0x3f3f3f3f);
    for(int i=1;i<=n;i++)
    {
        int b;
        cin>>b;
        ch(a,i,b);
    }
    int m;
    cin>>m;
    while(m--)
    {
        int fl;
        cin>>fl;
        if(fl==0)
        {
            int t,c;
            cin>>t>>c;
            ch(a,t,c);
        }
        else
        {
            int t;
            cin>>t;
            cout<<a[t]<<'\n';
        }
    }
    return 0;
}