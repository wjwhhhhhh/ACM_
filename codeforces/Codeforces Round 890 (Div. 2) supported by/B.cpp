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
    if(n==1)
    {
        cout<<"NO"<<endl;
        return ;
    }
    sort(a.begin(),a.end());
    i64 sum=0;
    for(int i=0;i<n;i++)sum+=a[i];
    for(int i=0;i<n;i++)
    {
        if(a[i]==1)a[i]=2;
        else a[i]=1;
        if(sum<a[i])
        {
            cout<<"NO"<<endl;
            return ;
        }
        sum-=a[i];
    }
    cout<<"YES"<<endl;
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