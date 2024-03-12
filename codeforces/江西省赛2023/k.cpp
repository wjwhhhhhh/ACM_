#include <bits/stdc++.h>
using namespace std;
int get(int l,int r,vector<int>&a)
{
    int mi=a[l],ma=a[l];
    for(int i=l+1;i<=r;i++)
    {
        mi=min(mi,a[i]),ma=max(ma,a[i]);
    }
    return ma-mi;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    vector<int> a(t);
    for(int i=0;i<t;i++)cin>>a[i];
    int ans=0x3f3f3f3f;
    for(int i=1;i<t;i++)
    {
        ans=min(ans,get(1,i,a)+get(i+1,t,a));
    }
    cout<<ans<<endl;
    return 0;
}