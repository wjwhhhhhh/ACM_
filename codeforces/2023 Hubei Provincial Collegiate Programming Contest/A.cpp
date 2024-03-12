#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    if(n==1||m==1)
    {
        int tem=max(n,m);
        int ans=1;
        ans+=(tem)/2;
        cout<<ans<<endl;
    }
    else
    {
        int ans=min(n,m);
        int tem=abs(n-m);
        ans+=(tem+1)/2;
        cout<<ans<<endl;
    }
    return 0;
}