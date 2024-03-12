#include <bits/stdc++.h>
const int bug=false;
#define dug(x) if(bug)cerr << "死了吧小丑" << x << endl
#define fir(i,a,b) for(int i=a;i<b;i++)
#define far(a,b)for(auto a:b)
using namespace std;
using i64=long long;
const int M=998244353;
template<class T>
T qmi(T k, long long p = M - 2,long long P=M)
{
    T res = 1;
    while (p)
    {
        if (p & 1)
            res = res * k % P;
        k = k * k % P;
        p >>= 1;
    }
    return res;
}
void solve()
{
    i64 n,m,k;
    cin>>n>>m>>k;

    if(2*k<=n)
    {
        cout<<qmi(m,n-k,M)<<endl;
    }
    else if(n==k)cout<<qmi(m%M,k,M)<<endl;
    else cout<<qmi(m%M,n-k,M)<<endl;
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