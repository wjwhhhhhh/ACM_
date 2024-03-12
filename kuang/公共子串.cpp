#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
struct SA // 最长公共前缀 //会帮你在最后加一个0
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
void solve(int k)
{
    SA sa;
    string a, b;
    cin >> a >> b;
    int n = a.size();
    sa.s = a + "#" + b;
    sa.work();
    i64 ans = 0;
    for (int i = 0; i < sa.s.size(); i++)
    {
        // cout << sa.he[i] << endl;
        if (sa.he[i] >= k)
        {
            vector<int> v;
            while (i < sa.s.size() && sa.he[i] >= k)
                v.push_back(i++);
            stack<array<int, 3>> has;
            for (int j = 0; j < v.size(); j++)
            {
                int cnt = sa.he[v[j]] - k + 1;
                array<int, 3> te{sa.he[v[j]], 1, 0};
                while (has.size() && te[0] <= has.top()[0])
                {
                    te[1] += has.top()[1];
                    has.pop();
                }
                te[2] = (has.size() ? has.top()[2] : 0) + cnt * te[1];
                has.push(te);
                ans += te[2];
            }
        }
    }
    sa.s = a;
    sa.work();
    for (int i = 0; i < sa.s.size(); i++)
    {
        // cout << sa.he[i] << endl;
        if (sa.he[i] >= k)
        {
            vector<int> v;
            while (i < sa.s.size() && sa.he[i] >= k)
                v.push_back(i++);
            stack<array<int, 3>> has;
            for (int j = 0; j < v.size(); j++)
            {
                int cnt = sa.he[v[j]] - k + 1;
                array<int, 3> te{sa.he[v[j]], 1, 0};
                while (has.size() && te[0] <= has.top()[0])
                {
                    te[1] += has.top()[1];
                    has.pop();
                }
                te[2] = (has.size() ? has.top()[2] : 0) + cnt * te[1];
                has.push(te);
                ans -= te[2];
            }
        }
    }
    sa.s = b;
    sa.work();
    for (int i = 0; i < sa.s.size(); i++)
    {
        // cout << sa.he[i] << endl;
        if (sa.he[i] >= k)
        {
            vector<int> v;
            while (i < sa.s.size() && sa.he[i] >= k)
                v.push_back(i++);
            stack<array<int, 3>> has;
            for (int j = 0; j < v.size(); j++)
            {
                int cnt = sa.he[v[j]] - k + 1;
                array<int, 3> te{sa.he[v[j]], 1, 0};
                while (has.size() && te[0] <= has.top()[0])
                {
                    te[1] += has.top()[1];
                    has.pop();
                }
                te[2] = (has.size() ? has.top()[2] : 0) + cnt * te[1];
                has.push(te);
                ans -= te[2];
            }
        }
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k;
    while (cin >> k, k)
    {
        solve(k);
    }
    return 0;
}