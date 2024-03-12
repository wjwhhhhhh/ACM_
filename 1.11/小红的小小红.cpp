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
    string a;
    cin >> a;
    string ans = "xiaohong";
    map<char, int> mp;
    for (auto c : a)
        mp[c]++;
    for (auto c : ans)
        mp[c]--;
    for (auto [x, y] : mp)
    {
        if (y == 0)
            continue;
        ans += string(y, x);
    }
    cout << ans << endl;
    return 0;
}