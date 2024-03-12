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
const int M = 998244353;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> f(n + 1);
    f[0] = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
            continue;
        for (int j = n; j >= a[i]; j--)
        {
            f[j] += f[j - a[i]];
            f[j] %= M;
        }
    }
    for (int i = n; i >= 0; i--)
    {
        if (f[i] != 0)
        {
            cout << i << " " << f[i] << endl;
            return 0;
        }
    }
    return 0;
}