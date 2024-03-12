#include <bits/stdc++.h>
using namespace std;
using i64=long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    map<int,vector<int> >mp;
    for(int i=1;i<=n;i++)
    {
        int tem;
        cin>>tem;
        mp[tem].push_back(i);
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        if(mp.find(x)==mp.end()||mp[x].size()<y)
        {
            cout<<"-1"<<'\n';
        }
        else cout<<mp[x][y-1]<<'\n';
    }
    return 0;
}