#include <bits/stdc++.h>
using namespace std;
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