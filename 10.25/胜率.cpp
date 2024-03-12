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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    double a;
    cin >> a;
    a *= 100;
    auto check = [&](int x) {
        int l = 0, r = x;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            // cout << (int)round(10000.0 * mid / x);
            if (round(10000.0 * mid / x) <= a)
                l = mid;
            else
                r = mid - 1;
        }
        return a == round(10000.0 * l / x);
    };
    // if (check(7))
    // {
    //     cout << "ok";
    // }
    for (int i = 1; i <= 10000; i++)
    {
        if (check(i))
        {
            cout << i << endl;
            return 0;
        }
    }
}