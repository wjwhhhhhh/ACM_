#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
const int N=4e6+10;
int mp[N],all[N],st[N],has[N];
using i64=long long;
void solve()
{
    int n;
    cin>>n;
    int idx=0;
    for(int i=0;i<n;i++)
    {
        int len;
        cin>>len;
        for(int z=0;z<len;z++)
        {
            int a;
            cin>>a;
            all[idx]=a;
            mp[idx++]=i;
        }
    }
    vector<int> o(idx);
    iota(o.begin(), o.end(), 0);
        sort(o.begin(),o.end(), [&](int x, int y) {return all[x]<all[y];
        });
        auto check=[&](int len)
        {
            memset(st,0,4*(n+5));
            int hh=0,tt=-1;
            int res=0;
            for(auto &x:o)
            {
                while(hh<=tt&&all[has[hh]]+len<all[x])
                {
                    st[mp[has[hh]]]--;
                    if(st[mp[has[hh]]]==0)res--;;
                    hh++;
                }
                has[++tt]=x;
                if(st[mp[x]]==0)res++;
                st[mp[x]]++;
                if(res==n)return true;
            }
            return false;
        };
    int l=0,r=2e9;
    while(l<r)
    {
        int mid=1ll*l+r>>1;
        if(check(mid))r=mid;
        else l=mid+1;
    }
    cout<<l<<'\n';
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