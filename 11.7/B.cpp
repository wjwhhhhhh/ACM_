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
const i64 M = 1e18, N = 4e4, MM = 1e9;
int f(i64 &x)
{
    return __builtin_popcountll(x);
}
unordered_map<i64, vector<int>> mp;
unordered_map<i64, i64> mmp;
void solve()
{
    i64 t;
    cin >> t;
    if (mp.find(t) != mp.end())
    {
        cout << mmp[t] << " " << mp[t].size() << '\n';
        for (auto c : mp[t])
            cout << c << " ";
        cout << '\n';
        return ;
    }
    i64 ans = 1;
    vector<int> has;
    for (int i = 2; i < t; i++)
    {
        i64 res = 0;
        i64 tem = t;
        int si = 0;
        while (tem)
        {
            if (tem % i == 0)
                res++;
            tem /= i;
            si++;
        }
        if (ans == res)
        {
            has.push_back(i);
        }
        else if (chmax(ans, res))
        {
            has.clear();
            has.push_back(i);
        }
        if (si < ans)
            break;
    }
    if (ans == 1)
    {
        has.push_back(t);
    }
    cout << ans << " " << has.size() << '\n';
    for (auto c : has)
        cout << c << " ";
    cout << '\n';
    mmp[t] = ans;
    mp[t] = has;
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