#include <bits/stdc++.h>
using namespace std;
using i64=long long;
void solve()
{
    i64 n,s;
    cin>>n>>s;
    i64 si=0;
    si=s/(n*n);
    cout<<si<<endl;
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