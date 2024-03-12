#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl;
using namespace std;
using i64 = long long;
struct string_hash
{
#define ll long long

    ll Q = 143, M = 1e9 + 7;
    vector<ll> h, p;
    string_hash()
    {
    }
    string_hash(int n)
    {

        init(n);
    }
    void init(int n, ll q = 131, ll m = 1e9 + 7)
    {
        Q = q, M = m;
        p.resize(n + 1);
        p[0] = 1;
        for (int i = 1; i <= n; i++)
            p[i] = p[i - 1] * Q % M;
        h.push_back(0);
    }
    template <class T> void Prefix_sum_Storage(T &str) // 预处理前缀和
    {
        for (int i = 0; i < str.size(); i++)
        {
            h.push_back((h.back() * Q + str[i]) % M);
        }
    }
    ll get(int l, int r) // 通过前缀和获得字串
    {
        l++, r++;
        return (h[r] - h[l - 1] * p[r - l + 1] % M + M) % M;
    }
    template <class T> void push_back(T c)
    {
        h.push_back(((h.size() ? h.back() : 0) * Q + c) % M);
    }
    void pop_back()
    {
        h.pop_back();
    }
    ll encode(string &str) // 编码
    {
        ll res = 0;
        for (auto i : str)
        {
            res = (res * Q % M + i) % M;
        }
        return res;
    }
};
void solve()
{
    int n;
    cin >> n;
    string a;
    cin >> a;
    auto check = [&](string &a, int x) {
        for (auto ch : a)
        {
            if (ch != x + '0')
                return false;
        }
        return true;
    };
    if (check(a, 0))
    {
        for (int i = 0; i < n; i++)
            cout << '1';
        cout << '\n';
        return;
    }
    if (check(a, 1))
    {
        for (int i = 0; i < n; i++)
            cout << '0';
        cout << '\n';
        return;
    }
    string all0, all1;
    for (int i = 0; i < n; i++)
    {
        all0 += '0', all1 += '1';
    }
    auto ch = [&](string in) {
        int m = in.size();
        int len = a.size();
        string_hash ha(m);
        ha.Prefix_sum_Storage(in);
        for (int i = 1; i + len < m; i++)
        {
            if (ha.get(0, len - 1) == ha.get(i, i + len - 1))
                return false;
        }
        return true;
    };
    if (ch(a + all0 + a))
    {
        cout << all0 << endl;
        return;
    }
    if (ch(a + all1 + a))
    {
        cout << all1 << endl;
        return;
    }
    assert(0);
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