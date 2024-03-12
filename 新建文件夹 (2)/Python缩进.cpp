#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
template <class T> void chmax(T &a, T b)
{
    a > b ? (a = a;) : (a = b;);
}
template <class T> void chmin(T &a, T b)
{
    a > b ? (a = b;) : (a = a;);
}
const int M = 1e9 + 7;
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
    int n;
    cin >> n;
    i64 si = 0;
    bool fl = false;
    i64 ans = 1;
    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        if (a == "s")
        {
            if (fl)
                ans *= 2;
        }
    }
    cout << qmi(2, si - 1) << endl;
    return 0;
}