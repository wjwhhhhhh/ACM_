#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int M = 998244353;
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
    int n, m, k;
    cin >> n >> m >> k;
    Comb co(n + m+100, M);
    vector<int> l(k), r(k);
    for (int i = 0; i < k; i++)
        cin >> l[i] >> r[i];
    vector<int> o(k);
    iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](int x, int y) { return l[x] < l[y] || (l[x] == l[y] && r[x] < r[y]); });
    vector<int> dp1(k), dp2(k);
    for (int i = k - 1; i >= 0; i--)
    {
        dp1[o[i]] = co.C(n - l[o[i]] + m - r[o[i]], n - l[o[i]]);
        // cout << dp1[o[i]] << endl;
        for (int j = k - 1; j > i; j--)
        {
            if (l[o[i]] <= l[o[j]] && r[o[i]] <= r[o[j]])
            {
                dp1[o[i]] =
                    (dp1[o[i]] - co.C(l[o[j]] - l[o[i]] + r[o[j]] - r[o[i]], l[o[j]] - l[o[i]]) * dp1[o[j]] % M + M) %
                    M;
            }
        }
    }
    for (int i = 0; i < k; i++)
    {
        dp2[o[i]] = co.C(l[o[i]] + r[o[i]], l[o[i]]);

        for (int j = 0; j < i; j++)
        {
            if (l[o[i]] >= l[o[j]] && r[o[i]] >= r[o[j]])
            {
                dp2[o[i]] =
                    (dp2[o[i]] - co.C(l[o[i]] - l[o[j]] + r[o[i]] - r[o[j]], l[o[i]] - l[o[j]]) * dp2[o[j]] % M + M) %
                    M;
            }
        }
    }
    i64 ans = 0;
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
        {
            if (i == j)
                continue;
            ans = (ans + dp2[i] * dp1[j] % M) % M;
        }
    cout << ans << endl;
    return 0;
}