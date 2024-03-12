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
vector<i64> fac(25);
int C(int n, int m) // 在n里选m
{
    if (n < m || m < 0)
        return 0;
    return (fac[n] / fac[m]) / fac[n - m];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    fac[0] = 1;
    for (int i = 1; i < 25; i++)
        fac[i] = i * fac[i - 1];
    i64 ans = 0;
    int k;
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        ans += C(k - 1, i - 1);
    }
    cout << ans << endl;
    return 0;
}