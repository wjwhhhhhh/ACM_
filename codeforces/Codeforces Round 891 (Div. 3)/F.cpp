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
    map<int,int> mp;
    for(int i=0;i<n;i++)mp[a[i]]++;
    int q;
    cin>>q;
    while(q--)
    {
        i64 x,y;
        cin>>x>>y;
        if(x*x<4*y)
        {
            cout<<"0 ";
            continue;
        }
        i64 a1=(x-sqrt(x*x-4*y))/2,a2=(x+sqrt(x*x-4*y))/2;
        if(a1*a1-x*a1+y!=0)
        {
            cout<<"0 ";
            continue;
        }
        if(a1==a2)
        {
            cout<<1ll*mp[a1]*(mp[a1]-1)/2<<" ";
        }
        else cout<<1ll*mp[a1]*mp[a2]<<" ";
    }
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