#include <bits/stdc++.h>
using namespace std;
using i64=long long;
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(auto i:a)
    {
        if(i<0)
            {
                cout<<i<<endl;
                return ;
            }
    }
    sort(a.begin(),a.end());
    cout<<a.back()<<endl;
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