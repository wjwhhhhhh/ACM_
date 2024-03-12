#include <bits/stdc++.h>
#define int long long
using namespace std;
void solves()
{
    int n;
    cin>>n;
    int res=0;
    for(int i=1;i<=n;i++)
    {
        int l=i,r=(n/i)*i-1;
        if(r>=l)res +=(1+r/i)*(r/i)*i/2;
        res+=n/i*(n-r);
    }
    cout<<res<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        solves();
    }
    return 0;
}