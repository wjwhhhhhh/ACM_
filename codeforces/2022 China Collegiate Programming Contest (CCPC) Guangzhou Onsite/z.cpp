#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    vector<int> a(t+5);
    for(int  i=1;i<=t;i++)cin>>a[i];
    int res=0;
    for(int i=1;i<t;i++)
    {
        res+=(a[i]^a[t]);
    }
    cout<<res<<endl;
    return 0;
}