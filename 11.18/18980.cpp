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
    int n, k;
    cin >> n >> k;
    string a;
    cin >> a;
    if (count(a.begin(), a.end(), 'B') == k)
    {
        cout << "0" << endl;
        return;
    }
    for (int i = 1; i <= a.size(); i++)
    {
        if (i + count(a.begin() + i, a.end(), 'B') == k)
        {
            cout << 1 << endl;
            cout << i << " "
                 << "B" << endl;
            return;
        }
        if (count(a.begin() + i, a.end(), 'B') == k)
        {
            cout << 1 << endl;
            cout << i << " "
                 << "A" << endl;
            return;
        }
    }
    cout << 2 << endl;
    cout << a.size() << " "
         << "A" << endl;
    cout << k << " "
         << "B" << endl;
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