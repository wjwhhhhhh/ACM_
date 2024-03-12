#include <bits/stdc++.h>
using namespace std;
struct string_hash
{
#define ll  long long

    ll Q = 143, M = 1e9 + 7;
    vector<ll> h, p;
    string_hash()
    {
    }
    string_hash(int n,ll q,ll m)
    {
        Q=q,M=m;
        init(n);
    }
    void init(int n)
    {
        p.resize(n + 1);
        p[0] = 1;
        for (int i = 1; i <= n; i++)
            p[i] = p[i - 1] * Q % M;
    }
    void Prefix_sum_Storage(string str)//预处理前缀和
    {
        int n = str.size();
        h.resize(n + 1);
        str = " " + str;
        for (int i = 1; i <= n; i++)
        {
            h[i] = (h[i - 1] * Q + str[i]) % M;
        }
    }
    ll get(int l, int r)//通过前缀和获得字串
    {
        return (h[r] - h[l - 1] * p[r - l + 1]%M + M) % M;
    }
    ll encode(string str)//编码
    {
        ll res = 0;
        for (auto i : str)
        {
            res = res * Q + i;
        }
        return res;
    }
};
const int N = 4e5 + 10;
string_hash ha(N);
map<ull, int> mp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    long long res = 0;
    vector<string> w(n + 5);
    for (int i = 1; i <= n; i++)cin >> w[i];
    sort(w.begin() + 1, w.begin() + 1 + n, [&](string x, string y) {
        return x.size() < y.size();
    });
    for (int i = 1; i <= n; i++)
    {
        string tem = w[i];
        ha.Prefix_sum_Storage(tem);
        auto t = ha.get(1, tem.size());
        if (mp.find(t) != mp.end())res += mp[t];
        for (int l = 1; l < tem.size() + 1 - l; l++)
        {
            int r = tem.size() + 1 - l;
            int len = tem.size();
            if (ha.get(1, l) == ha.get(r, len))
            {
                int tt = ha.get(l + 1, r - 1);
                res += mp[tt];
            }
        }
        mp[t]++;
    }
    cout << res << endl;
    return 0;
}