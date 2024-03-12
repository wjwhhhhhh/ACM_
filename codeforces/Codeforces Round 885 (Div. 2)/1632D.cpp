#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 2e5 + 10;
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
    virtual int op(int &x, int &y)
    {
        return max(x, y);
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
    int op(int &x, int &y)
    {
        return __gcd(x, y);
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    St st(a);
    int ans = 0;
    for (int i = 0, j = 0; i < n; i++)
    {
        int l = j, r = i;
        auto check = [&](int x) { return (i - x + 1) >= st.ask(x, i); };
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (check(mid))
                l = mid;
            else
                r = mid - 1;
        }
        if (st.ask(l, i) == (i - l + 1))
        {
            ans++, j = i + 1;
        }
        cout << ans << " ";
    }
    return 0;
}