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
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    }
    int res = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        bool fl = true;
        for (int z = 0; z < n; z++)
        {
            if (a[i][z] == 1 || a[i][z] == 3)
                fl = false;
        }
        if (fl)
            ans.push_back(i);
    }
    cout << ans.size() << endl;
    for (auto x : ans)
        cout << x + 1 << " ";
    return 0;
}