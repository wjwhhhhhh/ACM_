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
    string a;
    cin >> a;
    bool fl = false;
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i - 1] == 'X' && a[i] == 'X')
            fl = true;
    }
    if (fl)
        cout << n << endl;
    else
    {
        cout << count(a.begin(), a.end(), 'X') << endl;
    }
    return 0;
}