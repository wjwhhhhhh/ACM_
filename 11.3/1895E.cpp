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
using P = pair<int, int>;
void solve()
{
    int n;
    cin >> n;
    vector<P> a(n);
    fir(i, 0, n) cin >> a[i].first;
    fir(i, 0, n) cin >> a[i].second;
    int m;
    cin >> m;
    vector<P> b(m);
    fir(i, 0, m) cin >> b[i].first;
    fir(i, 0, m) cin >> b[i].second;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int> la(n), lb(m);
    la[n - 1] = n - 1, lb[m - 1] = m - 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i].second > a[la[i + 1]].second)
            la[i] = i;
        else
            la[i] = la[i + 1];
    }
    for (int i = m - 2; i >= 0; i--)
    {
        if (b[i].second > b[lb[i + 1]].second)
            lb[i] = i;
        else
            lb[i] = lb[i + 1];
    }
    vector<vector<int>> ed(n + m);
    vector<int> du(n + m);
    for (int i = 0; i < n; i++)
    {
        auto it = upper_bound(b.begin(), b.end(), P{a[i].second, 1e8}) - b.begin();
        // if (i == 2)
        //     cout << b[it].first<<" " << endl;
        if (it == b.size())
            continue;
        ed[n + lb[it]].push_back(i);
        // cout << n + lb[it] << " " << i << endl;
        du[i]++;
    }
    for (int i = 0; i < m; i++)
    {
        auto it = upper_bound(a.begin(), a.end(), P{b[i].second, 1e8}) - a.begin();
        if (it == a.size())
            continue;
        ed[la[it]].push_back(i + n);
        du[i + n]++;
    }
    queue<int> q;
    array<int, 3> ans;
    fill(ans.begin(), ans.end(), 0);
    vector<int> cnt(n + m, 1);
    for (int i = 0; i < n + m; i++)
    {
        if (du[i] == 0)
        {
            if (i < n)
                cnt[i] = 2;
            else
                cnt[i] = 0;
            q.push(i);
        }
    }
    while (q.size())
    {
        int x = q.front();
        q.pop();
        for (auto c : ed[x])
        {
            du[c]--;
            if (du[c] == 0)
            {
                cnt[c] = cnt[x];
                q.push(c);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (cnt[i] == 1)
        {
            // cout << a[i].first << " " << a[i].second << endl;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        ans[i] = count(cnt.begin(), cnt.begin() + n, 2 - i);
        cout << ans[i] << " ";
    }
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