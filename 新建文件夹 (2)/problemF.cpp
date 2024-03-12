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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin >> n;
    string a, ans;
    cin >> a;
    vector<char> mp;
    for (int i = 0; i < n; i++)
    {
        string an;
        if (find(mp.begin(), mp.end(), a[i]) == mp.end())
        {
            mp.push_back(a[i]);
        }
        else
        {
            auto ch = find(mp.begin(), mp.end(), a[i]);
            mp.erase(ch);
            mp.push_back(a[i]);
        }
        map<char, int> has;
        for (int j = 0; j < mp.size(); j++)
            has[mp[j]] = mp.size() - j - 1;
        for (int j = 0; j <= i; j++)
        {
            an += has[a[j]] + 'a';
        }
        // cout << an << endl;
        chkmax(ans, an);
    }
    cout << ans << endl;
    return 0;
}