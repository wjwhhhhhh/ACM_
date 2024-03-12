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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    vector<int> has;
    for (int i = 0; i < n; i++)
    {
        has.push_back(a[i]);
    }
    sort(has.begin(), has.end());
    has.erase(unique(has.begin(), has.end()), has.end());
    int idx = 0;
    map<int, int> mp;
    for (auto x : has)
        mp[x] = idx++;
    vector<vector<int>> val(n, vector<int>(n));
    vector<vector<int>> w(idx);
    for (int i = 0; i < n; i++)
    {
        w[mp[a[i]]].push_back(b[i]);
    }
    for (int i = 0; i < idx; i++)
        sort(w[i].begin(), w[i].end());
    auto get = [&](int l, int r) {
        if (a[l] > a[r])
            swap(l, r);
        for (int i = mp[a[l]]; i <= mp[a[r]]; i++)
        {
            auto fr = lower_bound(w[i].begin(), w[i].end(), )
        }
    };
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            val[i][j] = val[j][i] = get(i, j);
        }
    return 0;
}