#include <bits/stdc++.h>
using namespace std;
using i64=long long;
void solve()
{
    int n;
    cin>>n;
    std::vector<int> a(n+1),b(n+1);
    map<int,int>ma,mb;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    int l=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i]==a[i-1])l++;
        else ma[a[i-1]]=max(ma[a[i-1]],l),l=1;
    }
    ma[a[n]]=max(ma[a[n]],l);
    l=1;
    for(int i=2;i<=n;i++)
    {
        if(b[i]==b[i-1])l++;
        else mb[b[i-1]]=max(mb[b[i-1]],l),l=1;
    }
    mb[b[n]]=max(mb[b[n]],l);
    int ans=1;
    for(int i=1;i<=2*n;i++)
    {
        ans=max(ans,ma[i]+mb[i]);
    }
    cout<<ans<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}