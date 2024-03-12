#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1000, M = 1000000007;

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
Comb co(N, M);
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<bitset<N>> st(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        st[a][b] = 1, st[b][a] = 1;
    }
    i64 ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            int all = st[i].count();
            auto get = (st[i] & st[j]).count();
            if (st[i][j])
                all--;
            ans = (ans + 1ll * co.C(all - 4, 2) * co.C(get, 4) % M) % M;
        }
    cout << ans << endl;
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