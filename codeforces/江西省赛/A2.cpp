#include <bits/stdc++.h>
using namespace std;
void solves()
{
     long long a[3];
     cin>>a[0]>>a[1]>>a[2];
     sort(a,a+3);
     a[2]+=2ll*a[0],a[1]-=a[0],a[0]=0;
    long long res=0;
    if(a[1]%3==0||a[2]%3==0)
    {
        res=(a[2]+a[1])*(a[2]+a[1]);
    }
    else if(a[1]%3==2)
    {
        if((a[2]+1)%3==0) res=(a[2]+a[1])*(a[2]+a[1]);
        else
        {
            res=(a[2]+a[1]-1)*(a[2]+a[1]-1);
            res++;
        }
    }
    else
    {
        if((a[2]-1)%3==0) res=(a[2]+a[1])*(a[2]+a[1]);
        else
        {
            res=(a[2]+a[1]-1)*(a[2]+a[1]-1);
            res++;
        }
    }
    cout<<res<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        solves();
    }
    return 0;
}