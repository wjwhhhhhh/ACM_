#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
#define fir(a, b, c) for (int a = b; a < c; a++)
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
using P2 = array<int, 2>;
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> l(m), r(m);
    for (int i = 0; i < m; i++)
        cin >> l[i] >> r[i];
    if (m == 2)
    {
        cout << n << endl;
        return;
    }
    if (n == 1)
    {
        cout << "0" << endl;
        return;
    }
    vector<int> a(n + 2);
    for (int i = 0; i < m; i++)
    {
        a[l[i]]++;
        a[r[i] + 1]--;
    }
    for (int i = 1; i <= n; i++)
        a[i] += a[i - 1];
    vector<int> has[3];
    i64 xy = 0;
    fir(i, 1, n + 1)
    {
        if (a[i] == 0)
            xy++;
        else if (a[i] <= k)
            has[a[i]].push_back(i);
    }
    vector<int> w(m);
    vector<vector<int>> fr(has[2].size());
    fir(i, 0, m)
    {
        int res = 0;
        auto id = lower_bound(has[1].begin(), has[1].end(), l[i]) - has[1].begin();
        while (id < has[1].size() && has[1][id] <= r[i])
        {
            res++;
            id++;
        }
        w[i] = res;
    }
    fir(i, 0, m)
    {
        auto id = lower_bound(has[2].begin(), has[2].end(), l[i]) - has[2].begin();
        while (id < has[2].size() && has[2][id] <= r[i])
        {
            fr[id].push_back(i);
            id++;
        }
    }
    map<P2, int> mp;
    fir(i, 0, has[2].size())
    {
        if (fr[i][0] > fr[i][1])
            swap(fr[i][0], fr[i][1]);
        mp[P2{fr[i][0], fr[i][1]}]++;
    }
    i64 ans = 0;
    for (auto [cnt, c] : mp)
    {
        chmax(ans, 1ll * w[cnt[0]] + w[cnt[1]] + c);
    }
    sort(w.rbegin(), w.rend());
    chmax(ans, 1ll * w[0] + w[1]);
    cout << ans + xy << endl;
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