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
void solve()
{
    string a;
    cin >> a;
    i64 ing = 0;
    i64 siz;
    cin >> siz;
    int n = a.size();
    vector<int> id, cg;
    set<int> has;
    cg.push_back(0);
    for (int i = 1; i < n; i++)
    {
        while (cg.size() && a[i] < a[cg.back()])
        {
            id.push_back(cg.back());
            cg.pop_back();
        }
        cg.push_back(i);
    }
    while (cg.size())
    {
        id.push_back(cg.back());
        cg.pop_back();
    }
    reverse(id.begin(), id.end());
    set<int> vg;
    for (int i = n; i; i--)
    {
        if (siz <= i)
        {
            string need;
            for (int j = 0; j < n; j++)
            {
                if (vg.find(j) == vg.end())
                {
                    need += a[j];
                }
            }
            cout << need[siz - 1];
            return;
        }
        siz -= i;
        vg.insert(id.back());
        id.pop_back();
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