#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> l(m), r(m);
    for (int i = 0; i < m; i++)cin >> l[i] >> r[i];
    int q;
    cin >> q;
    vector<int> p(q);
    for(int i=0;i<q;i++)cin>>p[i];
    int ll=0,rr=m-1;
     auto check=[&](int x)
     {
        vector<int> qian(n+1);
        for(int i=0;i<=x;i++)qian[p[i]]=1;
        for(int i=0;i<=x;i++)if(qian[i]==0)qian[i]=-1;
        for(int i=1;i<=n;i++)qian[i]+=qian[i-1];
        for(int i=0;i<m;i++)
        {
            if(qian[r[i]]-qian[l[i]-1]>0)return true;
        }
        return false;
     };
    if(check(m-1))
    {
        cout<<"-1"<<endl;
        return ;
    }
    while(ll<rr)
    {
        int mid=ll+rr>>1;
        if(check(mid))rr=mid;
        else ll=mid+1;
    }
    cout<<ll+1<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}