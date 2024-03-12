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
    int n, m;
    cin >> n >> m;
    vector<two> all;
    int tx, ty;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;
            // cout << ch << endl;
            if (ch == 'O')
                all.push_back(two{i, j});
            else if (ch == 'W')
                tx = i, ty = j;
        }
    }
    int ans = 1e9;
    for (auto [x, y] : all)
    {
        // cout << tx << " " << ty << endl;
        chmin(ans, abs(x - tx) + abs(y - ty));
    }
    cout << ans << endl;
    return 0;
}