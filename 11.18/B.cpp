#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
#define fir(a, b, c) for (int a = b; a < c; a++)
using namespace std;
using i64 = long long;
using two = array<int, 2>;
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
    int n;
    cin >> n;
    int res = 0;
    int fl = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (res & 1 && res > 0)
            fl = 1;
        else if (res & 1 && res < 0)
            fl = -1;
        res /= 2;
        res += a;
        if (res == 0)
        {
            if (fl == 0)
                cout << "0";
            else if (fl > 0)
                cout << "+";
            else
                cout << "-";
        }
        else if (res < 0)
        {
            cout << "-";
        }
        else
            cout << "+";
    }
    return 0;
}