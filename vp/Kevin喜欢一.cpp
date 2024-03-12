#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    int n;
    cin>>n;
    int si=0;
    while(n!=1)
    {
        n=(n+1)/2;
        si++;
    }
    cout<<si<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}