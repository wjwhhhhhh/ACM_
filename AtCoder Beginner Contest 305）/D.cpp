#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n),b;
    for(int i=1;i<=n;i++)
    {
        int tem;
        cin>>tem;
        a.push_back(tem);
        b.push_back(tem);
    }
    a.push_back(0x3f3f3f3f);
    int t;
    cin>>t;
    vector<pair<int,int> > query;
    for(int i=0;i<t;i++)
    {
        int l,r;
        cin>>l>>r;
        a.push_back(l);
        a.push_back(r);
        query.push_back({l,r});
    }
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    int idx=1;
    map<int,int> mp;
    for(auto i:a)
    {
        mp[idx]=i;
    }
    vector<int> qian(idx),p(idx);
    for(int i=2;i<b.size();i++)
    {
        qian[b[i-1]]++,qian[i]--;
    }
    int tem=0;
    for(int i=1;i<idx;i++)
    {
        p[i]=p[i-1]+tem*(mp[i]-mp[i-1]);
        tem+=qian[i];
    }
    for(auto [x,y]:query)
    {
        cout<<p[y]-p[x]<<endl;
    }
    return 0;
}