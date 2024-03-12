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
        for (int i = 1; i <= str.size(); i++)
        {
            h.push_back((h.back() * Q + str[i - 1]) % M);
        }
    }
    ll get(int l, int r) // 通过前缀和获得字串
    {
        return (h[r] - h[l - 1] * p[r - l + 1] % M + M) % M;
    }
    void push_back(char c)
    {
        h.push_back((h.back() * Q + c) % M);
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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), c(n);
    string_hash ha(n + 10);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (n == 1)
    {
        cout << "0" << endl;
    }
    for (int i = 1; i < n; i++)
        c[i] = a[i] - a[i - 1];
    ha.Prefix_sum_Storage(c);
    auto check=[&](int len)
    {
        set<int> has;
        for(int i=2*len-1;i<n;i++)
        {
            auto get=ha.get(1,len-1);
            has.insert(get);
            get=ha.get(i-len+2,i);
            if(has.find(get)!=has.end())return true;
        }
        return false;
    };
    int l = 2, r = n / 2;
    while(l<r)
    {
        int mid=l+r+1>>1;
        if(check(mid))l=mid;
        else r=mid-1;
    }
    cout << l << endl;
    return 0;
}