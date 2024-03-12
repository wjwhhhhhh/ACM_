#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 110;
i64 dp[N][N];
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
void solve()
{
    int n, k, m;
    cin >> n >> k >> m;
    Comb co(N, M);
    memset(dp, 0, sizeof dp);
    string ing, need;
    cin >> ing >> need;
    int si = 0;
    for (int i = 0; i < n; i++)
        si += (need[i] == ing[i]);
    dp[0][si] = 1;
    for (int i = 0; i < k; i++)
        for (int j = 0; j <= n; j++)
            for (int z = max(0, m - (n - j)); z <= j && z <= m; z++)
            {
                dp[i + 1][j - z + (m - z)] =
                    (dp[i + 1][j - z + (m - z)] + (dp[i][j] * co.C(j, z) % M) * co.C(n - j, m - z) % M) % M;
            }
    cout << dp[k][n] << '\n';
}
signed main()
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