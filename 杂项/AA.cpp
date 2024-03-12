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
    string a;
    cin >> a;
    map<char, vector<int>> mp;
    for (int i = 0; i < a.size(); i++)
        mp[a[i]].push_back(i);
    int ans = 1e9;
    int s1 = -1, s2 = -1;
    auto ge = [&](char a, int ci) {
        if (mp[a][0] > ci)
            return -1;
        int l = 0, r = mp[a].size() - 1;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (mp[a][mid] <= ci)
                l = mid;
            else
                r = mid - 1;
        }
        return mp[a][l];
    };
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == 'b')
        {
            int res = 0;
            int g = ge('p', i - 1);
            if (g == -1)
                continue;
            res += (i - 1) - g;
            g = ge('s', g - 1);
            if (g == -1)
                continue;
            res += (i - 2) - g;
            auto get = upper_bound(mp['s'].begin(), mp['s'].end(), i);
            if (get == mp['s'].end())
                continue;
            res += *get - i - 1;
            get = upper_bound(mp['u'].begin(), mp['u'].end(), (*get));
            if (get == mp['u'].end())
                continue;
            res += *get - i - 2;
            chkmin(ans, res);
        }
    }
    cout << ans << endl;
    return 0;
}