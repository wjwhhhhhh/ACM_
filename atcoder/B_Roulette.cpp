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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin >> n;
    map<int, vector<int>> mp;
    vector<int> ci(n);
    for (int i = 0; i < n; i++)
    {
        int tem;
        cin >> tem;
        ci[i] = tem;
        for (int j = 0; j < tem; j++)
        {
            int a;
            cin >> a;
            mp[a].push_back(i);
        }
    }
    int x;
    cin >> x;
    map<int, vector<int>> has;
    if (mp[x].size() == 0)
    {
        cout << "0" << endl;
        return 0;
    }
    for (auto ch : mp[x])
    {
        has[ci[ch]].push_back(ch + 1);
    }
    cout << has.begin()->second.size() << endl;
    for (auto ch : has.begin()->second)
        cout << ch << " ";
    return 0;
}