#include <bits/stdc++.h>
#define int long long
using i64 = long long;
using namespace std;

void solve() {
    int n,m;
    std::cin >> n >> m;
    std::vector<int> a(n),b(n);
    for(int i=0;i<n;i++)cin>>a[i]>>b[i];
    if(m==1||n==1)
    {
        cout<<b[0]<<endl;
        return ;
    }
    vector<int>o(n);
    iota(o.begin(),o.end(),0);
    sort(o.begin(),o.end(),[&](int x,int y)
    {
        return a[x]-b[x]>a[y]-b[y];
    });
    i64 ans=0;
    vector<int>q(n+2),p(n+2);
    for(int i=1;i<=n;i++)q[i]=q[i-1]+a[o[i-1]]-b[o[i-1]];
    for(int i=n;i;i--)p[i]=p[i+1]+b[o[i-1]]-b[o[i-1]];
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            if(2*(n-1)+1>m)continue;
            ans=max(ans,p[i+1]);
        }
        else
        {
            if(i+1+2*(n-i-1)>m)continue;
            ans=max(ans,q[i+1]+p[i+2]);
        }
    }
    cout<<ans<<endl;
}

int32_t main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);

    int t = 1;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }

    return 0;
}