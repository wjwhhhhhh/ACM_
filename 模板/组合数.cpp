#include <bits/stdc++.h>
using namespace std;
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
        fac.resize(n + 1), inv.resize(n + 1);
        fac[0] = 1;
        for (int i = 1; i <= n; i++)
            fac[i] = fac[i - 1] * i % p;
        inv[n] = qmi(fac[n], p - 2, p);
        for (int i = n; i; i--)
            inv[i - 1] = inv[i] * i % p;
    }
    i64 C(int n, int m)//在n里选m
    {
        if (n < m || m < 0)
            return 0;
        if(m==0)return 1;
        return (fac[n] * inv[m] % p) * inv[n - m] % p;
    }
    i64 lucas(int n,int m)//要为质数
    {
        if (n < m || m < 0)
            return 0;
        if(m==0)return 1;
        return 1ll*C(n%p,m%p)*lucas(n/p,m/p)%p;
    }
};
inv[1]=1;
 for(int i=2;i<=n;i++){
        inv[i]=(i64)(M-M/i)*inv[M%i]%M;
    }
int main()
{
    upper_bound
    Comb a(10, 998244353);
    cout << a.C(10, 1);
}