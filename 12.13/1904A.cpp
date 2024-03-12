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
int dx[4] = {1, 1, -1, -1};
int dy[4] = {1, -1, -1, 1};
void solve()
{
    int a, b;
    cin >> a >> b;
    int x, y;
    cin >> x >> y;
    set<two> has;
    int ans = 0;
    for (int i = 0; i < 4; i++)
    {
        has.insert(two{x + dx[i] * a, y + dy[i] * b});
        has.insert(two{x + dx[i] * b, y + dy[i] * a});
    }
    cin >> x >> y;
    for (int i = 0; i < 4; i++)
    {
        if (has.find(two{x + dx[i] * a, y + dy[i] * b}) != has.end())
            ans++;
        if (a != b && has.find(two{x + dx[i] * b, y + dy[i] * a}) != has.end())
            ans++;
    }
    cout << ans << endl;
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