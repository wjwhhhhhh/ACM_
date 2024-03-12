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
    vector<i64> has;
    function<void(int, i64)> dfs = [&](int idx, i64 res) {
        if (idx)
        {
            has.push_back(res);
        }
        if (idx == 11)
        {
            return;
        }
        dfs(idx + 1, res * 10 + 4);
        dfs(idx + 1, res * 10 + 7);
    };
    dfs(0, 0ll);
    sort(has.begin(), has.end());
    int n;
    cin >> n;

    i64 si = has.end() - upper_bound(has.begin(), has.end(), n);
    cout << has.size() - si << endl;
    return 0;
}