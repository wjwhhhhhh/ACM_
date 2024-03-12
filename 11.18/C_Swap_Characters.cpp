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
const int N = 110;
i64 dp[N][N][N];
const int M = 998244353, NN = 3e5 + 10;
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
Comb co(NN, M);
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;

    array<int, 3> cnt;
    int n, k;
    cin >> n >> k;
    string a;
    cin >> a;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int z = 0; z < N; z++)
            {
                for (int ab = 0; ab <= i; ab++)
                {
                    int ac = i - ab, cb = j - ab;
                    int ca = z - cb, ba = i - ca, bc = z - ac;
                    if (ab >= 0 && ac >= 0 && ba >= 0 && bc >= 0 && ca >= 0 && cb >= 0)
                    {
                        dp[i][j][z]++;
                    }
                }
            }
        }
    }
    cout << dp[2][1][1] << endl;
    cnt[0] = count(a.begin(), a.end(), 'A');
    cnt[1] = count(a.begin(), a.end(), 'B');
    cnt[2] = count(a.begin(), a.end(), 'C');
    i64 sum = 0;
    for (int i = 0; i <= cnt[0] && i <= 2 * k; i++)
    {
        for (int j = 0; j <= cnt[1] && j <= 2 * k; j++)
        {
            for (int z = 0; z <= cnt[2] && z <= 2 * k; z++)
            {
                if (i + j + z > 2 * k || i + j + z < 2 || i > (j + z) || j > (i + z) || z > (i + j))
                    continue;
                i64 tem = co.C(cnt[0], i) * co.C(cnt[1], j) % M * co.C(cnt[2], z) % M;
                tem = tem * dp[i][j][z] % M;
                sum = (sum + tem) % M;
            }
        }
    }
    cout << sum + 1 << endl;
    return 0;
}