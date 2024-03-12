#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int mp[150];
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
    ll encode(string str) // 编码
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
    string a;
    cin >> a;
    int n = a.size();
    for (auto x : a)
    {
        // cerr << mp[x] << endl;
        if (mp[x] == 0)
        {
            cout << "No" << endl;
            return;
        }
    }
    for (int i = n - 1; i >= 0; i--)
        a += char(mp[a[i]]);
    string_hash ha(2 * n);
   // cout << a << endl;
    ha.Prefix_sum_Storage(a);
    int l = -1;
    for (int i = 0; i < n; i++)
    {
        if (ha.get(l + 1, i) == ha.get(2 * n - 1 - i, 2 * n - 2 - l))
            l = i;
    }
    if (l == n - 1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    mp['o'] = 'o', mp['s'] = 's', mp['x'] = 'x', mp['z'] = 'z', mp['b'] = 'q', mp['q'] = 'b', mp['d'] = 'p',
    mp['p'] = 'd', mp['n'] = 'u', mp['u'] = 'n';
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}