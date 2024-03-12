//#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using ui64 = unsigned long long;
const i64 M = 1e9 + 7, N = 5e4 + 10;
;
string a = "helowrd";
string mod = " helloworld";
vector<int> mp[128];
string ab;
vector<i64> p(7);
long long qmi(long long k, long long p = M - 2, long long P = M)
{
    long long res = 1;
    while (p)
    {
        if (p & 1)
            res = res * k % P;
        k = k * k % P;
        p >>= 1;
    }
    return res;
}
struct Matrix
{
    static const int M=1e9+7, W=11;
    array<array<ui64,W>,W>val;
    Matrix()
    {
    }
    friend Matrix operator*(const Matrix A, const Matrix B)
    {
        Matrix C;
        for (int i = 0; i < W; i++)
            for (int j = i; j < W; j++)
                for (int k = i; k <= j; k++)
                {
                    C.val[i][j] += A.val[i][k] * B.val[k][j];
                }
        for (int i = 0; i < W; i++)
            for (int j = i; j < W; j++)
                C.val[i][j] %= M;
        return C;
    }
};
template <class Info> struct SegmentTree
{
    int n;
    vector<Info> info;
    SegmentTree(string &a)
    {
        n = a.size();
        info.resize(4 * n);
        function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (l == r)
            {
                info[p].init(a[l - 1]);
                return;
            }
            int mid = l + r >> 1;
            build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
            info[p] = info[p << 1] + info[p << 1 | 1];
        };
        build(1, 1, n);
    }
    void modify(int p, int l, int r, int x, char c)
    {
        if (x == l && l == r)
        {
            info[p].init(c);
            return;
        }
        int mid = l + r >> 1;
        if (x <= mid)
            modify(p << 1, l, mid, x, c);
        else
            modify(p << 1 | 1, mid + 1, r, x, c);
        info[p] = info[p << 1] + info[p << 1 | 1];
    }
    void modify(int x, char c)
    {
        // cerr<<x<<c;
        modify(1, 1, n, x, c);
    }
    Info query(int p, int l, int r, int ll, int rr)
    {

        if (ll == l && rr == r)
        {
            return info[p];
        }
        int mid = l + r >> 1;
        if (ll <= mid && rr <= mid)
            return query(p << 1, l, mid, ll, min(rr, mid));
        else if (rr > mid && ll > mid)
            return query(p << 1 | 1, mid + 1, r, max(ll, mid + 1), rr);
        else
            return query(p << 1, l, mid, ll, min(rr, mid)) + query(p << 1 | 1, mid + 1, r, max(ll, mid + 1), rr);
    }
    Info query(int l, int r)
    {
        return query(1, 1, n, l, r);
    }
};
struct Info
{
    Matrix mat;
    Info()
    {
    }
    void init(char ch)
    {
        mat.val[0][0] = 1;
        if (ch == '0')
        {
            for (int i = 1; i < 11; i++)
            {
                mat.val[i - 1][i] = p[a.find(mod[i])];
                mat.val[i][i] = 1;
            }
        }
        else
        {
            for (int i = 1; i < 11; i++)
            {
                if (ch == mod[i])
                    mat.val[i - 1][i] = 1;
                else
                    mat.val[i - 1][i] = 0;
                mat.val[i][i] = 1;
            }
        }
    }
    friend Info operator+(const Info &a, const Info &b)
    {
        Info ans;
        ans.mat = a.mat * b.mat;
        return ans;
    }
};

void solve()
{
    int n;
    cin >> n;
    ab.assign(n, '0');

    i64 all = 0;
    for (int i = 0; i < 7; i++)
    {
        cin >> p[i];
        all += p[i];
    }
    for (int i = 0; i < 7; i++)
    {
        p[i] = p[i] * qmi(all) % M;
    }
    SegmentTree<Info> seg(ab);
    int q;
    cin >> q;
    while (q--)
    {
        int flag;
        cin >> flag;
        if (flag == 1)
        {
            int x;
            char ch;
            cin >> x >> ch;
            seg.modify(x, ch);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            auto get = seg.query(l, r);
            Matrix ans;
            ans.val[0][0] = 1;
            ans = ans * get.mat;
            cout << ans.val[0][10] << '\n';
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
   // cout << setprecision(15) << fixed;
    int t;
    cin >> t;
    mp['h'].push_back(0);
    mp['e'].push_back(1);
    mp['l'].push_back(2), mp['l'].push_back(3), mp['l'].push_back(8);
    mp['o'].push_back(4), mp['o'].push_back(6);
    mp['w'].push_back(5);
    mp['r'].push_back(7);
    mp['d'].push_back(9);
    while (t--)
    {
        solve();
    }
    return 0;
}