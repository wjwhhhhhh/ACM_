#pragma GCC optimize(3,"Ofast","inline")
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
    int size;
    static const int P;
    static int G;
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
            i64 te = i64(a[i].x + 0.5);
            tem._a.push_back(te);
        }
        return tem;
    }
};
const int poly::P = 786433;
vector<i64> poly::r;
int poly::G = poly::get_samll();
int main()
{
    int n, h;
    cin >> n >> h;
    vector<vector<int>> a(h + 1, vector<int>(n + 1));
    if(h==0)
    {
        cout<<(n==1)<<endl;
        return 0;
    }
    a[0][1] = 1, a[1][2] = 2, a[1][3] = 1;
    if (h <= 1)
    {
        cout << a[h][n] << endl;
        return 0;
    }
    for (int i = 2; i <= h; i++)
    {
        poly x(n + 1), y(n + 1);
        for (int j = 0; j <= n; j++)
        {
            x._a[j] = y._a[j] = a[i - 1][j];
        }
        auto get = poly::mul(x, y);
        for (int j = 0; j < n; j++)
            a[i][j + 1] = get._a[j];
        for (int j = 0; j < n; j++)
        {
            x._a[j] = a[i - 1][j];
            y._a[j] = a[i - 2][j];
        }
        get = poly::mul(x, y);
        for (int j = 0; j < n; j++)
            a[i][j + 1] += 2ll * get._a[j];
        for (int j = 0; j < n; j++)
            a[i][j + 1] %= poly::P;
    }
    cout << a[h][n] << endl;
}
/*
500 36 80 77
31 46 3 59 20 97 63 26 97 90 55 56 39 46 81 76 51 43 6 60 92 99 95 65 77 74 56 1 45 18 83 47 14 15 64 98 31 78 28 20 8 0 21 75 30 30 13 74 90 2 5 15 37 69 23 9 17 99 39 13 21 6 21 75 13 33 5 14 26 23 68 77 47 86 28 12 79 63 27 60 98 78 31 60 95 85 70 32 85 3 2 36 14 84 42 26 6 98 67 13 96 14 63 62 68 97 23 7 41 0 48 49 30 27 11 46 28 51 70 98 61 37 51 86 46 29 41 59 57 86 51 32 17 56 84 34 80 53 6 5 5 77 77 36 26 31 2 8 16 52 59 71 10 59 91 37 70 70 20 51 85 45 9 58 43 34 71 75 27 42 32 26 88 92 57 72 78 9 79 59 51 42 44 33 40 34 17 29 96 6 91 85 63 9 63 75 16 66 73 9 32 15 17 76 96 53 42 52 6 76 34 85 28 46 92 82 56 12 17 77 70 39 34 56 41 67 14 50 19 89 75 66 59 100 75 3 81 3 18 41 42 49 17 0 39 63 91 81 65 85 15 75 34 2 24 14 35 21 60 71 23 31 49 75 23 71 55 42 12 58 6 38 83 11 8 77 98 31 86 54 15 25 44 80 77 30 26 79 8 29 29 82 30 20 72 52 96 70 2 72 96 65 32 78 93 77 43 7 82 28 15 66 100 92 61 68 4 48 13 52 58 45 64 25 21 3 7 63 47 45 43 4 97 34 49 40 47 29 24 9 36 62 84 71 65 65 33 6 35 95 54 25 7 85 48 97 95 100 88 77 88 10 26 5 100 49 41 0 96 93 3 7 9 85 38 52 97 6 36 15 25 30 71 24 40 77 64 51 61 23 84 30 22 11 86 83 42 10 25 48 49 60 1 93 63 48 9 98 50 2 17 55 100 10 89 48 49 100 89 10 93 100 56 10 25 81 21 12 50 57 26 9 11 94 70 51 20 35 0 42 44 34 33 90 55 79 39 87 34 62 5 79 76 42 24 26 42 59 27 43 53 48 19 2 7 90 47 100 42 22 21 2 82 54 1 23 75 80 37 99 12 64 20 52 64 20 70 40 31 57 91 13 63 94 37 14 92 77 62 46
*/