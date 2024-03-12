#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    int res=0;
    for(int i=0;i<n;i++)res=max(res,a[i]);
        int x=-0x3f3f3f3f,y=-0x3f3f3f3f;
    for(int i=0;i<n;i++)
    {
        if(a[i]>x)y=x,x=a[i];
        else if(a[i]>y)y=a[i];
    }
    res=max(res,x+y);
    cout<<res<<endl;
    return 0;
}