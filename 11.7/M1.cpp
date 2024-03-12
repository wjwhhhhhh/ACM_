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
string th = "RSP";
void solve()
{
    string a;
    cin >> a;
    vector<int> w(a.size());
    for (int i = 0; i < a.size(); i++)
    {
        w[i] = find(th.begin(), th.end(), a[i]) - th.begin();
        // cout << w[i] << endl;
    }
    stack<int> all;
    for (int i = 0; i < a.size(); i++)
    {
        while (all.size() && (w[i] - all.top() + 3) % 3 == 2)
            all.pop();
        all.push(w[i]);
    }
    int ans;
    while (all.size())
    {
        ans = all.top();
        all.pop();
    }
    cout << th[ans] << endl;
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