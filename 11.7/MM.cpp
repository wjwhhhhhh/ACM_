#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
#define fir(a, b, c) for (int a = b; a < c; a++)
using namespace std;
using i64 = long long;
using two = array<int, 2>;
template <class T> bool chmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
    return a == b;
}
template <class T> bool chmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
    return a == b;
}
const int N=1e9+7;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin>>n;
    vector<int> a(n);
    i64 sum=0;
    fir(i,0,n)cin>>a[i];
    fir(i,0,n)
    {
        sum=(sum+a[i])%N;
    }
    i64 ans=0;
    fir(i,0,n)
    {
        sum=(sum-a[i]+N)%N;
        ans=(ans+a[i]*a[i])%N;
        ans=(ans+2ll*sum*a[i]%N)%N;
    }
    cout<<ans<<endl;
    return 0;
}