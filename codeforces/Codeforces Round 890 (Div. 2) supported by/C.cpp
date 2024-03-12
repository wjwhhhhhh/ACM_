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
    int n,k;
    cin>>n>>k;
    std::vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int last=-1;
    int l=n-1;
    for(int i=n-1;i>=0;i--)
    {
        if(last<a[i])last=a[i],l=i;
        else last++;
    }
    a.erase(a.begin()+l+1,a.end());
    int t=a.back();
    n=a.size();
    vector<vector<i64>> dp(n,vector<i64>(2*n,1e16));
    for(int i=0;i<=max(a[n-1]-(t-n),-1);i++)
        {
            dp[n-1][i]=0;
        }
    for(int j=n-2;j>=0;j--)
    {
        for(int i=0;i<=max(a[j]-(t-n),-1);i++)
        {
            dp[j][i]=0;
        }
        if(a[j]-(t-n)<0)dp[j][0]=(t-n)-a[j];
        for(int i=max(0,a[j]-(t-n))+1;i<=(n+n-j-1);i++)
        {
            chkmin(dp[j][i],i+t-n-a[j]+dp[j+1][i-1]);
        }
    }
    for(int i=n;i<2*n;i++)
    {
        bool fl=false;
        for(int j=0;j<n;j++)
        {
            if(dp[j][i]<=k)fl=true;
        }
        if(!fl)
        {
            cout<<t+i-1-n<<endl;
            return;
        }
    }
    cout<<t+n-1<<endl;
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