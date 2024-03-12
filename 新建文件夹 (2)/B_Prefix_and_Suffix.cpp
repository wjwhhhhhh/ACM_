#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
template <class T> void chmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
}
template <class T> void chmin(T &a, T b)
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
    string a, b;
    cin >> a >> b;
    if (a == b.substr(0, n) && a == b.substr(m - n, n))
        cout << 0;
    else if (a == b.substr(0, n))
        cout << 1;
    else if (a == b.substr(m - n, n))
        cout << 2;
    else
        cout << 3;
    return 0;
}