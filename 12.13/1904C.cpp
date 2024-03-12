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
    int n, k;
    cin >> n >> k;
    vector<i64> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (k >= 3)
    {
        cout << "0" << endl;
        return;
    }
    vector<i64> has;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            has.push_back(abs(a[i] - a[j]));
        }
    i64 ans = *min_element(a.begin(), a.end());
    if (k == 1)
    {
        chmin(ans, *min_element(has.begin(), has.end()));
        cout << ans << endl;
        return;
    }
    function<void(int, int)> dfs = [&](int l, int r) {

    };
    chmin(ans, *min_element(has.begin(), has.end()));
    sort(has.begin(), has.end());
    for (int i = 0; i < n; i++)
    {
        int l = 0, r = has.size() - 1;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (has[mid] <= a[i])
                l = mid;
            else
                r = mid - 1;
        }
        chmin(ans, abs(has[l] - a[i]));
        if (l + 1 < has.size())
        {
            chmin(ans, abs(has[l + 1] - a[i]));
        }
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