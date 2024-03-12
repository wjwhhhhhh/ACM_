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
    int n;
    cin >> n;
    int tem = n;
    set<int> has;
    for (int i = 2; i <= n / i; i++)
    {
        while (n % i == 0)
        {
            has.insert(i);
            n /= i;
        }
    }
    if (n != tem && n != 1)
    {
        has.insert(n);
    }
    cout << (has.size() >= 2 ? "Yes" : "No") << endl;
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