#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin >> n;
    string a('0', n);
    vector<int> w(n);
    for (int i = 0; i < n; i++)
        cin >> w[i];
    vector<int> o(n);
    iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](int x, int y) { return w[x] < w[y]; });
    int ma = *max_element(w.begin(), w.end());
    if (w[o[0]] == ma)
    {
        for (int i = 0; i < n; i++)
            cout << 1;
        return;
    }
    int last = 1e9, res;
    for (int i = 0, j = n - 1; i < n; i++)
    {
        if (i < j)
        {
            a[i] = '0';
            last = min(last, a[i]) + w[j]
        }
        else
        {
        }
    }
    return 0;
}