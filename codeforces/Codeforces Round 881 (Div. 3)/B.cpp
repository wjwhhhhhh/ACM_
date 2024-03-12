#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n),b;
    for (int i = 0; i < n; i++)cin >> a[i];
    int l=-1;
    i64 ans=0,sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=abs(a[i]);
        if(a[i]!=0)b.push_back(a[i]);
    }
    for(int i=0;i<b.size();i++)
    {
        if(b[i]<0)
        {
            ans++;
            while(i<b.size()&&b[i]<0)i++;
        }
    }
    cout<<sum<<" "<<ans<<endl;
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