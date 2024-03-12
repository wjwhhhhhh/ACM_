#include <bits/stdc++.h>
const int bug=false;
#define dug(x) if(bug)cerr << "死了吧小丑" << x << endl
#define fir(i,a,b) for(int i=a;i<b;i++)
#define far(a,b)for(auto a:b)
using namespace std;
using i64=long long;
template<class T> void chkmax(T &a, T b) {a > b ? (a = a) : (a = b);}
template<class T> void chkmin(T &a, T b) {a > b ? (a = b) : (a = a);}
void solve()
{
    int n;
    cin>>n;
    function<i64(int)>dfs=[&](int u)
    {
        if(u==0)return 0;
        if(u<10)return u;
        vector<int> has;
        while(u)
        {
            has.push_back(u%10);
            u/=10;
        }
        i64 all=0;
        for(int i=1;i<has.size();i++)all=all*10+has[i];
        i64 ans=0;
        int n=has.size();
        if(has[0]==0)continue;
        else
        {
            ans+=(has[0]-1)*pow(10,n)*(n+1);
            ans+=all*(n+1);
        }
        ans+=dfs(all);
        return ans;
    };
    cout<<dfs(n)<<endl;
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