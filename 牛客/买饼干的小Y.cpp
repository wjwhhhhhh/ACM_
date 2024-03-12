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
    int n, m;
    cin >> n >> m;
    int all = 0;
    n -= m;
    while (m != 1)
    {
        m = (m + 1) / 2;
        n -= m;
        all++;
        if (n <= 0)
            break;
    }
    all += max(n, 0);
    cout << all << endl;
    return 0;
}