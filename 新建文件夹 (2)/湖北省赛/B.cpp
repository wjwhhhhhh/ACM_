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
const int M = 1e9 + 7;
const int N = 2e5 + 10;
int k;
int fac[1 << 10];
int n;
struct Comb
{
#define ll long long
    ll n, p;
    vector<ll> fac, inv; // 阶乘 逆元

    long long qmi(long long k, long long p, long long M)
    {
        if (p < 0)
            return 0;
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
Comb co(N, M);
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
int get(string a)
{
    i64 ans = 0;
    for (int i = 1; i < n; i++)
    {
        ans += w[0][i][k] + w[1][i][k];
        ans %= M;
    }
    // cout << ans << endl;
    vector<vector<int>> last(2, vector<int>(1 << 10));
    for (int i = 1; i < a[0] - '0'; i++)
        last[0][1 << i] = 1;
    last[1][1 << a[0] - '0'] = 1;
    for (int i = 1; i < n; i++)
    {
        vector<vector<int>> ing(2, vector<int>(1 << 10));
        for (int j = 0; j < 1 << 10; j++)
        {
            ing[1][j | 1 << a[i] - '0'] += last[1][j];
            ing[1][j | 1 << a[i] - '0'] %= M;
        }
        for (int j = 0; j < 1 << 10; j++)
        {
            for (int z = 0; z < a[i] - '0'; z++)
            {
                ing[0][j | 1 << z] += last[1][j];
                ing[0][j | 1 << z] %= M;
            }
        }
        for (int j = 0; j < 1 << 10; j++)
        {
            for (int z = 0; z < 10; z++)
            {
                ing[0][j | 1 << z] += last[0][j];
                ing[0][j | 1 << z] %= M;
            }
        }
        swap(ing, last);
    }
    for (int i = 0; i < 1 << 10; i++)
    {
        if (fac[i] == k)
        {
            ans += last[0][i];
            ans += last[1][i];
            ans %= M;
        }
    }
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
    cout << get(a) << endl;
    // cout << get(b) - get(a) + (cao(a) == k) << endl;
    return 0;
}