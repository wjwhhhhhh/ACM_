#include <bits/stdc++.h>
using namespace std;
#define int long long
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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    i64 ans = 0;
    Comb co(n, M);
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        int si = 0, l = 0;
        for (int j = 1; j <= n; j++)
        {
            si += (a[i] == a[j]);
            if (j <= i)
                l += (a[i] == a[j]);
        }
        mp[a[i]] = si;
        for (int len = 1; len <= l; len++)
        {
            for (int j = 1; 2 * len >= j; j++)
            {
                ans = (ans + 1ll*co.C(l - 1, len - 1) * co.C(n - si, j - len)%M) % M;
            }
        }
    }
    vector<int> l, r;
    for (auto [x, y] : mp)
    {
        l.push_back(x), r.push_back(y);
    }
    for (int i = 0; i < l.size(); i++)
    {
        for (int j = i + 1; j < l.size(); j++)
        {
            for (int z = 1; z <= r[i] && z <= r[j]; z++)
            {
                ans = (ans+M - 1ll*co.C(r[i], z) * co.C(r[j], z)%M) % M;
            }
        }
    }
    cout << ans << endl;
    return 0;
}