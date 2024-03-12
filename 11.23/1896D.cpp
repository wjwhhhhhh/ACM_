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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    set<int> has;
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    for (int i = 0; i < n; i++)
        if (a[i] == 1)
            has.insert(i);
    while (q--)
    {
        int flag;
        cin >> flag;
        if (flag == 1)
        {
            int x;
            cin >> x;
            if (x > sum)
            {
                cout << "NO\n";
                continue;
            }
            if (a[0] == 1 || a[n - 1] == 1)
            {
                cout << "YES\n";
            }
            else if (has.size() == 0)
            {
                if ((x % 2 == 0))
                    cout << "YES\n";
                else
                    cout << "NO\n";
            }
            else
            {
                int it = *has.begin();
                bool fl = false;
                if (sum - 2 * it >= x)
                    fl = true;
                else if ((x - (sum - 2 * it)) % 2 == 0)
                    fl = true;
                it = *has.rbegin();
                it = n - it - 1;
                if (sum - 2 * it >= x)
                    fl = true;
                else if ((x - (sum - 2 * it)) % 2 == 0)
                    fl = true;
                if (fl)
                    cout << "YES\n";
                else
                    cout << "NO\n";
            }
        }
        else
        {
            int x, y;
            cin >> x >> y;
            x--;
            sum -= a[x];
            if (a[x] == 1)
                has.erase(x);
            a[x] = y;
            sum += a[x];
            if (a[x] == 1)
                has.insert(x);
        }
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