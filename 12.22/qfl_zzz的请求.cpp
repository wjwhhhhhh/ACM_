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
    vector<int> a[2];
    for (int i = 0; i < n; i++)
    {
        int tem;
        cin >> tem;
        if (tem % 2 == 0)
        {
            a[0].push_back(tem);
        }
        else
            a[1].push_back(tem);
    }
    sort(a[0].begin(), a[0].end());
    sort(a[1].begin(), a[1].end());

    if (a[0].size() == 0 || a[1].size() == 0)
    {
        cout << "-1" << endl;
        return 0;
    }
    cout << max({a[0][0] * a[1][0], a[0][0] * a[1].back(), a[0].back() * a[1][0], a[0].back() * a[1].back()});
    return 0;
}