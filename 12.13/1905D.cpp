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
void solve()
{
    int n;
    cin >> n;
    deque<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    while (a.back() != 0)
    {
        a.push_front(a.back());
        a.pop_back();
    }
    set<int> has;
    i64 ans = n, idx = 0, sum = 0;
    deque<pair<int, i64>> q;
    auto get = [&](int x, int y) { return (x - y + n) % n; };
    for (int i = 0; i < n - 1; i++)
    {
        while (q.size() && a[q.back().first] > a[i])
        {
            q.pop_back();
        }
        if (q.size() == 0)
        {
            q.push_back({i, 1ll * a[i] * (i + 1)});
        }
        else
        {
            q.push_back({i, 1ll * a[i] * get(i, q.back().first) + q.back().second});
            // cout<<
        }
        // cout << n + q.back().second << endl;
        chmax(ans, n + q.back().second);
    }
    cout << ans << endl;
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