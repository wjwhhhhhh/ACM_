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
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (is_sorted(a.begin(), a.end()))
    {
        cout << 0 << '\n';
        return;
    }
    if (a.back() < a[a.size() - 2])
    {
        cout << "-1" << endl;
        return;
    }
    if (a.back() < 0)
    {
        cout << "-1" << endl;
        return;
    }
    cout << n - 2 << '\n';
    for (int i = n - 2; i > 0; i--)
    {
        cout << i << " " << i + 1 << " " << n << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}