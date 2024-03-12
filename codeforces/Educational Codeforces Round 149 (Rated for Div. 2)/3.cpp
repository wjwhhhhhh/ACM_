#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    string a;
    cin>>a;
    a='0'+a;
    for(int i=1;i<a.size();i++)
    {
        if(a[i]=='?')a[i]=a[i-1];
    }
    for(int i=1;i<a.size();i++)cout<<a[i];
        cout<<'\n';
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