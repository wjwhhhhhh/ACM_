#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin>>k;
    for(int i=0;i<k;i++)cin>>a[i];
    int n,m,x;
    cin>>n>>m>>x;
    for(int i=0;i<k;i++)a[i]%=m;
    long long tem=x;
    for(int i=1;i<=n;i++)
    {
        tem+=a[(i-1)%m];
    }
    cout<<n-tem/m;
    return 0;
}