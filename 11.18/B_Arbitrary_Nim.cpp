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
    int n;
    cin >> n;
    vector<int> a(n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        ans ^= a[i];
    }
    if (ans)
    {
        cout << "-1" << endl;
        return 0;
    }
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
        mp[a[i]].push_back(a[i]);
    }
    vector<int> all;
    for (auto [x, cnt] : mp)
    {
        if (cnt.size() & 1)
            all.push_back(x);
    }
    if (all.size() == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << *max_element(all.begin(), all.end()) - 1 << endl;
    }
    return 0;
}