#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
#define fir(a, b, c) for (int a = b; a < c; a++)
using namespace std;
using i64 = long long;
using two = array<int, 2>;
template <class T> bool chmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
    return a == b;
}
template <class T> bool chmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
    return a == b;
}
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
    void clear()
    {
        h.clear();
        h.push_back(0);
    }
    int size()
    {
        return h.size() - 1;
    }
    bool operator<(string_hash a)
    {
        if (this->size() < a.size())
            return true;
        if (this->size() < a.size())
            return false;
        for (int i = 0; i < this->size(); i++)
        {
            if (this->get(i, i) != a.get(i, i))
            {
                if (this->get(i, i) < a.get(i, i))
                    return true;
                else
                    return false;
            }
        }
        return false;
    }
    void operator=(string_hash tem)
    {
        this->h = tem.h;
    };
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
    int n;
    cin >> n;
    string a;
    cin >> a;
    string b = a;
    reverse(b.begin(), b.end());
    a = a + b;
    string_hash ha(2 * n);
    ha.Prefix_sum_Storage(a);
    i64 ans = -1;
    auto check = [&](int l, int r) { return ha.get(l, r) == ha.get(2 * n - 1 - r, 2 * n - 1 - l); };
    for (int i = 0; i < n; i++)
    {
        if (2 * (i + 1) > n)
            break;
        if (ha.get(0, i) == ha.get(n - i - 1, n - 1))
        {
            if (i + 1 == n - i - 2 || check(i + 1, n - i - 2))
                ans = i + 1;
        }
    }
    if (ans == -1)
        cout << ans << endl;
    else
        cout << a.substr(0, ans) << endl;
    return 0;
}