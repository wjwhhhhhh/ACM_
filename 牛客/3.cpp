#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    if(n==0)
    {
        cout<<"None"<<endl;
        return 0;
    }
    for(int i=1;i;i+=n)
    {
        int tem=sqrt(i);
        if(tem>n)break;
        if(tem*tem==i)cout<<tem<<endl;
    }
    return 0;
}