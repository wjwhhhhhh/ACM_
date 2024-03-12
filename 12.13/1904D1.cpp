#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
#define fir(a, b, c) for (int a = b; a < c; a++)
using namespace std;
using i64 = long long;
using two = array<i64, 2>;
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
int dx[4] = {1, 1, -1, -1};
int dy[4] = {1, -1, -1, 1};
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    vector<int> o(n);
    iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](int x, int y) { return b[x] < b[y]; });
    for (int i = 0; i < n; i++)
    {
        int id = o[i];
        if (b[id] == a[id])
            continue;
        if (b[id] < a[id])
        {
            cout << "NO" << endl;
            return;
        }
        bool fl = false;
        int l = id, r = id + 1;
        while (l >= 0 && a[l] != b[id])
        {
            if (a[l] > b[id])
                break;
            if (b[l] < b[id])
                break;
            l--;
        }
        while (r < n && a[r] != b[id])
        {
            if (a[r] > b[id])
                break;
            if (b[r] < b[id])
                break;
            r++;
        }
        // cout << l << " " << r << " " << id << endl;
        if (l >= 0 && a[l] == b[id])
            fl = true;
        if (r < n && a[r] == b[id])
            fl = true;
        if (!fl)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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