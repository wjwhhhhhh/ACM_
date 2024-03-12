#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
const double PI = acos(-1);
const double eps = 1e-4;
template <class T> void chkmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
}
template <class T> void chkmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
}
template <class T> struct Point
{
    T x;
    T y;
    Point(T x_ = 0, T y_ = 0) : x(x_), y(y_)
    {
    }

    template <class U> operator Point<U>()
    {
        return Point<U>(U(x), U(y));
    }
    Point &operator+=(Point p) &
    {
        x += p.x;
        y += p.y;
        return *this;
    }
    Point &operator-=(Point p) &
    {
        x -= p.x;
        y -= p.y;
        return *this;
    }
    Point &operator*=(T v) &
    {
        x *= v;
        y *= v;
        return *this;
    }
    Point operator-() const
    {
        return Point(-x, -y);
    }
    friend Point operator+(Point a, Point b)
    {
        return a += b;
    }
    friend Point operator-(Point a, Point b)
    {
        return a -= b;
    }
    friend Point operator*(Point a, T b)
    {
        return a *= b;
    }
    friend Point operator*(T a, Point b)
    {
        return b *= a;
    }
    friend bool operator==(Point a, Point b)
    {
        return a.x == b.x && a.y == b.y;
    }
    friend std::istream &operator>>(std::istream &is, Point &p)
    {
        return is >> p.x >> p.y;
    }
    friend std::ostream &operator<<(std::ostream &os, Point p)
    {
        return os << "(" << p.x << ", " << p.y << ")";
    }
};

template <class T> T dot(Point<T> a, Point<T> b)
{
    return a.x * b.x + a.y * b.y;
}

template <class T> T cross(Point<T> a, Point<T> b)
{
    return a.x * b.y - a.y * b.x;
}

template <class T> T square(Point<T> p)
{
    return dot(p, p);
}

template <class T> double length(Point<T> p)
{
    return std::sqrt(double(square(p)));
}

long double length(Point<long double> p)
{
    return std::sqrt(square(p));
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    Point<double> a[3];
    for (int i = 0; i < 3; i++)
        cin >> a[i];
    double r = dot(a[1] - a[0], a[2] - a[0]) / length(a[1] - a[0]) / length(a[2] - a[0]);
    r = sqrt(1 - r * r);
    r = length(a[1] - a[2]) / r / 2.0;
    // cout << r << endl;
    double a1 = length(a[0] - a[1]), a2 = length(a[1] - a[2]), a3 = length(a[2] - a[0]);
    // cout << a1 << ' ' << a2 << " " << a3 << endl;
    double b1 = acos((2 * r * r - a1 * a1) / (2 * r * r)), b2 = acos((2 * r * r - a2 * a2) / (2 * r * r)),
           b3 = acos((2 * r * r - a3 * a3) / (2 * r * r));
    auto check = [&](double a) { return fabs(a - (int)a) < eps; };
    for (int i = 4; i <= 4; i++)
    {
        // dug(i);
        double in = 2.0 * PI / i, c1 = b1 / in, c2 = b2 / in, c3 = b3 / in;
        if (!check(c1) || !check(c2) || !check(c3))
            continue;
        cout << r * r * sin(in) * i / 2 << endl;
        return 0;
    }
    return 0;
}