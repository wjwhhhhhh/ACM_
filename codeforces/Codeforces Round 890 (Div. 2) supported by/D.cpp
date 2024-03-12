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
    vector<vector<int>> f(n+1,std::vector<int>(n+1));
    auto ask=[&](int l,int r)
    {
        cout<<"? "<<l<<" "<<r<<endl;
        int tem;
        cin>>tem;
        return tem;
    };
    function<void(int,int)>dfs=[&](int l,int r)
    {
        if(l==r)
        {
            f[l][r]=l;
            return ;
        }
        int mid=l+r>>1;
        dfs(l,mid),dfs(mid+1,r);
        int a=ask(l,f[mid+1][r]-1),b=ask(l,f[mid+1][r]);
        if(a==b)f[l][r]=f[mid+1][r];
        else f[l][r]=f[l][mid];
        return ;
    };
    dfs(1,n);
    cout<<"! ";
    cout<<f[1][n]<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}