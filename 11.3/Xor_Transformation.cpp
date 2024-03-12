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
i64 solve(i64 x, i64 y)
{
    return x ^ y;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    i64 x, y;
    cin >> x >> y;
    vector<i64> ans;
    if (__lg(x) == __lg(y))
        ans.push_back(solve(x, y));
    else
    {
        i64 tem = 0;
        for (int i = 0; i < 63; i++)
        {
            if ((x >> i) > 0)
                tem += 1ll << i;
        }
        ans.push_back(solve(x, tem));
        i64 ing = tem;
        tem = 0;
        for (int i = 0; i < 63; i++)
        {
            if ((y >> i) > 0)
                tem += 1ll << i;
        }
        ans.push_back(solve(ing, tem));
        ing ^= ans.back();
        ans.push_back(ing ^ y);
    }
    cout << ans.size() << endl;
    for (auto c : ans)
    {
        assert(x > c);
        cout << c << ' ';
        x ^= c;
    }
    assert(x == y);
    return 0;
}