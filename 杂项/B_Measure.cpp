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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int t;
    cin >> t;
    for (int i = 0; i <= t; i++)
    {
        char tr = '-';
        for (int j = 9; j >= 1; j--)
        {
            if (t % j == 0 && i % (t / j) == 0)
                tr = j + '0';
        }
        cout << tr;
    }
    return 0;
}