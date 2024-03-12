#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
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
set<string> ja;
void solve()
{
    int n;
    cin >> n;
    vector<string> ans;

    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        if (ja.find(a) != ja.end())
            continue;
        for (int j = 0; j < (int)a.size() - 2; j++)
        {
            if (a.substr(j, 3) == "bie")
            {
                ja.insert(a);
                ans.push_back(a);
                break;
            }
        }
    }
    if (ans.size() == 0)
    {
        cout << "Time to play Genshin Impact, Teacher Rice!" << endl;
    }
    else
    {
        for (auto c : ans)
        {
            cout << c << '\n';
        }
    }
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