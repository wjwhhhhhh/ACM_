#include <bits/stdc++.h>
using namespace std;
using i64=long long;
void solve()
{
    int n;
    cin>>n;
    std::vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    sort(v.begin(),v.end());
    int l=1,r=n-1;
    i64 a=v[0],b=0;
    while(l<r)
    {
        a+=v[l++],b+=v[r--];
        if(a<b)
        {
            cout<<"YES"<<endl;
            return ;
        }
    }
    cout<<"NO"<<endl;
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