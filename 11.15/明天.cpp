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

string a = "tomorrow";
set<string> has;
void solve()
{
    string aa;
    cin >> aa;
    if (aa == a)
        cout << "no" << endl;
    else
        cout << (has.find(aa) != has.end() ? "yes" : "no") << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int t;
    cin >> t;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = i; j < a.size(); j++)
        {
            has.insert(a.substr(i, j - i + 1));
        }
    }
    while (t--)
    {
        solve();
    }
    return 0;
}