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
bool find(string a, string b)
{
    for (int i = 0; i + b.size() - 1 < a.size(); i++)
    {
        if (a.substr(i, b.size()) == b)
            return true;
    }
    return false;
}
void solve()
{
    int n;
    cin >> n;
    string a;
    cin >> a;
    int si = 0;
    for (auto c : a)
    {
        si += (c == '1');
    }
    if (si & 1)
    {
        cout << "-1" << endl;
        return;
    }
    if (si == 2)
    {
        if (a.size() == 2)
        {
            cout << "-1" << endl;
        }
        else if (find(a, "11"))
        {
            cout << 2 << endl;
        }
        else
        {
            cout << si / 2 << endl;
        }
        return;
    }
    cout << si / 2 << endl;
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