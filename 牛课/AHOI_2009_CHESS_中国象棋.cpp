#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 110;
i64 dp[N][N][N];
const int M = 9999973;
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
    int n, m;
    cin >> n >> m;
    dp[0][0][0] = 1;
    Comb C(N, M);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= m; j++)
            for (int z = 0; z <= m; z++)
            {
                (dp[i + 1][j][z] += dp[i][j][z]) %= M;
                (dp[i + 1][j + 1][z] += 1ll * dp[i][j][z] * (max(m - j - z, 0))) %= M;
                (dp[i + 1][j - 1][z + 1] += 1ll * dp[i][j][z] * max(0, j) % M) %= M;
                (dp[i + 1][j][z + 1] += (1ll * dp[i][j][z] * (max(0, m - j - z)) % M) * (j) % M) %= M;
                (dp[i + 1][j + 2][z] += 1ll * dp[i][j][z] * C.C(m - j - z, 2) % M) %= M;
                (dp[i + 1][j - 2][z + 2] += 1ll * dp[i][j][z] * C.C(j, 2) % M) %= M;
            }
    }
    i64 ans = 0;
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= m; j++)
            (ans += dp[n][i][j]) %= M;
    cout << ans << endl;
    return 0;
}