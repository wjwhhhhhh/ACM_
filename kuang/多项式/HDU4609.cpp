#include <bits/stdc++.h>
const int bug=false;
#define dug(x) if(bug)cerr << "死了吧小丑" << x << endl
#define fir(i,a,b) for(int i=a;i<b;i++)
#define far(a,b)for(auto a:b)
using namespace std;
using i64=long long;
template<class T> void chkmax(T &a, T b) {a > b ? (a = a) : (a = b);}
template<class T> void chkmin(T &a, T b) {a > b ? (a = b) : (a = a);}
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
        return Complex(x * b.x - y * b.y*I_mul_I, x * b.y + y * b.x);
    }
    Complex operator%(int &P)const
    {
        return Complex((i64)x%P,(i64)y%P);
    }
};
int Complex:: I_mul_I=-1;
struct poly
{
    int size;
    vector<i64> coe; // 系数
    poly()
    {
    }
    poly(int le)
    {
        size = le;
        coe.resize(le);
    }
    poly(vector<i64> const need)
    {
        coe = need;
    }
    static void change(vector<Complex> &y, int len)
    {
        int i, j, k;
        for (int i = 1, j = len / 2; i < len - 1; i++)
        {
            if (i < j)
                std::swap(y[i], y[j]);
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
            a[i].x = coe[i];
        for (int i = 0; i < v.size; i++)
            b[i].x = v.coe[i];
        fft(a, len, 1), fft(b, len, 1);
        for (int i = 0; i < len; i++)
            a[i] = a[i] * b[i];
        fft(a, len, -1);
        poly tem(0);
        for (int i = 0; i < len; i++)
        {
            int te = int(a[i].x + 0.5);
            tem.coe.push_back(te);
        }
        while (tem.coe.size() > 1 && tem.coe.back() == 0)
            tem.coe.pop_back();
        tem.size = tem.coe.size();
        return tem;
    }
    poly operator+(poly const &y) const
    {
        int len = max(this->coe.size(), y.coe.size());
        poly ans(len);
        for (int i = 0; i < len; i++)
        {
            ans.coe[i] = this->coe[i] + y.coe[i];
        }
        return ans;
    }
    poly operator-(poly const &y) const
    {
        int len = max(this->coe.size(), y.coe.size());
        poly ans(len);
        for (int i = 0; i < len; i++)
        {
            ans.coe[i] = this->coe[i] - y.coe[i];
        }
        return ans;
    }
    pair<poly, poly> div(poly const &dividend, poly const &divisor)
    {

    }
};
const int N=1e5+10;
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n)
    for(int i=0;i<n;i++)cin>>a[i];
    poly x(N),y(N);
    for(int i=0;i<n;i++)
    {
        x.coe[a[i]]++,y.coe[a[i]]++;
    }
    x=x*y;
    vector<int> f(2*N);
    for(int i=1;i<x.coe.size();i++)f[i]=x[i]/2;
    for(int i=2;i<coe.size();i++)f[i]+=f[i-1];
    i64 sum1=n*(n-1)*(n-2)/6,sum2=sum1;
    for(int i=0;i<n;i++)
    {
        sum2-=f[a[i]];
    }
    cout<<1.0*sum2/sum1<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    while(t--)
    {
        solve();
    }
    return 0;
}