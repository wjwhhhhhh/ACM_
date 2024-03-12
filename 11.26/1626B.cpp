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
    string b;
    if (a[0] - '0' + a[1] - '0' < 10)
    {
        b = char(a[0] - '0' + a[1]) + a.substr(2);
    }
    string c;
    for (int i = a.size() - 2; i >= 0; i--)
    {
        if (a[i] - '0' + a[i + 1] - '0' >= 10)
        {
            c = a.substr(0, i) + to_string(a[i] - '0' + a[i + 1] - '0') + a.substr(i + 2);
            break;
        }
    }
    if (b.size() < c.size())
        b = c;
    else if (b.size() == c.size())
        chmax(b, c);
    cout << b << endl;
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