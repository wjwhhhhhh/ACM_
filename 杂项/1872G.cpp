#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
template <class T> void chkmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
}
template <class T> void chkmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
}
const int N = 2e9;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int need = 0;
    bool fl = true;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 1)
            fl = false;
    }
    if (fl)
    {
        cout << "1 1" << endl;
        return;
    }
    int l = -1, r = n;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
            need++;
        else
            break;
        l = i;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == 1)
            need++;
        else
            break;
        r = i;
    }
    i64 ing = 1;
    for (int i = l + 1; i < r; i++)
    {
        ing *= a[i];
        if (ing > N)
        {
            cout << l + 1 + 1 << " " << r << endl;
            return;
        }
    }
    vector<int> has;
    for (int i = l + 1; i < r; i++)
    {
        if (a[i] != 1)
            has.push_back(i);
    }
    // cerr << "ok" << endl;
    i64 ans = -1, ansl, ansr;
    vector<int> s(n + 1);
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i - 1];
    for (int i = 0; i < has.size(); i++)
    {
        i64 ing = 1;
        for (int j = i; j >= 0; j--)
        {
            ing *= a[has[j]];
            //cerr << ing << endl;
            if (ing + s[n] - (s[has[i] + 1] - s[has[j]]) > ans)
            {
                ans = ing + s[n] - (s[has[i] + 1] - s[has[j]]);
                ansl = has[j], ansr = has[i];
            }
        }
    }
    cout << ansl + 1 << " " << ansr + 1 << endl;
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