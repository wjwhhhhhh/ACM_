#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
struct SA_IS
{
    using vec = std::vector<int>;
    using iter = vec::iterator;

    const int n;
    std::vector<int> wa, wb, wv, ws;
    std::vector<int> r, sa;

    SA_IS(std::string a) : n(a.size() + 1), sa(3 * n), r(3 * n), wa(n), wb(n), wv(n), ws(std::max(128, n))
    {
        a += char(0);
        for (int i = 0; i < n; i++)
        {
            r[i] = a[i];
        }
        dc3(r.begin(), sa.begin(), n, 127);
    }

    int c0(iter r, int a, int b)
    {
        return r[a] == r[b] && r[a + 1] == r[b + 1] && r[a + 2] == r[b + 2];
    }

    int c12(int k, iter r, int a, int b)
    {
        if (k == 2)
        {
            return r[a] < r[b] || r[a] == r[b] && c12(1, r, a + 1, b + 1);
        }
        return r[a] < r[b] || r[a] == r[b] && wv[a + 1] < wv[b + 1];
    }

    void sort(iter r, vec &a, vec &b, int n, int m)
    {
        for (int i = 0; i < n; i++)
        {
            wv[i] = r[a[i]];
        }
        for (int i = 0; i < m; i++)
        {
            ws[i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            ws[wv[i]]++;
        }
        for (int i = 1; i < m; i++)
        {
            ws[i] += ws[i - 1];
        }
        for (int i = n - 1; i >= 0; i--)
        {
            b[--ws[wv[i]]] = a[i];
        }
    }

    void dc3(iter r, iter sa, int n, int m)
    {
        int i, j, ta = 0, tb = (n + 1) / 3, tbc = 0, p;
        iter rn = r + n;
        iter san = sa + n;
        r[n] = r[n + 1] = 0;

        auto g = [&](int x) { return x < tb ? x * 3 + 1 : (x - tb) * 3 + 2; };
        auto f = [&](int x) { return x / 3 + (x % 3 == 1 ? 0 : tb); };

        for (int i = 0; i < n; i++)
        {
            if (i % 3 != 0)
            {
                wa[tbc++] = i;
            }
        }

        sort(r + 2, wa, wb, tbc, m);
        sort(r + 1, wb, wa, tbc, m);
        sort(r, wa, wb, tbc, m);

        for (p = 1, rn[f(wb[0])] = 0, i = 1; i < tbc; i++)
        {
            rn[f(wb[i])] = c0(r, wb[i - 1], wb[i]) ? p - 1 : p++;
        }

        if (p < tbc)
        {
            dc3(rn, san, tbc, p);
        }
        else
        {
            for (int i = 0; i < tbc; i++)
            {
                san[rn[i]] = i;
            }
        }

        for (int i = 0; i < tbc; i++)
        {
            if (san[i] < tb)
            {
                wb[ta++] = san[i] * 3;
            }
        }

        if (n % 3 == 1)
        {
            wb[ta++] = n - 1;
        }
        sort(r, wb, wa, ta, m);

        for (int i = 0; i < tbc; i++)
        {
            wv[wb[i] = g(san[i])] = i;
        }

        i = 0, j = 0, p = 0;
        while (i < ta && j < tbc)
        {
            sa[p++] = c12(wb[j] % 3, r, wa[i], wb[j]) ? wa[i++] : wb[j++];
        }
        while (i < ta)
        {
            sa[p++] = wa[i++];
        }
        while (j < tbc)
        {
            sa[p++] = wb[j++];
        }
    }
    vector<int> get_rk()
    {
        vector<int> rk(n - 1);
        for (int i = 1; i < n; i++)
            rk[sa[i]] = i - 1;
        return rk;
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a;
    cin >> a;
    string b = a;
    int n = a.size();
    a = a + a;
    SA_IS need(a);
    auto rk = need.get_rk();
    string ans(n, ' ');
    vector<int> o(n);
    iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](int x, int y) { return rk[x] < rk[y]; });
    for (int i = 0; i < n; i++)
    {
        int j = o[i];
        ans[i] = b[(j + n - 1) % n];
    }
    cout << ans << endl;
    return 0;
}