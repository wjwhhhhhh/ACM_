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
    i64 n;
    cin >> n;
    if (n == 1)
    {
        cout << "-1" << endl;
        return 0;
    }
    map<i64, int> mp;
    i64 sum = 0;
    for (i64 i = 2; i <= n / i; i++)
    {
        while (n % i == 0)
        {
            mp[i]++;
            sum++;
            n /= i;
        }
    }
    if (n != 1)
    {
        sum++;
        mp[n]++;
    }
    int res = 0;
    for (auto [x, c] : mp)
        chmax(res, c);
    if (res > sum - res + 1)
    {
        cout << "-1" << endl;
        return 0;
    }
    vector<int> ans;
    while (sum--)
    {
        int id = 0;
        for (auto [x, y] : mp)
        {
            if (ans.size() != 0 && x == ans.back())
                continue;
            if (mp[id] < y)
                id = x;
        }
        ans.push_back(id);
        mp[id]--;
    }
    cout << ans.size() << endl;
    for (auto c : ans)
        cout << c << " ";
    return 0;
}