#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
struct SA
{
    vector<int> sa, rk, he;
    string s;
    SA()
    {
    }
    void work()
    {
        s += char(0);
        int n = s.size(), m = 128;
        sa.resize(n), rk.resize(n), he.resize(n);
        vector<int> oldrk(n), key1(n), cnt(max(m, n));
        auto cmp = [&](int a, int b, int l) { return oldrk[a] == oldrk[b] && oldrk[a + l] == oldrk[b + l]; };
        fill(cnt.begin(), cnt.begin() + m, 0);
        for (int i = 0; i < s.size(); i++)
            rk[i] = s[i];
        for (int i = 0; i < n; i++)
            cnt[rk[i]]++;
        for (int i = 1; i < m; i++)
            cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; i--)
            sa[--cnt[rk[i]]] = i;
        for (int j = 1, p = 1; p < n; j *= 2, m = p)
        {
            p = 0;
            for (int i = n - j; i < n; i++)
                oldrk[p++] = i;
            for (int i = 0; i < n; i++)
                if (sa[i] >= j)
                    oldrk[p++] = sa[i] - j;
            fill(cnt.begin(), cnt.begin() + m, 0);
            for (int i = 0; i < n; i++)
                key1[i] = rk[oldrk[i]];
            for (int i = 0; i < n; i++)
                cnt[key1[i]]++;
            for (int i = 1; i < m; i++)
                cnt[i] += cnt[i - 1];
            for (int i = n - 1; i >= 0; i--)
                sa[--cnt[key1[i]]] = oldrk[i];
            swap(oldrk, rk);
            p = 1, rk[sa[0]] = 0;
            for (int i = 1; i < n; i++)
                rk[sa[i]] = cmp(sa[i - 1], sa[i], j) ? p - 1 : p++;
        }
        for (int i = 0; i < n; i++)
            rk[sa[i]] = i;
        for (int i = 0, k = 0; i < n - 1; i++)
        {
            if (k)
                k--;
            while (s[i + k] == s[sa[rk[i] - 1] + k])
                k++;
            he[rk[i]] = k;
        }
    }
};
struct DSU
{
    std::vector<int> f, siz;
    struct state
    {
        int ma = 0, mi = 0;
    };
    vector<state> st;
    i64 nums, res;
    DSU()
    {
    }
    DSU(int n)
    {
        init(n);
        nums = 0, res = -2e18;
    }

    void init(int n)
    {
        f.resize(n);
        st.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }

    int find(int x)
    {
        while (x != f[x])
        {
            x = f[x] = f[f[x]];
        }
        return x;
    }

    bool same(int x, int y)
    {
        return find(x) == find(y);
    }

    bool merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
        {
            return false;
        }
        nums += (i64)siz[x] * siz[y];
        res = max(res, max((i64)st[x].mi * st[y].mi, (i64)st[x].ma * st[y].ma));
        f[x] = y;
        siz[y] += siz[x];
        st[y].mi = min(st[x].mi, st[y].mi);
        st[y].ma = max(st[x].ma, st[y].ma);
        return true;
    }

    int size(int x)
    {
        return siz[find(x)];
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin >> n;
    SA sa;
    cin >> sa.s;
    sa.work();
    vector<int> w(n);
    for (int i = 0; i < n; i++)
        cin >> w[i];
    DSU f(n + 1);
    for (int i = 0; i < n; i++)
        f.st[i].ma = f.st[i].mi = w[i];
    vector<int> o(n + 1);
    iota(o.begin(), o.end(), 0);
    stable_sort(o.begin() + 1, o.end(), [&](int x, int y) { return sa.he[x] < sa.he[y]; });
    vector<i64> ans1(n), ans2(n);
    int l = n;
    for (int i = n - 1; i >= 0; i--)
    {
        while (l > 1 && sa.he[o[l]] == i)
        {
            // cout<<sa.sa[o[l]]<<" "<<sa.sa[o[l]-1]<<" "<<i<<endl;
            f.merge(sa.sa[o[l]], sa.sa[o[l] - 1]);
            l--;
        }
        if (f.nums)
            ans1[i] = f.nums, ans2[i] = f.res;
    }
    for (int i = 0; i < n; i++)
        cout << ans1[i] << " " << ans2[i] << endl;
    return 0;
}