#include <bits/stdc++.h>
const int bug = true;
#define dug(x)                                                                                                         \
    if (bug)                                                                                                           \
    cerr << "死了吧小丑" << x << endl
#define fir(i, a, b) for (int i = a; i < b; i++)
#define far(a, b) for (auto a : b)
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
const double PI = acos(-1.0);
int uu = 0;
struct Complex
{
    double x, y;
    static int I_mul_I;
    Complex(double _x = 0.0, double _y = 0.0)
    {
        x = _x;
        y = _y;
    }

    Complex operator-(const Complex &b) const
    {
        return Complex(x - b.x, y - b.y);
    }

    Complex operator+(const Complex &b) const
    {
        return Complex(x + b.x, y + b.y);
    }

    Complex operator*(const Complex &b) const
    {
        return Complex(x * b.x + y * b.y * I_mul_I, x * b.y + y * b.x);
    }
    Complex operator%(int &P) const
    {
        return Complex((i64)x % P, (i64)y % P);
    }
};
int Complex::I_mul_I = -1;
struct poly
{
    int size;
    static const int P = 998244353;
    vector<i64> _a; // 系数
    static vector<i64> r;
    poly()
    {
    }
    poly(int le)
    {
        _a.resize(le);
    }
    poly(vector<i64> a)
    {
        _a = a;
    }
    static i64 qmi(i64 k, i64 p)
    {
        i64 res = 1;
        while (p)
        {
            if (p & 1)
                res = res * k % P;
            k = k * k % P;
            p >>= 1;
        }
        return res;
    }
    static void change(vector<Complex> &y, int len)
    {
        int i, j, k;
        for (int i = 1, j = len / 2; i < len - 1; i++)
        {
            if (i < j)
                std::swap(y[i], y[j]);
            // 交换互为小标反转的元素，i<j 保证交换一次
            // i 做正常的 + 1，j 做反转类型的 + 1，始终保持 i 和 j 是反转的
            k = len / 2;
            while (j >= k)
            {
                j = j - k;
                k = k / 2;
            }
            if (j < k)
                j += k;
        }
    }
    static void fft(vector<Complex> &y, int len, int on)
    {
        change(y, len);

        for (int h = 2; h <= len; h <<= 1)
        {
            Complex wn(cos(2 * PI / h), sin(on * 2 * PI / h));

            for (int j = 0; j < len; j += h)
            {
                Complex w(1, 0);

                for (int k = j; k < j + h / 2; k++)
                {
                    Complex u = y[k];
                    Complex t = w * y[k + h / 2];
                    y[k] = u + t;
                    y[k + h / 2] = u - t;
                    w = w * wn;
                }
            }
        }
        if (on == -1)
        {
            for (int i = 0; i < len; i++)
            {
                y[i].x /= len;
            }
        }
    }
    static void ntt(vector<i64> &x, int lim, int opt)
    {
        for (int i = 0; i < lim; ++i)
            if (r[i] < i)
                swap(x[i], x[r[i]]);
        for (int m = 2; m <= lim; m <<= 1)
        {
            int k = m >> 1;
            int gn = qmi(3, (P - 1) / m);
            for (int i = 0; i < lim; i += m)
            {
                int g = 1;
                for (int j = 0; j < k; ++j, g = 1ll * g * gn % P)
                {
                    int tmp = 1ll * x[i + j + k] * g % P;
                    x[i + j + k] = (x[i + j] - tmp + P) % P;
                    x[i + j] = (x[i + j] + tmp) % P;
                }
            }
        }
        if (opt == -1)
        {
            reverse(x.begin() + 1, x.begin() + lim);
            int inv = qmi(lim, P - 2);
            for (int i = 0; i < lim; ++i)
                x[i] = 1ll * x[i] * inv % P;
        }
    }
    static poly mul(poly const &a, poly const &b)
    {
        int len = 1;
        while (len < b._a.size() << 1 || len < a._a.size() << 1)
            len <<= 1;
        r.resize(len);
        for (int i = 0; i < len; ++i)
            r[i] = (i & 1) * (len >> 1) + (r[i >> 1] >> 1);
        vector<i64> x(len), y(len);
        for (int i = 0; i < a._a.size(); i++)
            x[i] = a._a[i];
        for (int i = 0; i < a._a.size(); i++)
            y[i] = b._a[i];
        ntt(x, len, 1), ntt(y, len, 1);
        for (int i = 0; i < len; i++)
            x[i] = (x[i] * y[i]) % P;
        ntt(x, len, -1);
        return poly(x);
    }
    poly operator*(poly const &v) const
    {
        int len = 1;
        while (len < _a.size() << 1 || len < v._a.size() << 1)
            len <<= 1;
        vector<Complex> a(len, Complex(0.0, 0.0)), b(len, Complex(0.0, 0.0));
        for (int i = 0; i < _a.size(); i++)
            a[i].x = _a[i];
        for (int i = 0; i < _a.size(); i++)
            b[i].x = v._a[i];
        fft(a, len, 1), fft(b, len, 1);
        for (int i = 0; i < len; i++)
            a[i] = a[i] * b[i];
        fft(a, len, -1);
        poly tem(len);
        for (int i = 0; i < len; i++)
        {
            i64 te = i64(a[i].x + 0.5);
            tem._a[i] = te;
        }
        // if (tem._a.size() > 0 && tem._a.back() == 0)
        //     tem._a.pop_back();
        // tem.size = tem._a.size();
        return tem;
    }
};
vector<i64> poly::r;
struct Graph // 有向图
{
    std::vector<int> e, ne, h, w;
    int idx = 0;
    int node_size, edge_size;
    Graph()
    {
    }
    Graph(int n, int m)
    {
        init(n, m);
    }
    void init(int n, int m)
    {
        node_size = n;
        edge_size = m;
        idx = 0, e.resize(m), ne.resize(m), w.resize(m);
        h.resize(n, -1);
    }
    void add(int a, int b)
    {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }
    void add(int a, int b, int c)
    {
        w[idx] = c, e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }
    void clear(int si = 0) // 清空图
    {
        if (si == 0)
            si = node_size;
        idx = 0;
        fill(h.begin(), h.begin() + si, -1);
    }
    void dfs(int u, int fath = -1)
    {
        for (int i = h[u]; ~i; i = ne[i])
        {
            int j = e[i];
            if (j != fath)
            {
                dfs(j, u);
            }
        }
    }
};
struct UNdigraph : Graph // 无向图
{
    static const int W = 25;
    vector<array<int, W>> fa;
    vector<int> depth;
    bool is_use;
    int root;
    UNdigraph()
    {
    }
    UNdigraph(int n, int m) : Graph(n, 2 * m)
    {
        node_size = n, edge_size = m;
        is_use = false;
        root = 0;
    }
    void dfs(int u, int fath)
    {
        fa[u][0] = fath, depth[u] = depth[fath] + 1;
        // cerr<<depth[u]<<" "<<u<<endl;
        for (int i = 1; i < W; i++)
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        for (int i = h[u]; ~i; i = ne[i])
        {
            int j = e[i];
            if (j != fath)
            {
                dfs(j, u);
            }
        }
    }
    int lca(int x, int y)
    {
        if (!is_use)
        {
            // cerr<<node_size;
            depth.resize(node_size);
            fa.resize(node_size);
            dfs(root, root);
            is_use = true;
        }
        if (depth[x] < depth[y])
            swap(x, y);
        for (int i = __lg(depth[x]); ~i; i--)
        {
            if (depth[fa[x][i]] >= depth[y])
                x = fa[x][i];
        }
        // cout<<x<<y<<endl;
        if (x == y)
            return x;
        for (int i = __lg(depth[x]); ~i; i--)
        {
            if (fa[x][i] != fa[y][i])
            {
                x = fa[x][i], y = fa[y][i];
            }
        }
        return fa[x][0];
    }
    void insert(int a, int b)
    {
        add(a, b), add(b, a);
    }
    void insert(int a, int b, int c)
    {
        add(a, b, c), add(b, a, c);
    }

    vector<int> cut_point() // 割点
    {
        vector<int> dfn(node_size), low(node_size), vis(node_size), flag(node_size);
        int inde, res;

        function<void(int, int)> Tarjan = [&](int u, int father) { // u 当前点的编号，father 自己爸爸的编号
            vis[u] = true;                                         // 标记
            low[u] = dfn[u] = ++inde;                              // 打上时间戳
            int child = 0;                                         // 每一个点儿子数量
            for (int i = h[u]; ~i; i = ne[i])
            {
                int v = e[i];
                if (!vis[v])
                {
                    child++;                      // 多了一个儿子
                    Tarjan(v, u);                 // 继续
                    low[u] = min(low[u], low[v]); // 更新能到的最小节点编号
                    if (father != u && low[v] >= dfn[u] && !flag[u])
                    {
                        flag[u] = true;
                        res++; // 记录答案
                    }
                }
                else if (v != father)
                    low[u] = min(low[u], dfn[v]); // 如果这个点不是自己，更新能到的最小节点编号
            }
            if (father == u && child >= 2 && !flag[u])
            {
                flag[u] = true;
                res++; // 记录答案
            }
        };
        for (int i = 0; i < node_size; i++)
        {
            if (!vis[i])
            {
                inde = 0;
                Tarjan(i, i);
            }
        }
        vector<int> p;
        for (int i = 0; i < node_size; i++)
            if (flag[i])
                p.push_back(i);
        return p;
    };
    vector<int> cut_edge()
    {
        vector<int> dfn(node_size), low(node_size), vis(node_size), bridge(edge_size);
        int inde, res;
        function<void(int, int)> tarjan = [&](int x, int in_edge) {
            dfn[x] = low[x] = ++inde;
            for (int i = h[x]; ~i; i = ne[i])
            {
                int y = e[i];
                if (!dfn[y])
                {
                    tarjan(y, i);
                    low[x] = min(low[x], low[y]);
                    if (low[y] > dfn[x])
                        bridge[i / 2] = true;
                }
                else if (i != (in_edge ^ 1))
                    low[x] = min(low[x], dfn[y]);
            }
        };
        for (int i = 0; i < node_size; i++)
        {
            if (!vis[i])
            {
                inde = 0;
                tarjan(i, i);
            }
        }
        vector<int> p;
        for (int i = 0; i < edge_size; i++)
            if (bridge[i])
                p.push_back(i);
        return p;
    }
    friend istream &operator>>(istream &in, UNdigraph &gra)
    {
        // TODO: 在此处插入 return 语句
        for (int i = 0; i < gra.edge_size; i++)
        {
            int a, b;
            cin >> a >> b;
            a--, b--;
            gra.insert(a, b);
        }
        return in;
    }
};
struct Point_divide : UNdigraph // 点分治
{
    vector<int> vis, siz, mx;
    vector<i64> ans;
    queue<int> q;
    Point_divide(int n) : UNdigraph(n, n - 1)
    {
        root = -1;
        vis.resize(n);
        siz.resize(n);
        mx.resize(n);
        ans.resize(n);
    }
    void get_dis(int u, int fa, int dis)
    {
        q.push(dis);
        for (int i = h[u]; ~i; i = ne[i])
        {
            int j = e[i];
            if (j == fa || vis[j])
                continue;
            get_dis(j, u, dis + 1);
        }
    }
    void calc(int u)
    {
        uu = u;
        poly x(siz[u] + 1), y(siz[u] + 1);
        queue<int> p;
        // if(u==6)cerr<<y._a.size()<<endl;
        for (int i = h[u]; ~i; i = ne[i])
        {
            int j = e[i];
            if (vis[j])
                continue;
            get_dis(j, u, 1);
            while (q.size())
            {
                p.push(q.front());
                ans[q.front()]++;
                y._a[q.front()]++;
                q.pop();
            }
            auto c = x * y;
            for (int i = 1; i < c._a.size() && i < ans.size(); i++)
                ans[i] += c._a[i];
            while (p.size())
            {
                x._a[p.front()]++;
                y._a[p.front()]--;
                p.pop();
            }
        }
        cerr << u << "kll" << endl;
        return;
    }
    void find(int u, int fa = -1)
    {
        siz[u] = 1, mx[u] = 0;
        for (int i = h[u]; ~i; i = ne[i])
        {
            int j = e[i];
            if (j == fa || vis[j])
                continue;
            find(j, u);
            siz[u] += siz[j];
            chkmax(mx[u], siz[j]);
        }
        chkmax(mx[u], node_size - siz[u]);
        if (root < 0 || mx[u] < mx[root])
        {
            root = u;
        }
        return;
    }
    void solve(int u)
    {
        // cerr << u << endl;
        vis[u] = true;
        calc(u);
        cerr << u << endl;
        for (int i = h[u]; ~i; i = ne[i])
        {
            int j = e[i];
            if (vis[j])
                continue;
            root = -1;
            node_size = siz[j];
            find(j, -1);
            find(root, -1);
            solve(j);
        }
    }
    void work()
    {
        find(0, -1);
        find(root, -1);
        solve(root);
    }
};
vector<int> euler_function(i64 x)
{
    vector<int> q, s(x + 1), idx;
    vector<int> st(x + 1);
    st[1] = true;
    s[1] = 1;
    for (int i = 2; i <= x; i++)
    {
        if (!st[i])
            q.push_back(i), s[i] = i - 1;
        for (int j = 0; q[j] <= x / i; j++)
        {
            st[q[j] * i] = true;
            if (i % q[j] == 0)
            {
                s[q[j] * i] = s[i] * q[j];
                break;
            }
            s[q[j] * i] = s[i] * (q[j] - 1);
        }
    }
    return st;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin >> n;
    Point_divide po(n);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        po.insert(a, b);
    }
    po.work();
    i64 sum1 = 0, sum2 = 0;
    auto st = euler_function(n);
    for (int i = 1; i < n; i++)
    {
        sum1 += po.ans[i];
        if (!st[i])
            sum2 += po.ans[i];
    }
    // cout<<sum2<<endl;
    cout << 1.0 * sum2 / sum1 << endl;
    return 0;
}
/*30
1 2
1 3
1 4
3 5
3 6
4 7
2 8
2 9
4 10
6 11
11 12
11 13
9 14
3 15
6 16
7 17
7 18
18 19
2 20
1 21
13 22
5 23
20 24
12 25
24 26
26 27
25 28
7 29
18 30
*/