#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
const double PI = acos(-1.0);

struct Complex
{
    double x, y;

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
        return Complex(x * b.x - y * b.y, x * b.y + y * b.x);
    }
};

struct poly
{
    int size;
    vector<i64> _a; // 系数
    poly()
    {
    }
    poly(int le)
    {
        size = le;
        _a.resize(le);
    }
    static void change(vector<Complex> &y, int len)
    {
        int i, j, k;
        for (int i = 1, j = len / 2; i < len - 1; i++)
        {
            if (i < j)
                std::swap(y[i], y[j]);
            // 交换互为小标反转的元素，i<j 保证交换一次
            // i 做正常的 + 1，j 做反转类型的 + 1，始终保持 i 和 j 是反转的
            k = len / 2;
            while (j >= k)
            {
                j = j - k;
                k = k / 2;
            }
            if (j < k)
                j += k;
        }
    }
    static void fft(vector<Complex> &y, int len, int on)
    {
        change(y, len);

        for (int h = 2; h <= len; h <<= 1)
        {
            Complex wn(cos(2 * PI / h), sin(on * 2 * PI / h));

            for (int j = 0; j < len; j += h)
            {
                Complex w(1, 0);

                for (int k = j; k < j + h / 2; k++)
                {
                    Complex u = y[k];
                    Complex t = w * y[k + h / 2];
                    y[k] = u + t;
                    y[k + h / 2] = u - t;
                    w = w * wn;
                }
            }
        }
        if (on == -1)
        {
            for (int i = 0; i < len; i++)
            {
                y[i].x /= len;
            }
        }
    }
    poly operator*(poly const &v) const
    {
        int len = 1;
        while (len < 2 * size || len < 2 * v.size)
            len <<= 1;
        vector<Complex> a(len, Complex(0.0, 0.0)), b(len, Complex(0.0, 0.0));
        for (int i = 0; i < size; i++)
            a[i].x = _a[i];
        for (int i = 0; i < v.size; i++)
            b[i].x = v._a[i];
        fft(a, len, 1), fft(b, len, 1);
        for (int i = 0; i < len; i++)
            a[i] = a[i] * b[i];
        fft(a, len, -1);
        poly tem(0);
        for (int i = 0; i < len; i++)
        {
            int te = int(a[i].x + 0.5);
            tem._a.push_back(te);
        }
        if (tem._a.size() > 0 && tem._a.back() == 0)
            tem._a.pop_back();
        tem.size = tem._a.size();
        return tem;
    }
};
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
i64 qmi(i64 k, i64 p = M - 2)
{
    i64 res = 1;
    while (p)
    {
        if (p & 1)
            res = res * k % M;
        k = k * k % M;
        p >>= 1;
    }
    return res;
}
const int N = 1e5 + 10;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    Comb co(N, M);
    poly b(N + 10);
    for (int i = 1; i < b._a.size(); i++)
        b._a[i] = (1ll * i * i) % M;
    int n = N;
    vector<i64> ans(n + 1);
    ans[0] = 1;
    auto get = [&](int t) {
        if (t == 0)
            return 1ll;
        else
            return (ans[t] * co.fac[t - 1] % M) * co.inv[t] % M;
    };
    function<void(int, int)> solve = [&](int l, int r) {
        if (l == r)
            return;
        int mid = l + r >> 1;
        solve(l, mid);
        poly x(mid - l + 1);
        poly y(r - l + 1);
        for (int i = 0; i <= r - l; i++)
            y._a[i] = b._a[i];
        for (int i = 0; i <= mid - l; i++)
        {
            x._a[i] = get(l + i);
        }
        auto get = poly::mul(x, y);
        for (int i = mid + 1; i <= r; i++)
            ans[i] += get._a[i - l];
        for (int i = mid + 1; i <= r; i++)
            ans[i] %= M;
        solve(mid + 1, r);
    };
    solve(0, n);
    int q;
    while (cin >> q)
    {
        cout << ans[q] * co.fac[q - 1] << '\n';
    }
}