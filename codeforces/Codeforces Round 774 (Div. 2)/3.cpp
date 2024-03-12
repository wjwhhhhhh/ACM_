#include <bits/stdc++.h>
using namespace std;
using i64=long long;
void solve()
{
    i64 n;
    cin>>n;
    std::vector<i64> v;
    i64 te=1,si=0;
    while(te<=n)
    {
        te=te*(si+1);
        if(te<=n)v.push_back(te);
        si++;
    }
    sort(v.begin(),v.end());
    int ans=0x3f3f3f3f;
    function<void(int ,i64 ,int)>dfs=[&](int d,i64 res,int wei)
    {
      if(res>n)return ;
      if(wei==v.size())
      {
          res=n-res;
          while(res)
          {
              if(res&1)d++;
              res>>=1ll;
          }
          ans=min(ans,d);
          return ;
      }
      dfs(d,res,wei+1),dfs(d+1,res+v[wei],wei+1);
    };
    dfs(0,0,0);
    cout<<ans<<endl;
    return ;
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