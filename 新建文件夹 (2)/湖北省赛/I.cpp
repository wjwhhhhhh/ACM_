#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
template <class T> void chmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
}
template <class T> void chmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
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
const int M = 1e9 + 7;
const int N = 2e5 + 10;
Comb co(N, M);
int k;
int fac[1 << 10];
int n;
i64 w[2][N][11];
int cao(string a)
{
    set<int> has;
    for (auto c : a)
    {
        has.insert(c);
    }
    return has.size();
}
i64 bigj[11][N];
i64 smallj[11][N];
int get(string a)
{
    i64 ans = 0;
    for (int i = 1; i < n; i++)
    {
        ans += (w[0][i][k] + w[1][i][k]);
        ans %= M;
    }
    int ing = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < a[i] - '0'; j++)
        {
            if (i == 0 && j == 0)
                continue;
            ans += bigj[fac[ing | 1 << j]][n - 1 - i];
            ans %= M;
        }
        ing |= 1 << a[i] - '0';
        if (fac[ing] > k)
            break;
    }
    ans += (cao(a) == k);
    return ans;
}
signed main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout << setprecision(15) << fixed;
    cin >> n;
    for (int i = 1; i < (1 << 10); i++)
    {
        fac[i] = fac[i - (i & -i)] + 1;
    }
    w[0][1][1] = 9, w[1][1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            w[0][i][j] = w[0][i - 1][j - 1] * (9 - (j - 1)) + w[0][i - 1][j] * j;
            w[0][i][j] %= M;
            w[1][i][j] = w[0][i - 2][j - 1] + w[1][i - 1][j - 1] * (10 - (j - 1)) + w[1][i - 1][j] * (j - 1);
            w[1][i][j] %= M;
        }
    }
    string a, b;
    cin >> a >> b;
    cin >> k;
    smallj[0][0] = 1;
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            smallj[i][j] = smallj[i][j - 1] * i + smallj[i - 1][j - 1] % M;
            smallj[i][j] %= M;
        }
    }
    for (int z = 1; z <= k; z++)
    {
        for (int j = 0; j <= n; j++)
        {
            for (int i = k - z; i <= k; i++)
            {

                bigj[z][j] += (smallj[i][j] * co.C(z, i - (k - z)) % M) * co.fac[i] * co.C(10 - z, k - z) % M;
                bigj[z][j] %= M;
            }
        }
    }
    cout << (get(b) - get(a) + (cao(a) == k) + M) % M << endl;
    return 0;
}