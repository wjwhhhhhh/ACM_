#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
template <class T> void chkmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
}
template <class T> void chkmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
}
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
    virtual void p(T &x, T c)
    {
        x += c;
    }
};
const int N = 5e5;
using ui64 = unsigned long long;
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
const int M = 1e9 + 7;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin >> n;
    vector<i64> s(N + 1);
    vector<array<int, 4>> a(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 4; j++)
            cin >> a[i][j];
    vector<int> q(N + 1);
    for (int i = 0; i < n; i++)
    {
        if (a[i][0] > a[i][3] || a[i][1] < a[i][2])
        {
            q[a[i][0]] += 1, q[a[i][1] + 1] -= 1;
            q[a[i][2]] += 1, q[a[i][3] + 1] -= 1;
        }
        else
        {
            int l = min(a[i][0], a[i][2]), r = max(a[i][1], a[i][3]);
            q[l]++, q[r + 1]--;
        }
    }
    for (int i = 1; i <= N; i++)
        q[i] += q[i - 1];
    set<int> has;
    for (int i = 1; i <= N; i++)
    {
        if (q[i] == n)
            has.insert(i);
    }
    cout << mp.size() << endl;
    vector<int> sh(N + 1);
    for (int i = 0; i < n; i++)
    {
        if (a[i][0] > a[i][3] || a[i][1] < a[i][2])
        {
            continue;
        }
        else
        {
            int l = max(a[i][0], a[i][2]);
            int id = mp[s[l]] * 2 % M;
            mp[s[l]] = id;
        }
    }
    i64 ans = 0;
    for (auto [_, x] : mp)
    {
        ans = (ans + x) % M;
    }
    cout << ans << endl;
    return 0;
}