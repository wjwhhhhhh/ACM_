#include <bits/stdc++.h>
//#define int long long
using namespace std;
using i64 = long long;
const int M = 1e9 + 7;
map<pair<int, i64>, int> mp, ma;
i64 n, m;
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
Comb co;
bool find(int d, i64 res)
{
    if (res < 0)
    {
        return false;
    }
    if (d < 0)
    {
        if (res == 0)
        {
            mp[ {d, res}] = 0;
            ma[ {d, res}] = 1;
            return true;
        }
        else return false;
    }
    if (res/m >=  (1ll << d + 1))return false;
    if(mp.find({d,res})!=mp.end())return true;
    i64 ans = 0;
    i64 si=0;

    for (int i = 0; i <= m; i++)
    {
        i64 tem = res - 1ll*i*(1ll << d);
        if (find(d - 1, tem))
        {
            ans =(ans+ 1ll*co.C(m,i)*(mp[ {d - 1, tem}] + (i & 1)*((1ll<<d)%M)*(ma[ {d - 1, tem}])%M)%M)%M;
            si=(si+1ll*co.C(m,i)*ma[{d-1,tem}]%M)%M;
        }
    }
    mp[{d,res}]=ans,ma[{d,res}]=si;
    return true;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    co.init(m,M);
    i64 idx = -1,tem=n;
    while (tem)
    {
        tem /= 2;
        idx++;
    }
    find(idx, n);
    cout << (mp[ {idx, n}]+M)%M << endl;
    return 0;
}