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
    std::vector<int> v(n*(n-1)/2);
    for(int i=0;i<n*(n-1)/2;i++)cin>>v[i];
    map<int,int> mp;
    for(int i=0;i<n*(n-1)/2;i++)mp[v[i]]++;
    vector<int> ans;
    int idx=n-1;
    for(auto [x,y]:mp)
    {
        while(y>0)
        {
            ans.push_back(x);
            y-=idx;
            idx--;
        }
    }
    ans.push_back(1e9);
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