#include <bits/stdc++.h>
using namespace std;
using i64=long long;
void solve()
{
    int s1,s2;
    cin>>s1;
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
        cin>>s2;
    int ans=s2-s1+1;
    for(int i=0;i<n;i++)
    {
        if(a[i]<=s2)ans--;
    }
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