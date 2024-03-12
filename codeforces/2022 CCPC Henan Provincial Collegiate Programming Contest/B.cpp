#include <bits/stdc++.h>
#define int long long
using namespace std;
using i64=long long;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> h(n);
    for(int i=0;i<n;i++)cin>>h[i];
    vector<int> lr(n);
    lr[n-1]=n-1;
    for(int i=n-2;~i;i--)
    {
        if(h[lr[i+1]]>h[i+1])lr[i]=lr[i+1];
        else lr[i]=i+1;
    }
    priority_queue< pair<i64,i64> > st;
    int l=0,r;
    while(l<n)
    {
        int r;
        for(r=l+1;r<=lr[l]&&r<n;r++)
        {
            if(h[r]>=h[l])break;
        }
        i64 tem=abs(h[r]-h[l]),cnt=0;
        for(int i=l+1;i<=r;i++)
        {
            cnt+=abs(h[i]-h[i-1]);
        }
        st.push({cnt-tem,tem});
        l=r;
    }
    i64 ans=0;
    while(m--&&st.size())
    {
        ans+=st.top().second;
        st.pop();
    }
    while(st.size())
    {
        ans+=st.top().second+st.top().first;
        st.pop();
    }
    cout<<ans<<endl;
    return 0;
}
