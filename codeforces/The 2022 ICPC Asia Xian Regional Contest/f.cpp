#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n,c1,c2;
    cin>>n>>c1>>c2;
    long long ans=0;
    while(n--)
    {
        string tem;
        cin>>tem;
        sort(tem.begin(),tem.end());
        if(2*c1>c2&&(tem[0]==tem[1]||tem[1]==tem[2]))
        {
            ans+=min(c1,c2)+c2;
        }
        else
        {
            ans+=3*min(c1,c2);
        }
    }
    cout<<ans<<endl;
    return 0;
}