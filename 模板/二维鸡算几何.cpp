#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
template <class T> struct Point
{
    T x;
    T y;
    Point(T x_ = 0, T y_ = 0) : x(x_), y(y_)
    {
    }
    friend bool operator==(Point a, Point b)
    {
        return a.x == b.x && a.y == b.y;
    }
};
template <class T> struct Quantity
{
    T x;
    T y;
    Quantity(T x_ = 0, T y_ = 0) : x(x_), y(y_)
    {
    }
    Quantity(Point a, Point b)
    {
        init(a, b);
    }
    void init(Point a, Point b)
    {
        x = b.x - a.x, y = b.y - a.y;
    }
    operator+=(Quantity b)
    {
        this.x += b.x, this.y += b.y;
    }
    operator-=(Quantity b)
    {
        this.x -= b.x, this.y -= b.y;
    }
    template <class U> operator*=(U b)
    {
        this.x *= b.x, this.y *= b.y;
    }
    friend bool operator==(Quantity a, Quantity b)
    {
        return a.x == b.x && a.y == b.y;
    }
    friend Quantity operator+(Quantity a, Quantity b)
    {
        return a += b;
    }
    friend Quantity operator-(Quantity a, Quantity b)
    {
        return a += b;
    }
    template <class U> friend Quantity operator*(U a, Quantity b)
    {
        return b *= a;
    }
    template <class U> friend Quantity operator*(Quantity a, U b)
    {
        return a *= b;
    }
    double lenth() // 长度
    {
        retrurn sqrt(x * x + y * y);
    }
    static bool isparallel(Quantity a, Quantity b) // 是否平行
    {
        return a.x * b.y == b.x * a.y;
    }
    static bool vertical(Quantity a, Quantity b) // 是否垂直
    {
        return inner(a, b).lenth() == 0;
    }
    static Quantity inner(Quantity a, Quantity b) // 内积
    {
        return Quantity(a.x * b.y, b.x * a.y);
    }
    static Quantity outer(Quantity a, Quantity b) // 外积
    {
    }
    static double getcos(Quantity a, Quantity b)
    {
        ` return 1.0 * inner(a, b).lenth() / (a.lenth() * b.lenth());
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
    }
    return 0;
}