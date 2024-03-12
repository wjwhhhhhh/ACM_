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
    int n, m;
    cin >> n >> m;
    vector<int> has;
    has.push_back(1), has.push_back(m);
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++)
    {
        cin >> l[i] >> r[i];
        has.push_back(l[i]);
        if (r[i] + 1 <= m)
            has.push_back(r[i] + 1);
    }
    sort(has.begin(), has.end());
    has.erase(unique(has.begin(), has.end()), has.end());
    int idx = 0;
    map<int, int> mp;
    for (auto c : has)
        mp[c] = idx++;
    vector<int> w(has.size());
    for (int i = 0; i < n; i++)
    {
        w[mp[l[i]]]++;
        if (r[i] + 1 <= m)
        {
            w[mp[r[i] + 1]]--;
        }
    }
    for (int i = 1; i < has.size(); i++)
    {
        w[i] += w[i - 1];
    }
    int ma = max_element(w.begin(), w.end()) - w.begin();
    fill(w.begin(), w.end(), 0);
    for (int i = 0; i < n; i++)
    {
        if (mp[l[i]] <= ma && (r[i] == m || mp[r[i] + 1] > ma))
        {
            w[mp[l[i]]]++;
            if (r[i] + 1 <= m)
                w[mp[r[i] + 1]]--;
        }
    }
    for (int i = 1; i < has.size(); i++)
    {
        w[i] += w[i - 1];
    }
    ma = *max_element(w.begin(), w.end()) - *min_element(w.begin(), w.end());
    cout << ma << endl;
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