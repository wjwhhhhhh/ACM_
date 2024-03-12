#include <bits/stdc++.h>
using namespace std;
template <class T>
struct stable
{
    static const int K = 20;
    vector<array<T, K>> f;
    int si;
    void work(vector<T> &a) // 默认从0开始
    {
        for (int i = 0; i < si; ++i)
        {
            f[i][0] = a[i];
        }
        for (int j = 1; j < K; ++j)
        {
            for (int i = 0; i + (1 << j) - 1 < si; i++)
            {
                f[i][j] = op(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    T ask(int l, int r)
    {
        int len = r - l + 1;
        len = __lg(len);
        return op(f[l][len], f[r - (1 << len) + 1][len]);
    }
    virtual T op(const T& x, const T& y)
    {
        return min(x, y);
    }
};
template <class T>
struct St : stable<T>
{
    St()
    {
    }
    St(vector<T> &a)
    {

        si=a.size();
        f.resize(si);
        work(a);
    }
    T op(const T& x, const T& y)
    {
        return min(x, y);
    }
};