#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
struct stable
{
    static const int K = 20;
    vector<array<int, K>> f;
    // vector<int> lg;
    int si;
    stable()
    {
    }
    stable(int n)
    {
        init(n);
    }
    void init(int n)
    {
        si = n;
        f.resize(n + 5);
        // lg[0] = -1;
        //  for (int i = 1; i <= n; i++)
        //      lg[i] = lg[i / 2] + 1;
        // lg.resize(n+5);
    }
    void work(int *a) // 默认从1开始
    {
        for (int i = 1; i <= si; ++i)
        {
            f[i][0] = a[i];
        }
        for (int j = 1; j < K; ++j)
        {
            for (int i = 1; i + (1 << j) - 1 <= si; ++i)
            {
                f[i][j] = op(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    void work(vector<int> a) // 默认从1开始
    {
        for (int i = 1; i <= si; ++i)
        {
            f[i][0] = a[i];
        }
        for (int j = 1; j < K; ++j)
        {
            for (int i = 1; i + (1 << j) - 1 <= si; ++i)
            {
                f[i][j] = op(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    int ask(int l, int r)
    {
        int len = r - l + 1;
        len = __lg(len);
        return op(f[l][len], f[r - (1 << len) + 1][len]);
    }
    virtual int op(int x, int y)
    {
        return max(x, y);
    }
};
struct ab : stable
{
    ab()
    {

    }
    ab (int n)
    {
        init(n);
    }
    int op(int x, int y)
    {
        return max(x, y);
    }
};
const int N = 5e5 + 10;
ab stt;
int r[N];
void solves()
{
    int n;
    cin >> n;
    vector<int> a(n + 2);
    stt.init(n);
    i64 res = 0;
    for (int i = 1; i <= n; i++)cin >> a[i], res += 1ll * (i) * (i - 1) / 2;
    stt.work(a);
    vector<int> s;
    s.push_back(n + 1);
    for (int i = n; i > 0; i--)
    {
        while (a[s.back()] > a[i])s.pop_back();
        r[i] = s.back();
        s.push_back(i);
    }
    s.clear();
    s.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        while (a[s.back()] > a[i])s.pop_back();
        int j = s.back();
        for (int k = ab::K - 1; k >= 0; k--)
        {
            if (j >= (1 << k) && stt.f[j - (1 << k) + 1][k] < a[i])j -= 1 << k;
        }
        res -= 1ll * (r[i] - i) * (s.back() - j);
        //cout<<j<<endl;
        s.push_back(i);
    }
    cout << res << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solves();
    }
    return 0;
}