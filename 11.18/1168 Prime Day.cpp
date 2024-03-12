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
bool is(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i <= n / i; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin >> n;
    bool fl = true;
    string a = to_string(n);
    while (a.size() != 8)
    {
        a = "0" + a;
    }
    for (int i = 8; i > 0; i--)
    {
        n %= (int)pow(10, i);
        cout << a << " ";
        a = a.substr(1);
        if (is(n))
            cout << "Yes" << endl;
        else
            cout << "No" << endl, fl = false;
    }
    if (fl)
        cout << "All Prime!" << endl;
    return 0;
}