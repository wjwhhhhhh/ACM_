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
const int N = 16;
i64 get(int x, int y)
{
    vector<int> val(y);
    if (y == 0)
        return -1;
    if (x > y * 9)
        return -1;
    if (x == 0)
    {
        return 1;
    }
    if (y == 1)
    {
        return x + 1;
    }
    if (1 + 9 * (y - 1) >= x)
    {
        vector<int> val(y);
        x--;
        val[0] = 1;
        for (int i = y - 1; i > 0; i--)
        {
            int v = min(9, x);
            val[i] = v;
            x -= v;
        }
        i64 ing = 0;
        for (auto c : val)
        {
            ing = ing * 10 + c;
        }
        return ing + 1;
    }
    else
    {
        for (int i = y - 1; i >= 0; i--)
        {
            int v = min(9, x);
            val[i] = v;
            x -= v;
        }
        i64 ing = 0;
        for (auto c : val)
        {
            ing = ing * 10 + c;
        }
        return ing + 1;
    }
}
void solve()
{
    int x, y;
    cin >> x >> y;
    i64 ans = get(x, y);
    i64 tem = get(x, y - 1);
    if (tem != -1 && to_string(tem).size() == y)
    {
        chmin(ans, tem);
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