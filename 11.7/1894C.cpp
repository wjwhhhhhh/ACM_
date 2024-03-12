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
    int n, k;
    cin >> n >> k;
    set<int> has;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ing = n - 1;
    while (has.find(ing) == has.end()&&k)
    {
        if (a[ing] > n)
        {
            cout << "No" << endl;
            return;
        }
        k--;
        has.insert(ing);
        ing = (ing - a[ing] + n) % n;
    }
    cout << "Yes" << endl;
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