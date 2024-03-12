#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
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
        return Complex((i64)x % P, (i64)y % P);
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
__int128 CRT(array<i64, 3> &a, array<i64, 3> &mod)
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
    int size;
    int MOD;
    static const int P1 = 998244353, P2 = 1004535809, P3 = 469762049;
    static const int G = 3;
    vector<i64> _a; // 系数
    static vector<i64> r;
    poly()
    {
    }
    poly(int le)
    {
        size = le;
        _a.resize(le);
    }
    poly(vector<i64> a)
    {
        _a = a;
    }
    static i64 qmi(i64 k, i64 p, i64 P)
    {
        i64 res = 1;
        while (p)
        {
            if (p & 1)
                res = res * k % P;
            k = k * k % P;
            p >>= 1;
        }
        return res;
    }
    static void ntt(vector<i64> &x, int lim, int opt, int P)
    {
        for (int i = 0; i < lim; ++i)
            if (r[i] < i)
                swap(x[i], x[r[i]]);
        for (int m = 2; m <= lim; m <<= 1)
        {
            int k = m >> 1;
            int gn = qmi(G, (P - 1) / m, P);
            for (int i = 0; i < lim; i += m)
            {
                int g = 1;
                for (int j = 0; j < k; ++j, g = 1ll * g * gn % P)
                {
                    int tmp = 1ll * x[i + j + k] * g % P;
                    x[i + j + k] = (x[i + j] - tmp + P) % P;
                    x[i + j] = (x[i + j] + tmp) % P;
                }
            }
        }
        if (opt == -1)
        {
            reverse(x.begin() + 1, x.begin() + lim);
            int inv = qmi(lim, P - 2, P);
            for (int i = 0; i < lim; ++i)
                x[i] = 1ll * x[i] * inv % P;
        }
    }
    static poly mul(poly const &a, poly const &b, int P)
    {
        int len = 1;
        while (len < b._a.size() << 1 || len < a._a.size() << 1)
            len <<= 1;
        r.resize(len);
        for (int i = 0; i < len; ++i)
            r[i] = (i & 1) * (len >> 1) + (r[i >> 1] >> 1);
        vector<i64> x(len), y(len);
        for (int i = 0; i < a._a.size(); i++)
            x[i] = a._a[i];
        for (int i = 0; i < b._a.size(); i++)
            y[i] = b._a[i];
        ntt(x, len, 1, P), ntt(y, len, 1, P);
        for (int i = 0; i < len; i++)
            x[i] = (x[i] * y[i]) % P;
        ntt(x, len, -1, P);
        return poly(x);
    }

    poly operator*(poly const &v) const
    {
        poly a[3];
        a[0] = mul(*this, v, P1);
        a[1] = mul(*this, v, P2);
        a[2] = mul(*this, v, P3);
        array<i64, 3> mod = {P1, P2, P3};
        poly ans(a[0]._a.size());
        // cerr << a[0]._a.size() << endl;
        for (int i = 0; i < a[0]._a.size(); i++)
        {
            // cerr << i << endl;
            array<i64, 3> ge = {};
            for (int j = 0; j < 3; j++)
                ge[j] = a[j]._a[i];
            ans._a[i] = CRT(ge, mod) % MOD;
        }
        return ans;
    }
};
vector<i64> poly::r;
int main()
{
    int n, m, p;
    cin >> n >> m >> p;
    poly a(n + 1), b(m + 1);
    a.MOD = b.MOD = p;
    for (int i = 0; i <= n; i++)
        cin >> a._a[i];
    for (int i = 0; i <= m; i++)
        cin >> b._a[i];
    auto get = a * b;
    // cerr << "ok";
    for (int i = 0; i < n + m + 1; i++)
        cout << get._a[i] % p << " ";
}