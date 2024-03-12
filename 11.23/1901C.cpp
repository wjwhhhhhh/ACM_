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
    fir(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());
    array<int, 2> cnt{a[0], a.back()};
    vector<int> ans;
    int si = 0;
    while (cnt[0] != cnt[1])
    {
        if ((cnt[1] - cnt[0]) % 2 == 0)
            ans.push_back(0);
        else if (cnt[1] & 1)
            ans.push_back(0);
        else
            ans.push_back(1);
        cnt[0] = (cnt[0] + ans.back()) / 2;
        cnt[1] = (cnt[1] + ans.back()) / 2;
        si++;
    }
    cout << si << '\n';
    if (ans.size() <= n)
    {
        for (auto c : ans)
            cout << c << " ";
        cout << '\n';
    }
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