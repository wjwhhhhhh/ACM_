#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int a[N];
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> a[i];
    for(int i=0;i<=n;i++)
    {
        int si=0;
        for(int j=1;j<=n;j++)
        {
            if(a[j]<=i)si++;
        }
        if(si==(n-i))
        {
            cout<<i<<endl;
            return ;
        }
    }
    cout<<"-1"<<endl;
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