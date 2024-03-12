#include <bits/stdc++.h>
using namespace std;
using i64=long long;
int find(string &a,string &b)
{
    int si=0;
    for(int i=0;i<a.size();i++)if(a[i]!=b[i])si++;
    return si;
}
void solve()
{
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    int ans=0x3f3f3f3f;
    int si=find(a,b);
    if(si&1)ans=min(ans,2*(si-1)+1);
    else ans=min(ans,si*2);
    reverse(b.begin(),b.end());
    si=find(a,b);
    if(si==0)ans=min(ans,2);
    else if(si%2==0)ans=min(ans,2*si-1);
    else ans=min(ans,2*si);
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