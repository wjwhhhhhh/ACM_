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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    fir(i, 0, n) cin >> a[i];
    vector<int> aa = a;
    a[0] = aa[0];
    for (int i = 1; i < n; i++)
        a[i] = aa[i] - aa[i - 1];
    vector<vector<int>> cnt(k);
    vector<array<int, 15>> id(n + 1);
    for (int i = 0; i < k; i++)
    {
        cnt[i].push_back(0);
    }
    fill(id[0].begin(), id[0].end(), 0);
    for (int i = 0; i < n; i++)
    {
        if (i)
        {
            id[i] = id[i - 1];
        }
        cnt[i % k].push_back(a[i]);
        id[i][i % k] = cnt[i % k].size() - 1;
    }
    for (int i = 0; i < k; i++)
    {
        for (int j = 1; j < cnt[i].size(); j++)
        {
            cnt[i][j] += cnt[i][j - 1];
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int last = (l == 0 ? 0 : aa[l - 1]);
        if (r - l + 1 < k)
        {
            bool fl = false;
            if (a[l] != -last)
            {
                cout << "No" << endl;
                continue;
            }
            for (int i = l + 1; i <= r; i++)
            {
                if (a[i] != 0)
                {
                    fl = true;
                    cout << "No" << endl;
                    break;
                }
            }
            if (!fl)
                cout << "Yes" << endl;
        }
        else
        {
            bool fl = false;
            for (int i = 0; i < k; i++)
            {
                if ((r + 1) % k == (l + i) % k)
                    continue;
                if (cnt[(l + i) % k][id[r][(l + i) % k]] - cnt[(l + i) % k][id[l + i][(l + i) % k] - 1] !=
                    (i == 0 ? -last : 0))
                {
                    fl = true;
                    cout << "No" << endl;
                    break;
                }
            }
            if (!fl)
                cout << "Yes" << endl;
        }
    }
    return 0;
}