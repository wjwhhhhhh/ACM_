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
    vector<int> has;
    int ing = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (a[i] > a[i - 1] && a[i] > a[i + 1])
        {
            has.push_back(i);
        }
    }
    int ans = 0;
    for (int i = 1; i < has.size(); i++)
    {
        if (has[i] - has[i - 1] == 2)
        {
            a[has[i] - 1] = max(a[has[i]], a[has[i - 1]]);
            ans++;
            i++;
        }
    }
    vector<int> in(1, a[0]);
    for (int i = 1; i < n - 1; i++)
    {
        if (a[i] > a[i - 1] && a[i] > a[i + 1])
        {
            a[i] = max(a[i - 1], a[i + 1]);
            ans++;
        }
        in.push_back(a[i]);
    }
    in.push_back(a.back());
    cout << ans << endl;
    for (auto c : in)
        cout << c << " ";
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