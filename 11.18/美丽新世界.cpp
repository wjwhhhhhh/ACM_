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
int M;
template <class T> T qmi(T k, long long p = M - 2, long long P = M)
{
    T res = 1;
    while (p)
    {
        if (p & 1)
            res = 1ll * res * k % P;
        k = 1ll * k * k % P;
        p >>= 1;
    }
    return res % P;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    array<int, 5> f;
    for (int i = 0; i < 5; i++)
        cin >> f[i];
    vector<i64> a(f[4] + 1);
    a[1] = f[0], a[2] = f[1];
    int p = f[2], A = f[3], n = f[4];
    M = p;
    for (int i = 3; i <= n; i++)
        a[i] = __lg(qmi(a[i - 1], a[i - 2]) + 1) + A;
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    return 0;
}