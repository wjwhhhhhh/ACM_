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
void solve()
{
    string a, b;
    cin >> a >> b;
    map<char, int> mp;
    for (int i = 0; i < a.size(); i++)
    {
        mp[a[i]]++;
    }
    int has = 0;
    vector<int> st(b.size());
    for (int i = 0; i < b.size(); i++)
    {
        if (mp[b[i]] > 0)
        {
            st[i] = true;
            has++;
            mp[b[i]]--;
        }
    }
    cout << has << " ";
    int ing = 0;
    for (int i = 0; i < b.size(); i++)
    {
        if (ing + has > a.size())
            break;
        if (!st[i])
        {
            if (b[i] >= 'a' && b[i] <= 'z')
                b[i] = b[i] + ('A' - 'a');
            else
                b[i] = b[i] + ('a' - 'A');
            if (mp[b[i]] > 0)
            {
                st[i] = true;
                ing++;
                mp[b[i]]--;
            }
        }
    }
    cout << ing << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}