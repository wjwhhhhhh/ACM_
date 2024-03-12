#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
struct string_hash
{
#define ll long long

    ll Q = 131, M = 1e9 + 7;
    vector<ll> h, p;
    string_hash()
    {
    }
    string_hash(int n)
    {

        init(n);
    }
    void init(int n, ll q = 1331, ll m = 1e9 + 7)
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
    void clear()
    {
        h.clear();
        h.push_back(0);
    }
    ll get(int l, int r) // 通过前缀和获得字串
    {
        l++, r++;
        return (h[r] - h[l - 1] * p[r - l + 1] % M + M) % M;
    }
    template <class T> void push_back(T c)
    {
        h.push_back((h.back() * Q % M + c) % M);
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
const int N = 1e6 + 10;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    string_hash ha(N), hb(N),haa,hbb;
    string ans = a[0];
    ha.Prefix_sum_Storage(ans);
    for (int i = 1; i < n; i++)
    {
        int len = 0, m = ans.size();
        hb.clear();
        hb.Prefix_sum_Storage(a[i]);
        for (int j = 0; j < m && j < a[i].size(); j++)
        {
            if (ha.get(m - j - 1, m - 1) == hb.get(0, j))
                len = max(j + 1, len);
        }
        for (; len < a[i].size(); len++)
        {
            ans += a[i][len];
            ha.push_back(a[i][len]);
        }
    }
    cout << ans << endl;
    return 0;
}