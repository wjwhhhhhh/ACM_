#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    i64 n;
    cin >> n;
    i64 ans=n;
   while(n!=1)
   {
        n=n/2;
        ans+=n;
   }
   cout<<ans<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}