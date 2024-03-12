#pragma GCC optimize(3, "Ofast", "inline")
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
struct poly
{
    static const int P;
    static int G;
    vector<i64> _a; // 系数
    static vector<i64> r;
    poly()
    {
    }
    poly(int le)
    {
        _a.resize(le);
    }
    poly(vector<i64> a)
    {
        _a = a;
    }
    static i64 qmi(i64 k, i64 p)
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
    static int get_samll()
    {
        int m = P - 1;
        std::vector<int> b;
        for (int i = 2; i <= m / i; i++)
        {
            if (m % i == 0)
            {
                b.push_back(i);
                while (m % i == 0)
                    m /= i;
            }
        }
        if (m != 1)
        {
            b.push_back(m);
        }
        for (int g = 1; g < P; g++)
        {
            bool valid = true;
            for (auto p : b)
            {
                if (qmi(g, (P - 1) / p) == 1)
                {
                    valid = false;
                    break;
                }
            }
            if (valid)
            {
                return g;
                break;
            }
        }
        return -1;
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
    static void ntt(vector<i64> &x, int lim, int opt)
    {
        for (int i = 0; i < lim; ++i)
            if (r[i] < i)
                swap(x[i], x[r[i]]);
        for (int m = 2; m <= lim; m <<= 1)
        {
            int k = m >> 1;
            int gn = qmi(G, (P - 1) / m);
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
            int inv = qmi(lim, P - 2);
            for (int i = 0; i < lim; ++i)
                x[i] = 1ll * x[i] * inv % P;
        }
    }
    static poly mul(poly const &a, poly const &b)
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
        ntt(x, len, 1), ntt(y, len, 1);
        for (int i = 0; i < len; i++)
            x[i] = (x[i] * y[i]) % P;
        ntt(x, len, -1);
        return poly(x);
    }
    poly operator*(poly const &v) const
    {
        int len = 1;
        while (len < _a.size() << 1 || len < v._a.size() << 1)
            len <<= 1;
        vector<Complex> a(len, Complex(0.0, 0.0)), b(len, Complex(0.0, 0.0));
        for (int i = 0; i < _a.size(); i++)
            a[i].x = _a[i];
        for (int i = 0; i < v._a.size(); i++)
            b[i].x = v._a[i];
        fft(a, len, 1), fft(b, len, 1);
        for (int i = 0; i < len; i++)
            a[i] = a[i] * b[i];
        fft(a, len, -1);
        poly tem(0);
        for (int i = 0; i < len; i++)
        {
            i64 te = i64(a[i].x + 0.5);
            tem._a.push_back(te);
        }
        return tem;
    }
};
const int poly::P = 998244353;
vector<i64> poly::r;
int poly::G = poly::get_samll();