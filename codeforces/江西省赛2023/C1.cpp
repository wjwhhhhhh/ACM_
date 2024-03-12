#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n,p,ans=0;
    cin>>n>>p;
    for(int i=0;i<n;i++)
    {
        long long tem;
        cin>>tem;
        if(p&1)
        {
            if(tem&1)ans^=1;
            else ans^=0;
        }
        else
        {
            int len=p/2;
            tem++;
            len=2*len+1;
            if(tem%len==0)ans^=2;
            else if((tem%len)&1)ans^=0;
            else ans^=1;
        }
    }
    if(ans)cout<<"GOOD";
        else cout<<"BAD";
    return 0;
}