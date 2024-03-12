#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
template <class T> bool chmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
    return a == b;
}
template <class T> bool chmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
    return a == b;
}
struct Point
{
    double _x, _y;
    Point(double x = 0.0, double y = 0.0) : _x(x), _y(y)
    {
    }
};
double dis(Point x, Point y)
{
    return sqrt((x._x - y._x) * (x._x - y._x) + (x._y - y._y) * (x._y - y._y));
}
bool parallel(Point x, Point y) // 平行
{
    return (x._x * y._y) == (x._y * y._x);
}
bool vertical(Point x, Point y) // 垂直
{
    return (x._x * y._y) + (x._y * y._x) == 0;
}
struct line
{
    Point _x, _y;
    line(Point x, Point y)
    {
        _x = x;
        _y = Point(y._x - x._x, y._y - x._y);
    }
    bool inter(line x, line y, Point &ans)
    {
        if (parallel(x._y, y._y))
            return false;
    }
};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;

    return 0;
}