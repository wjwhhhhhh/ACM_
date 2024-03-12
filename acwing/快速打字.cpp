#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    string a,b;
    cin>>a>>b;
    int l=0,r=0;
    while(l<a.size()&&r<b.size())
    {
        if(a[l]==b[r])l++,r++;
        else r++;
    }
    if(l==a.size())cout<<b.size()-a.size()<<endl;
    else cout<<"IMPOSSIBLE"<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for(int tt=0;tt<t;tt++)
    {
        cout<<"Case #"<<tt+1<<": ";
        solve();
    }
    return 0;
}