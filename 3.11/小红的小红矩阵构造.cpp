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
    int n, m, x;
    cin >> n >> m >> x;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            x -= a[i][j];
    if (x != 0)
    {
        cout << "wrong answer" << endl;
        return 0;
    }
    set<int> has;
    for (int i = 0; i < n; i++)
    {
        int res = 0;
        for (int j = 0; j < m; j++)
            res ^= a[i][j];
        has.insert(res);
    }
    for (int j = 0; j < m; j++)
    {
        int res = 0;
        for (int i = 0; i < n; i++)
            res ^= a[i][j];
        has.insert(res);
    }
    if (has.size() == 1)
    {
        cout << "accepted" << endl;
    }
    else
        cout << "wrong answer" << endl;
    return 0;
}