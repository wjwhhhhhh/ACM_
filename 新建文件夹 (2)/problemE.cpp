#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
template <class T> void chmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
}
template <class T> void chmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
}
void solve()
{
    int n, m;
    cin >> n >> m;
    std::vector<int> a(n);
    std::iota(a.begin(), a.end(), 1);
    do
    {
        int sum = 0;
        for (int i = 0; i < m; i++)
            sum += a[i];
        bool fl = true;
        int res = sum;
        for (int i = m; i < n; i++)
        {
            sum -= a[i - m];
            sum += a[i];
            if (sum % 2 != res % 2)
                fl = false;
        }
        if (fl)
        {
            cout << "Yes" << endl;
            return;
        }
    } while (std::next_permutation(a.begin(), a.end()));
    cout << "No" << endl;
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