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
    string_hash(int n, ll q = 131, ll m = 1e9 + 7)
    {
        Q = q, M = m;
        init(n);
    }
    void init(int n)
    {
        p.resize(n + 1);
        p[0] = 1;
        for (int i = 1; i <= n; i++)
            p[i] = p[i - 1] * Q % M;
    }
    void Pre(string str) // 预处理前缀和
    {
        int n = str.size();
        h.resize(n + 1);
        str = " " + str;
        for (int i = 1; i <= n; i++)
        {
            h[i] = (h[i - 1] * Q + str[i]) % M;
        }
    }
    ll get(int l, int r) // 通过前缀和获得字串
    {
        return (h[r] - h[l - 1] * p[r - l + 1] % M + M) % M;
    }
    ll encode(string str) // 编码
    {
        ll res = 0;
        for (auto i : str)
        {
            res = res * Q + i;
        }
        return res;
    }
};
void solve()
{
    string_hash h(55);
    set<ll> mp;
    vector<ll> st;
    int n;
    cin >> n;
    int an = 0;
    for (int i = 1; i <= n; i++)
    {
        string a;
        cin >> a;
        h.Pre(a);
        for (int len = 1; len <= a.size(); len++)
        {
            st.clear();
            for (int i = 1; i + len - 1 <= a.size(); i++)
            {
                int x = i, y = i + len - 1;
                auto tem = h.get(x, y);
                st.push_back(tem);
                if (mp.find(tem) != mp.end())an = max(an, len);
            }
            for (auto tr : st)
            {
                mp.insert(tr);
            }
        }
    }
    cout << an << '\n';

}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);

    int t = 1;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }

    return 0;
}