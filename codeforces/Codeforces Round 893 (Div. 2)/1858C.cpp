#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
template <class T> void chkmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
}
template <class T> void chkmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
}
void solve()
{
    int n;
    cin >> n;
    if (n <= 3)
    {
        for (int i = 1; i <= n; i++)
            cout << i << " ";
        cout << endl;
        return;
    }
    int m = n;
    n = n / 2;
    set<int> has;
    vector<int> ans;
    for (int i = 2; i <= n; i++)
    {
        if (has.find(i) != has.end())
            continue;
        i64 ing = i;
        ans.push_back(ing);
        while (ing <= n)
        {
            has.insert(ing);
            ing <<= 1;
            ans.push_back(ing);
        }
    }
    set<int> all;
    for (auto ch : ans)
        all.insert(ch);
    for (int i = 1; i <= m; i++)
    {
        if (all.find(i) == all.end())
            ans.push_back(i);
    }
    for (auto ch : ans)
        cout << ch << " ";
    cout << endl;
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