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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    i64 ans = 0;
    int back = 2e9;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] <= back)
        {
            back = a[i];
        }
        else
        {
            if (back == 1)
            {
                ans += a[i] - 1;
            }
            else
            {
                int l = 2, r = a[i];
                while (l < r)
                {
                    int mid = l + r >> 1;
                    if ((a[i] + (mid - 1)) / mid <= back)
                        r = mid;
                    else
                        l = mid + 1;
                }
                ans += l - 1;
                back = a[i] / l;
            }
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