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
auto get(string &s)
{
    stringstream a;
    a << s;
    int t;
    a >> t;
    return t;
}
void solve()
{
    string a;
    cin >> a;
    string b;
    for (int i = 0; i < a.size() - 1; i++)
    {
        b += a[i];
        if (b[0] == '0')
            continue;
        string c = a.substr(i + 1);
        if (c[0] == '0')
            continue;
        if (get(b) >= get(c))
            continue;
        cout << get(b) << " " << get(c) << '\n';
        return;
    }
    cout << "-1" << '\n';
    return;
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