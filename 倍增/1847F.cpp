#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
struct stable
{
    static const int K = 20;
    vector<array<int, K>> f;
    int si;
    void work(vector<int> &a) // 默认从0开始
    {
        for (int i = 0; i < si; ++i)
        {
            f[i][0] = a[i];
        }
        for (int j = 1; j < K; ++j)
        {
            for (int i = 0; i + (1 << j) - 1 < si; i++)
            {
                f[i][j] = op(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    int ask(int l, int r)
    {
        int len = r - l + 1;
        len = __lg(len);
        return op(f[l][len], f[r - (1 << len) + 1][len]);
    }
    virtual int op(const int &x, const int &y)
    {
        return min(x, y);
    }
};
struct St : stable
{
    St()
    {
    }
    St(vector<int> &a)
    {

        si = a.size();
        f.resize(si);
        work(a);
    }
    int op(const int &x, const int &y)
    {
        return x | y;
    }
};
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(2 * n);
    for (int i = 0; i < n; i++)
        cin >> a[n - 1 - i], a[2 * n - 1 - i] = a[n - 1 - i];
    St st(a);
    vector<pair<i64, i64>> has;
    has.push_back({0, a[n - 1]});
    auto get = [&](int i, int l) -> i64 {
        i = n - i - 1;
        return 1ll * l * (n - 1) + i;
    };
    for (int i = 0; i < n - 1; i++)
    {
        // cerr<<i<<endl;
        int j = 0;
        while (1)
        {
            int tem = st.ask(i, i + j);
            has.push_back({get(i, j), tem});
            int l = j, r = n - 1;
            while (l < r)
            {
                int mid = l + r + 1 >> 1;
                if (st.ask(i, i + mid) <= tem)
                    l = mid;
                else
                    r = mid - 1;
            }
            if (l == n - 1)
                break;
            else
                j = l + 1;
        }
    }
    sort(has.begin(), has.end());
    vector<pair<i64, i64>> ans;
    i64 tem = 0;
    for (int i = 0; i < has.size(); i++)
    {
        if (tem >= has[i].second)
            continue;
        else
        {
            ans.push_back({has[i].second, has[i].first});
            tem = max(tem, has[i].second);
        }
    }
    while (q--)
    {
        i64 res;
        cin >> res;
        //    cerr<<"kl";
        auto get = upper_bound(ans.begin(), ans.end(), make_pair(res, 1e18));
        cout << (get == ans.end() ? -1 : get->second + 1) << '\n';
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