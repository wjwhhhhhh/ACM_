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
    int n, m;
    cin >> n >> m;
    __int128 sum = 1;
    __int128 tr = pow(n, m);
    for (int i = 0; i <= tr / i; i++)
    {
        if (tr / i == 0)
        {
            sum *= tr;
            if (1ll * i * i != tr)
                sum *= tr / i;
        }
    }
    return 0;
}