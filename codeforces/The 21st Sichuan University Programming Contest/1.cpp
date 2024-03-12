#include <bits/stdc++.h>
using namespace std;
using i64=long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int ans=0;
    for(int i=0;i<=n;i++)
    {
       for(int j=0;j+i<=n;j++)
       {
        ans+=(i^j^(n-i-j));
       }
    }
    cout<<ans<<endl;
    return 0;
}