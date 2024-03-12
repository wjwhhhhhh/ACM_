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
    i64 C(int n, int m) // 在n里选m
    {
        if (n < m || m < 0)
            return 0;
        return (fac[n] * inv[m] % p) * inv[n - m] % p;
    }
    i64 lucas(int n, int m) // 要为质数
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
    int n, k, p;
    cin >> n >> k >> p;
    Comb co(n + 10, p);
    if (k >= n)
    {
        cout << co.fac[n] << '\n';
        return;
    }
    i64 ans = 0;
    // ans += co.fac[k];
    ans += co.fac[k] * ((n - k) * (n - k - 1) + 1);
    ans %= p;
    ans += co.C(k, 1) * co.C(n - k, 1) % p * co.fac[k] % p;
    ans %= p;
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}