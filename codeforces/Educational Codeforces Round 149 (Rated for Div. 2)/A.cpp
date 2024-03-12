#include <bits/stdc++.h>
using namespace std;
using i64=long long;
void solve()
{
    int x,k;
    cin>>x>>k;
    if(x%k!=0)
    {
        cout<<1<<'\n'<<x<<'\n';
    }
    else
    {
        cout<<2<<'\n';
        cout<<1<<' '<<x-1<<'\n';
    }
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