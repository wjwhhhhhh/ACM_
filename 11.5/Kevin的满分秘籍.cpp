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
const int N=2100;
i64 dp[N][N][2];//几个没确定，还要改几个,还有一个错的没改
const int M = 998244353;
template<class T>
T qmi(T k, long long p = M - 2,long long P=M)
{
    T res = 1;
    while (p)
    {
        if (p & 1)
            res = 1ll*res * k % P;
        k = 1ll*k * k % P;
        p >>= 1;
    }
    return res%P;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    for(int i=0;i<N;i++)dp[i][0][0]=0,dp[i][0][1]=1;
    for(int i=0;i<N;i++)dp[0][i][0]=i,dp[0][i][1]=i+1;
    for(int i=1;i<N;i++)
    {
        for(int j=1;j<N;j++)
        {
            dp[i][j][0]=(j*qmi(i)%M*dp[i-1][j-1][0]%M+(i-j)*qmi(j)%M*dp[i-1][j][1]%M+1)%M;
            dp[i][j][1]=(dp[i][j][0]+1)%M;
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        
    }
    return 0;
}