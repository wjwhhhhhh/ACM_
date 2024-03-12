#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 110;
int a[N];
void solve()
{
    int n,m;
    cin>>n>>m;
    if(n==1)
    {
        cout<<"YES"<<endl;
        return ;
    }
    if(n<=m)
    {
        cout<<"NO"<<endl;
        return ;
    }
    for(int i=2;i<=n*i&&i<=m;i++)
    {
        if(n%i==0)
        {
            cout<<"NO"<<endl;
            return ;
        }
    }
    cout<<"YES"<<endl;
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