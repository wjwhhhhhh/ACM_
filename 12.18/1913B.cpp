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
    string a;
    cin >> a;
    int x[2];
    x[1] = count(a.begin(), a.end(), '0');
    x[0] = count(a.begin(), a.end(), '1');
    for (int i = 0; i < a.size(); i++)
    {
        if (x[a[i] - '0'] == 0)
        {
            cout << a.size() - i << '\n';
            return;
        }
        x[a[i] - '0']--;
    }
    cout << "0\n";
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