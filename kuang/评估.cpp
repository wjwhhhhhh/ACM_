#pragma GCC diagnostic error "-std=c++11"
#pragma GCC target("avx")
#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
template <class T> void chkmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
}
template <class T> void chkmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
}
const double PI = acos(-1.0);

struct Complex
{
    double x, y;
    static int I_mul_I;
    Complex(double _x = 0.0, double _y = 0.0)
    {
        x = _x;
        y = _y;
    }

    Complex operator-(const Complex &b) const
    {
        return Complex(x - b.x, y - b.y);
    }

    Complex operator+(const Complex &b) const
    {
        return Complex(x + b.x, y + b.y);
    }

    Complex operator*(const Complex &b) const
    {
        return Complex(x * b.x + y * b.y * I_mul_I, x * b.y + y * b.x);
    }
    Complex operator%(int &P) const
    {
        return Complex((int)x % P, (int)y % P);
    }
};
int Complex::I_mul_I = -1;
__int128 exgcd(__int128 a, __int128 b, __int128 &x, __int128 &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
__int128 CRT(array<int, 3> &a, array<int, 3> &mod)
{
    __int128 n = 1, ans = 0;
    for (auto x : mod)
        n *= x;
    for (int i = 0; i < a.size(); i++)
    {
        __int128 m = n / mod[i], b, y;
        exgcd(m, mod[i], b, y);
        ans = (ans + (a[i] * m % n) * b % n) % n;
    }
    return (ans % n + n) % n;
}
struct poly
{
    static const int MOD;
    static constexpr int P[3] = {998244353, 1004535809, 469762049};
    static const int G = 3;
    vector<int> _a; // 系数
    static vector<int> r;
    poly()
    {
    }
    poly(int le)
    {
        _a.resize(le);
    }
    poly(vector<int> a)
    {
        _a = a;
    }
    static int qmi(int k, int p, int P)
    {
        int res = 1;
        while (p)
        {
            if (p & 1)
                res = res * k % P;
            k = k * k % P;
            p >>= 1;
        }
        return res;
    }
    static void ntt(vector<int> &x, int lim, int opt, int id)
    {
        for (int i = 0; i < lim; ++i)
            if (r[i] < i)
                swap(x[i], x[r[i]]);
        for (int m = 2; m <= lim; m <<= 1)
        {
            int k = m >> 1;
            int gn = qmi(G, (P[id] - 1) / m, P[id]);
            for (int i = 0; i < lim; i += m)
            {
                int g = 1;
                for (int j = 0; j < k; ++j, g = 1ll * g * gn % P[id])
                {
                    int tmp = 1ll * x[i + j + k] * g % P[id];
                    x[i + j + k] = (x[i + j] - tmp + P[id]) % P[id];
                    x[i + j] = (x[i + j] + tmp) % P[id];
                }
            }
        }
        if (opt == -1)
        {
            reverse(x.begin() + 1, x.begin() + lim);
            int inv = qmi(lim, P[id] - 2, P[id]);
            for (int i = 0; i < lim; ++i)
                x[i] = 1ll * x[i] * inv % P[id];
        }
    }
    static poly mul(poly const &a, poly const &b, int id)
    {
        int len = 1;
        while (len < b._a.size() << 1 || len < a._a.size() << 1)
            len <<= 1;
        r.resize(len);
        for (int i = 0; i < len; ++i)
            r[i] = (i & 1) * (len >> 1) + (r[i >> 1] >> 1);
        vector<int> x(len), y(len);
        for (int i = 0; i < a._a.size(); i++)
            x[i] = a._a[i];
        for (int i = 0; i < b._a.size(); i++)
            y[i] = b._a[i];
        ntt(x, len, 1, id), ntt(y, len, 1, id);
        for (int i = 0; i < len; i++)
            x[i] = (1ll*x[i] * y[i]) % P[id];
        ntt(x, len, -1, id);
        return poly(x);
    }

    poly operator*(poly const &v) const
    {
        poly a[3];
        for (int i = 0; i < 3; i++)
            a[i] = poly::mul(*this, v, i);
        array<int, 3> mod = {P[0], P[1], P[2]};
        poly ans(a[0]._a.size());
        // cerr << a[0]._a.size() << endl;
        for (int i = 0; i < a[0]._a.size(); i++)
        {
            // cerr << i << endl;
            array<int, 3> ge = {};
            // cerr << "ok" << endl;
            for (int j = 0; j < 3; j++)
                ge[j] = a[j]._a[i];
            ans._a[i] = CRT(ge, mod) % MOD;
        }

        return ans;
    }
};
const int poly::MOD = 1e6 + 3;
vector<int> poly::r;
const int M = 1e6 + 3;
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
int qmi(int k, long long p = M - 2, long long P = M)
{
    int res = 1;
    while (p)
    {
        if (p & 1)
            res = 1ll * res * k % P;
        k = 1ll * k * k % P;
        p >>= 1;
    }
    return res % P;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n, b, c, d;
    cin >> n >> b >> c >> d;
    Comb co(n, M);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> f(n);
    f[0] = 1;
    for (int i = 1; i < n; i++)
        f[i] = 1ll*f[i - 1] * i * d % M;
    for (int i = 0; i < n; i++)
        f[i] = 1ll*f[i] * a[i] % M;
    vector<int> fac(n);
    for (int i = 0; i < n; i++)
        fac[i] = co.inv[i];
    reverse(fac.begin(), fac.end());
    poly y(fac), x(f);
    auto get = x * y;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
        p[i] = get._a[n - 1 + i];
    f[0] = 1;
    for (int i = 1; i < n; i++)
    {
        f[i] = (1ll*f[i - 1] * b % M) * qmi(d) * qmi(i) % M;
    }
    for (int i = 0; i < n; i++)
    {
        f[i] = 1ll*f[i] * qmi(1ll * c, 1ll * i * i)*p[i] % M;
    }

    poly a1(f), a2(2 * n - 1);
    for (int i = 0; i < 2 * n - 1; i++)
    {
        int t = n - 1;
        a2._a[i] = qmi(c, 1ll * (t - i) * (t - i)) % M;
        a2._a[i] = qmi(a2._a[i]);
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
        ans[i] = qmi(1ll * c, i * i);
    get = a1 * a2;
    for (int i = 0; i < n; i++)
    {
        ans[i] = ans[i] * get._a[n - 1 + i] % M;
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << '\n';
    return 0;
}