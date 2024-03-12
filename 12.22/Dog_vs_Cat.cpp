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
    int siz = (n + 1) / 2;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (n == 2 && a[0] != a[1])
    {
        if (abs(a[0] - a[1]) >= 2)
        {
            cout << "Dog" << '\n';
            return;
        }
    }
    if (count(a.begin(), a.end(), 0) >= siz)
    {
        cout << "Dog" << '\n';
        return;
    }
    i64 all = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
            siz--;
        else
            all += a[i] - 1;
    }
    all += siz;
    if (all & 1)
        cout << "Dog" << '\n';
    else
        cout << "Cat" << '\n';
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