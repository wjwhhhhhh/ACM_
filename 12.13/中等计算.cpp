#pragma GCC optimize(3, "Ofast", "inline")
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    i64 ans = 0;
    for (auto c : a)
        ans ^= c;
    vector<int> val(n + 1, 0);
    for (int i = 1; i <= n; i++)
        val[i] = val[i - 1] ^ i;
    for (int i = 1; i <= n; i++)
    {

        int l = 0;
        for (; l + i - 1 <= n; l += i)
        {
            ans ^= val[i - 1];
        }
        for (; l <= n; l++)
        {
            ans ^= l % i;
        }
    }
    cout << ans << endl;
    return 0;
}