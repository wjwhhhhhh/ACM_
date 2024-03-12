#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
const int M = 1e9 + 7;
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
        init(a, b);
    }
    void init(int a, int b)
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
    int C(int n, int m) // 在n里选m
    {
        if (n < m || m < 0)
            return 0;
        return (fac[n] * inv[m] % p) * inv[n - m] % p;
    }
    int lucas(int n, int m) // 要为质数
    {
        if (n < m || m < 0)
            return 0;
        if (m == 0)
            return 1;
        return 1ll * C(n % p, m % p) * lucas(n / p, m / p) % p;
    }
};
void solve()
{
    int n, k;
    cin >> n >> k;
    Comb co(n + 1, M);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    map<int, int> mp;
    int l, r;
    bool fl = false;
    for (int i = 0; i < n; i++)
    {
        if (mp.find(a[i]) != mp.end())
        {
            l = mp[a[i]], r = i;
            fl = true;
        }
        else
            mp[a[i]] = i;
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1])
            fl = true;
    }
    if (!fl)
    {
        cout << co.C(n, k) << endl;
    }
    else
    {
        cout << (co.C(n, k) - co.C(l + n - r - 1, k - 1) % M + M) % M << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}