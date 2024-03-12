#include <bits/stdc++.h>
using namespace std;
using i64=long long;
void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int> f(n+1);
    for(int i=1;i<=n;i++)cin>>f[i];
    if(n==k)
    {
        cout<<0<<endl;
        return ;
    }
    i64 l=1,r=1e16;
    auto check=[&](int x)
    {
        priority_queue<int>a,b;
        vector<int>dp1(n+2),dp2(n+2);
        i64 ans=0;
        for(int i=1;i<=n;i++)
        {
            if(f[i]>x)dp1[i]=dp1[i-1];
            else
            {
                if(ans+f[i]<=x)
                {
                    dp1[i]=dp1[i-1]+1;
                    a.push(x);
                }
                else if(f[i]<a.top())
                {
                    dp1[i]=dp1[i-1];
                    auto tr=a.top();
                    ans-=(tr-f[i]);
                    a.pop();
                    a.push(f[i]);
                }
                else dp1[i]=dp1[i-1];
            }
        }
        for(int i=n;i>0;i--)
        {
            if(f[i]>x)dp2[i]=dp2[i+1];
            else
            {
                if(ans+f[i]<=x)
                {
                    dp2[i]=dp2[i+1]+1;
                    b.push(x);
                }
                else if(f[i]<a.top())
                {
                    dp2[i]=dp2[i-1];
                    auto tr=a.top();
                    ans-=(tr-f[i]);
                    b.pop();
                    b.push(f[i]);
                }
                else dp2[i]=dp2[i-1];
            }
        }
        for(int i=1;i<n;i++)
        {
            if(dp1[i]+dp2[i+1]>=k)return true;
        }
        return false;
    };
    while(l<r)
    {
        i64 mid=l+r>>1;
        if(check(mid))r=mid;
        else l=mid+1;
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