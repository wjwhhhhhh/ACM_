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
    int a[5];
    for (int i = 0; i < 5; i++)
        cin >> a[i];
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        int b;
        cin >> b;
        sum += b * a[i];
    }
    if (sum > a[4])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}