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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> cnt(n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cnt[a[i]] = i;
    }
    for (int i = n; i > 0; i--)
    {
        if (cnt[i] == -1)
            continue;
        if (a.back() == i)
        {
            a.pop_back();
            ans++;
        }
        else
        {
            int mi = 1e9;
            while (a.size() - 1 >= cnt[i])
            {
                chmin(mi, a.back());
                cnt[a.back()] = -1;
                a.pop_back();
            }
            a.push_back(mi);
            cnt[mi] = a.size() - 1;
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