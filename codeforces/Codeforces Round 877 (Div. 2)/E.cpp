#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
using i64 = long long;
struct Comb
{
#define ll long long
    ll n, p;
    vector<ll> fac, inv; // 阶乘 逆元

    long long qmi(long long k, long long p, long long M)
    {
        long long res = 1;
        while (p)
        {
            if (p & 1)
                res = res * k % M;
            k = k * k % M;
            p >>= 1;
        }
        return res;
    }
    Comb()
    {
    }
    Comb(int a, int b)
    {
        init(a,b);
    }
    void init(int a,int b)
    {
        n = a, p = b;
        fac.resize(n + 5), inv.resize(n + 5);
        fac[0] = 1;
        for (int i = 1; i <= n; i++)
            fac[i] = fac[i - 1] * i % p;
        inv[n] = qmi(fac[n], p - 2, p);
        for (int i = n; i; i--)
            inv[i - 1] = inv[i] * i % p;
    }
    int C(int n, int m)
    {
        if (n < m || m < 0)
            return 0;
        return (fac[n] * inv[m] % p) * inv[n - m] % p;
    }
};
void solve()
{
    i64 n, m, k;
    cin >> n >> m >> k;
    Comb co(n,m);
    i64 ans=co.qmi(m,k,M);
    i64 tem=co.qmi(k-1,m,M);
    for(int i=0;i<n;i++)
    {
        ans-=tem;
        tem=tem*(m-i)*co.qmi(i+1,M-2,M)*co.qmi(k-1,M-2,M);
    }
    cout<<(ans+M)%M;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}