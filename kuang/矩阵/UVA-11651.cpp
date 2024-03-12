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
    int n,m;
    cin>>n>>m;
    i64 ans=0;
    for(int i=1;i<=n;i++)
    {
        if(i%3==1)ans=ans*3%m;
        else if(i%3==2)ans=ans*2%m;
        if(i%10==0)ans=(ans+10)%m;
        if(i%5==0)ans=(ans+5)%m;
    }
    cout<<m<<endl;
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