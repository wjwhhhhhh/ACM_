#include <bits/stdc++.h>
using namespace std;
using i64=long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n+2);
    for(int i=1;i<=n;i++)cin>>a[i];
    a[0]=-0x3f3f3f3f,a[n+1]=0x3f3f3f3f;
    if(n==1)
    {
        cout<<"0"<<endl;
        return 0;
    }
    sort(a.begin(),a.end());
    map<int,int> mp;
    for(int i=1;i<=n;i++)
    {
        mp[a[i]]++;
    }
    i64 ans=0;
    map<int,vector<int> >ma;
    int si=0;
    for(auto i=mp.begin();i!=mp.end();i++)
    {
        auto [x,y]=*i;
        ma[si].push_back(x);
        if(y%2)
        {
            si++;
        }
    }
    if(ma[si-1].size()==1)
    return 0;
}