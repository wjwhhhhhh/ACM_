#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
template <class T> void chkmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
}
template <class T> void chkmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
}
void solve()
{
    int n;
    cin >> n;
    int a = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        int ing;
        cin >> ing;
        if (ing == 1)
            a++;
        else if (ing == 2)
            b++;
        else if (ing == 3)
            a++, b++;
        else
            a--, b--;
    }
    if (a > b)
        cout << "Kobayashi" << endl;
    else if (a == b)
        cout << "Draw" << endl;
    else
        cout << "Tohru" << endl;
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