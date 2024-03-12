#include <bits/stdc++.h>
using namespace std;
// #define int long long
//  #define int __int128
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define dug cout << "ceshi" << endl;
#define met(x, y) memset(x, y, sizeof x)
const int inf = 1e8;
// #define read(x) scanf("%d",&x)
typedef long long LL;
typedef std::pair<int, int> PII;
const int N = 1e5 + 10;

int f[N];
int ans[N];
vector<PII> dt;
map<int, int> wei;

struct Max
{
    int x;
    Max(int x = -inf * 3) : x(x)
    {
    }
    Max operator+(const Max &rhs)
    {
        return std::max(x, rhs.x);
    }
};

template <class Info> struct SegmentTree
{
    int n;
    std::vector<Info> tr;

    SegmentTree()
    {
    }
    SegmentTree(int n)
    {
        init(n);
    }
    SegmentTree(std::vector<Info> w)
    {
        init(w);
    }

    void init(int n)
    {
        this->n = n;
        tr.resize(4 << std::__lg(n));
    }

    void init(std::vector<Info> w)
    {
        init(w.size());
        auto build = [&](auto self, int p, int l, int r) {
            if (r - l == 1)
            {
                tr[p] = w[l];
                return;
            }
            int m = (l + r) / 2;
            self(self, 2 * p, l, m);
            self(self, 2 * p + 1, m, r);
            pull(p);
        };
        build(build, 1, 0, n);
    }

    void pull(int p)
    {
        tr[p] = tr[2 * p] + tr[2 * p + 1];
    }

    void modify(int p, int l, int r, int x, const Info &v)
    {
        if (r - l == 1)
        {
            tr[p] = v;
            return;
        }
        int m = (l + r) / 2;
        if (x < m)
        {
            modify(2 * p, l, m, x, v);
        }
        else
        {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }

    void modify(int p, const Info &v)
    {
        modify(1, 0, n, p, v);
    }

    Info rangeQuery(int p, int l, int r, int x, int y)
    {
        if (l >= y || r <= x)
        {
            return Info();
        }
        if (l >= x && r <= y)
        {
            return tr[p];
        }
        int m = (l + r) / 2;
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }

    Info rangeQuery(int l, int r)
    {
        return rangeQuery(1, 0, n, l, r);
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.txt", "r", stdin);
    int n;
    cin >> n;
    dt.push_back({-inf - 1, 0});
    SegmentTree<Max> seg(n + 1);
    fir(i, 1, n)
    {
        int a, b;
        cin >> a >> b;
        wei[a] = i;
        dt.push_back({a, b});
    }
    sort(dt.begin(), dt.end());
    // build(1, 1, n);
    for (int i = n; i > 0; i--)
    {
        PII h = {dt[i].first + dt[i].second, 0};
        auto aa = lower_bound(dt.begin(), dt.end(), h);
        int len = aa - dt.begin();
        int tem;
        if (i + 1 > len - 1)
            tem = -1;
        else
            tem = seg.rangeQuery(i + 1, len).x;
        if (tem == -1)
            ans[i] = 1;
        else
            ans[i] = tem - i + 1;
        f[i] = i + ans[i] - 1;
        seg.modify(i, f[i]);
        // update(1, i, f[i]);
    }
    for (int i = 1; i <= n; i++)
        f[wei[dt[i].first]] = ans[i];
    for (int i = 1; i <= n; i++)
        cout << f[i] << " ";
    return 0;
}