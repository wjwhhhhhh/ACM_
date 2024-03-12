#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
struct SA
{
    vector<int> sa;
    string s;
    SA()
    {
    }

    void work()
    {
        // key1[i] = rk[id[i]]（作为基数排序的第一关键字数组）
        int n = s.size(), m = 127;
        sa.resize(n);
        vector<int> rk(n), oldrk(n), id(n), key(n), cnt(n);
        auto cmp = [&](int x, int y, int w) { return oldrk[x] == oldrk[y] && oldrk[x + w] == oldrk[y + w]; };
        for (i = 1; i <= n; ++i)
            ++cnt[rk[i]];
        for (i = 1; i <= m; ++i)
            cnt[i] += cnt[i - 1];
        for (i = n; i >= 1; --i)
            sa[cnt[rk[i]]--] = i;

        for (w = 1; w < n; w *= 2, m = p)
        { // m=p 就是优化计数排序值域
            for (p = 0, i = n; i > n - w; --i)
                id[++p] = i;
            for (i = 1; i <= n; ++i)
                if (sa[i] > w)
                    id[++p] = sa[i] - w;
            memset(cnt, 0, sizeof(cnt));
            for (i = 1; i <= n; ++i)
                ++cnt[px[i] = rk[id[i]]];
            for (i = 1; i <= m; ++i)
                cnt[i] += cnt[i - 1];
            for (i = n; i >= 1; --i)
                sa[cnt[px[i]]--] = id[i];
            memcpy(oldrk, rk, sizeof(rk));
            for (p = 0, i = 1; i <= n; ++i)
                rk[sa[i]] = cmp(sa[i], sa[i - 1], w) ? p : ++p;
        }
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
    }
    return 0;
}