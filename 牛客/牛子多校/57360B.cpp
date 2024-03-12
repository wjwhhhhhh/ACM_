#include <bits/stdc++.h>
const int bug=false;
#define dug(x) if(bug)cerr << "死了吧小丑" << x << endl
#define fir(i,a,b) for(int i=a;i<b;i++)
#define far(a,b)for(auto a:b)
using namespace std;
using i64=long long;
const int N=2300,M=998244353;
template <class T>
struct Tree_array
{
    vector<T> tr;
    int maxx;
    Tree_array(int n)
    {
        init(n);
    }
    Tree_array(vector<T> a)
    {
        int n=a.size();
        init(n+1);
        for(int i=1;i<n;i++)insert(i,a[i]);
    }
    void init(int n)
    {
        maxx = n;
        tr.resize(n + 1,0);
    }
    void insert(int x, T c)
    {
        for (int i = x; i <= maxx; i += lowbit(i))
            op(tr[i], c);
    }
    T ask(int x)
    {
        T res = 0;
        for (int i = x; i; i -= lowbit(i))
            op(res, tr[i]);
        return res;
    }
    int lowbit(int x)
    {
        return x & -x;
    }
    void op(T &x, T c)
    {
        x=(x+c)%M;
    }
};
i64 dp[2300][2300];
i64 f[2300][2300];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    i64 ans=0;
    int n;
    cin>>n;
    vector<int> a(n+1),b(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
        Tree_array<i64> tr(n);
    Tree_array<i64> th(n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            f[i][j]=tr.ask(j-1)+1;
            dp[i][j]=(th.ask(j-1)+f[i][j]*abs(a[i]-b[j])%M)%M;
            ans=(ans+dp[i][j])%M;
        }
        for(int j=1;j<=n;j++)
        {
            th.insert(j,dp[i][j]);
            tr.insert(j,f[i][j]);
        }
    }
    cout<<ans<<endl;
    return 0;
}