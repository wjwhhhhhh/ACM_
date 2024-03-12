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
const int N = 1e6;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    i64 all = 0;
    for (int i = 1; i <= N; i++)
    {
        i64 res = 0;
        for (int j = 1; j <= i / j; j++)
        {
            if (i % j == 0)
                res += 2;
        }
        chmax(all, res);
        // if (chmax(all, res))
        // {
        //     cout << i << '\n';
        // }
    }
    cout << all << '\n';
    return 0;
}