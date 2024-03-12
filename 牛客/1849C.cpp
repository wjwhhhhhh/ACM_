#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl;
using namespace std;
using i64 = long long;
template <class T> struct Tree_array
{
    vector<T> tr;
    int maxx;
    Tree_array(int n)
    {
        init(n);
    }
    Tree_array(vector<T> a)
    {
        int n = a.size();
        init(n + 1);
        for (int i = 1; i < n; i++)
            insert(i, a[i]);
    }
    void init(int n)
    {
        maxx = n;
        tr.resize(n + 1);
    }
    void insert(int x, T c)
    {
        for (int i = x; i <= maxx; i += lowbit(i))
            op(tr[i], c);
    }
    T ask(int x)
    {
        T res = 0;
        for (int i = x; i; i -= lowbit(i))
            op(res, tr[i]);
        return res;
    }
    int lowbit(int x)
    {
        return x & -x;
    }
    void op(T &x, T c)
    {
        x += c;
    }
};
struct string_hash
{
#define ll unsigned long long

    ll Q = 131;
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
        Q = q;
        p.resize(n + 1);
        p[0] = 1;
        for (int i = 1; i <= n; i++)
            p[i] = p[i - 1] * Q;
        h.push_back(0);
    }
    template <class T> void Prefix_sum_Storage(T &str) // 预处理前缀和
    {
        for (int i = 0; i < str.size(); i++)
        {
            h.push_back((h.back() * Q + str[i]));
        }
    }
    ll get(int l, int r) // 通过前缀和获得字串
    {
        // cerr << l << r << endl;
        if (r < l)
            return 0;
        return (h[r] - h[l - 1] * p[r - l + 1]);
    }
    template <class T> void push_back(T c)
    {
        h.push_back(((h.size() ? h.back() : 0) * Q + c));
    }
    void pop_back()
    {
        h.pop_back();
    }
    ll encode(string &str) // 编码
    {
        ll res = 0;
        int l, r;
        cin >> l >> r;
        for (auto i : str)
        {
            res = (res * Q + i);
        }
        return res;
    }
};
void solve()
{
    int n, k;
    cin >> n >> k;
    string a;
    cin >> a;
    string_hash ha(n);
    ha.Prefix_sum_Storage(a);
    Tree_array<int> tr(n);
    for (int i = 0; i < n; i++)
        tr.insert(i + 1, a[i] == '1');
    vector<ll> all0(1, 0), all1(1, 0);
    for (int i = 1; i <= n; i++)
    {
        all0.push_back(all0.back() * ha.Q + '0');
        all1.push_back(all1.back() * ha.Q + '1');
    }
    set<i64> has;
    while (k--)
    {
        int l, r;
        cin >> l >> r;
        int si = tr.ask(r) - tr.ask(l - 1), cnt = 0;
        ll val = ha.get(r + 1, n);
        cnt += n - r;
        val += all1[si] * ha.p[cnt];
        cnt += si;
        val += all0[r - l + 1 - si] * ha.p[cnt];
        cnt += r - l + 1 - si;
        val += ha.get(1, l - 1) * ha.p[cnt];
        has.insert(val);
    }
    cout << has.size() << '\n';
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