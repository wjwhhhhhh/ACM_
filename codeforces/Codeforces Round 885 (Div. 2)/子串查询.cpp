#include <bits/stdc++.h>
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
int main()
{
    int n, q;
    cin >> n >> q;
    set<ll> sh;
    string_hash ha(n);
    string a;
    cin >> a;
    ha.Prefix_sum_Storage(a);
    for (int i = 0; i < n; i++)
        for (int j = i; j - i < 50 && j < n; j++)
        {
            sh.insert(ha.get(i, j));
        }
    while (q--)
    {
        string a;
        cin >> a;
        if (sh.find(ha.encode(a)) != sh.end())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}