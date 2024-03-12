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
    string a;
    cin >> a;
    vector<int> v(n - 1);
    queue<int> q;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] == 'A' && a[i + 1] == 'B')
        {
            q.push(i);
            v[i] = true;
        }
    }
    int ans = 0;
    while (q.size())
    {
        int x = q.front();
        q.pop();
        ans++;
        swap(a[x], a[x + 1]);
        if (x > 0)
        {
            if (a[x - 1] == 'A' && a[x] == 'B' && !v[x - 1])
            {
                v[x - 1] = true;
                q.push(x - 1);
            }
        }
        if (x + 1 < n - 1)
        {
            if (a[x + 1] == 'A' && a[x + 2] == 'B' && !v[x + 1])
            {
                v[x + 1] = true;
                q.push(x + 1);
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