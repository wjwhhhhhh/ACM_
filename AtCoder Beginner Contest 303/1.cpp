#include <bits/stdc++.h>
using namespace std;
using i64=long long;
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int tem;
        cin>>tem;
        cout<<n+1-tem<<" ";
    }
    cout<<"\n";
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