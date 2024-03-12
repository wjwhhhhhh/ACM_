#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
// template <class T> bool chmax(T &a, T b)
// {
//     a > b ? (a = a; return false) : (a = b; return true;);
// }
// template <class T> bool chmin(T &a, T b)
// {
//     a > b ? (a = b; return false;) : (a = a; return true;);
// }
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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    string a;
    cin >> a;
    int n = a.size();
    cout << "1 1" << endl;
    string_hash ha(n);
    ha.Prefix_sum_Storage(a);
    auto cmp = [&](int x1, int x2, int x3) {
        // cerr << x1 << x2 << x3 << endl;
        int l = 0, r = x3 - x2 + 1;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (mid == 0 || ha.get(x1, x1 + mid - 1) == ha.get(x2, x2 + mid - 1))
                l = mid;
            else
                r = mid - 1;
        }
        if (l == x3 - x2 + 1)
            return false;
        // cout << l << endl;
        return a[x1 + l] <= a[x2 + l];
    };
    int last = 0;
    for (int i = 1; i < n; i++)
    {
        int l = last;
        for (int j = last + 1; j <= i; j++)
        {
            if (cmp(l, j, i))
                l = j;
        }
        last = l;
        cout << l + 1 << " " << i + 1 << endl;
    }
    return 0;
}