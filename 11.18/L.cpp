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
    vector<int> a(n), b(n), cnt(n);
    for (int i = 0; i < n; i++)
        cin >> a[i], a[i]--;
    for (int i = 0; i < n; i++)
        cin >> b[i], b[i]--;
    for (int i = 0; i < n; i++)
        cnt[b[i]] = i;
    deque<int> de;
    for (int i = 0; i < n; i++)
    {
        de.push_back(cnt[a[i]]);
    }
    vector<int> ans;
    for (int i = 1; i < n; i++)
    {
        while (de.front() != i)
        {
            ans.push_back(1);
            de.push_back(de.front());
            de.pop_front();
        }
        de.pop_front();
        while (de.front() != (i - 1))
        {
            ans.push_back(2);
            de.push_back(de.front());
            de.pop_front();
        }
        de.pop_front();
        ans.push_back(2);
        de.push_back(i - 1);
        ans.push_back(1);
        de.push_back(i);
    }
    for (auto c : ans)
        cout << c;
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