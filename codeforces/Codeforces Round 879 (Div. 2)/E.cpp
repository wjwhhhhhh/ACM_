#include <bits/stdc++.h>
using namespace std;
using i64=long long;
const int INF=1e9;
void solve()
{
    int n;
    cin>>n;
    vector<i64> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    set<i64>s,pre;
    pre.insert(a[0]);
    for(int i=1;i<n;i++)
    {
        s.clear();
        s.insert(a[i]);
        for(auto j:pre)
        {
            i64 tr=j*a[i]/__gcd(j,a[i]);
            if(tr>INF)continue;
            s.insert(tr);
        }
        swap(pre,s);
    }
    int ans=1;
    while(s.find(ans)!=s.end())ans++;
    cout<<ans<<endl;
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
// (n-x)*x=z;
// x*x-nx+z=0