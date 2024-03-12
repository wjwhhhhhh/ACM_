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
    std::vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    i64 sum=0;
    vector<int> o(n);
    iota(o.begin(), o.end(), 0);
        sort(o.begin(),o.end(), [&](int x, int y) {return a[x]<a[y];
        });
    vector<int> ans(n);
    for(int i=0;i<n;i++)
    {
        ans[o[0]]+=a[o[i]]-a[o[0]]+1;
    }
    for(int i=1;i<n;i++)
    {
        ans[o[i]]=ans[o[i-1]]+(a[o[i]]-a[o[i-1]])*((i-(n-i)));
    }
    for(int i=0;i<n;i++)cout<<ans[i]<<" ";
        cout<<endl;
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