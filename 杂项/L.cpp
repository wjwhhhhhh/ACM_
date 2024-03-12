
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
int n, m;
string tm(1, char('0' - 1));
string work(string a)
{
    string ans = a;
    n = a.size();
    set<int> has;
    for (int i = 0; i < n; i++)
    {
        if (ans[i] == '?')
        {
            has.insert(i);
            ans[i] = '0';
        }
    }
    vector<pair<int, int>> an;
    int xian = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == '?')
        {
            int l = i;
            while (i < n && a[i] == '?')
            {
                i++;
            }
            an.push_back({l, i - 1});
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (has.find(i) == has.end() && has.find(i - 1) == has.end())
        {
            if (a[i] != a[i - 1])
                xian++;
        }
    }
    if (xian > m)
        return tm;
    int ing = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1])
            ing++;
    }
    if (abs(ing - m) % 2 == 1)
        return tm;
    if (ing == m)
        return a;
    else if (ing < m)
    {
        for (int i = an.size() - 1; i >= 0; i--)
        {
            int l = an[i].first, r = an[i].second;
            if (a[l - 1] == a[r + 1] && a[l - 1] == '0')
            {
            }
        }
    }
    else
    {
    }
}
void solve()
{
    cin >> n >> m;
    string a;
    cin >> a;
    if (a[0] == '?' && a.back() == '?')
    {
        vector<string> b(4);
        a[0] = '0', a.back() = '0';
        b[0] = work(a);
        a[0] = '0', a.back() = '1';
        b[1] = work(a);
        a[0] = '1', a.back() = '0';
        b[2] = work(a);
        a[0] = '1', a.back() = '1';
        b[3] = work(a);
        string ans = *min_element(b.begin(), b.end());
        if (ans == tm)
            cout << "Impossible" << endl;
        else
            cout << ans << endl;
    }
    else if (a[0] == '?')
    {
        vector<string> b(2);
        a[0] = '0';
        b[0] = work(a);
        a[0] = '1';
        b[1] = work(a);
        string ans = *min_element(b.begin(), b.end());
        if (ans == tm)
            cout << "Impossible" << endl;
        else
            cout << ans << endl;
    }
    else if (a.back() == '?')
    {
        vector<string> b(2);
        a.back() = '0';
        b[0] = work(a);
        a.back() = '1';
        b[1] = work(a);
        string ans = *min_element(b.begin(), b.end());
        if (ans == tm)
            cout << "Impossible" << endl;
        else
            cout << ans << endl;
    }
    else
    {
        vector<string> b(1);
        b[0] = work(a);
        string ans = *min_element(b.begin(), b.end());
        if (ans == tm)
            cout << "Impossible" << endl;
        else
            cout << ans << endl;
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