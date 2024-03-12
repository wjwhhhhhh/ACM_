#include <bits/stdc++.h>
using namespace std;
using i64=long long;

void solve()
{
    int n,m;
    cin>>n>>m;
        for(int i=1;i<=n;i+2)
        {
            for(int j=1;j<=m;j++)
            {
                cout<<i+(j-1)*n<<" ";
            }
            cout<<endl;
        }
    for(int i=2;i<=n;i+2)
        {
            for(int j=1;j<=m;j++)
            {
                cout<<i+(j-1)*n<<" ";
            }
            cout<<endl;
        }
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