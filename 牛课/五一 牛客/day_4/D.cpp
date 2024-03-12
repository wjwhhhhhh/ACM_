#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int N = 1e5+10;
int a[N];
void solve()
{
    int n;
    cin >> n;
    vector<int> f(n+5);
    for (int i = 1; i <= n; i++)cin >> a[i];
    for(int i=1;i<=n;i++)f[i]=a[i]-i;
    for(int i=n-1;i>0;i--)
    {
        f[i]=max(f[i+1],f[i]);
    }
    int te=a[1]+1;
    int ans=-0x3f3f3f3f;
    for(int i=2;i<n;i++)
    {
        ans=max(ans,te+a[i]+f[i+1]);
        te=max(te,a[i]+i);
    }
    cout<<ans<<endl;
}
signed main()
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