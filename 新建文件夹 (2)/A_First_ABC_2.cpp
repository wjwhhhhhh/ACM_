#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
template <class T> void chmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
}
template <class T> void chmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
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
    for (int i = 0; i < a.size() - 2; i++)
    {
        if (a.substr(i, 3) == "ABC")
        {
            cout << i + 1;
            return 0;
        }
    }
    cout << -1;
    return 0;
}