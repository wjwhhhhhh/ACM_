#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
template <class Info, class Tag>
struct LazySegmentTree {
    int n;
    std::vector<Info> tr;
    std::vector<Tag> tag;
    LazySegmentTree() {}
    LazySegmentTree(int n) {
        init(n);
    }
    LazySegmentTree(std::vector<Info> w) {
        init(w);
    }
    void init(int n) {
        this->n = n;
        tr.resize(4 << std::__lg(n));
        tag.resize(4 << std::__lg(n));
    }
    void init(std::vector<Info> w) {
        init(w.size());
        auto build = [&](auto self, int p, int l, int r) {
            if (r - l == 1) {
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

    void pull(int p) {
        tr[p] = tr[p * 2] + tr[p * 2 + 1];
    }

    void apply(int p, const Tag& t) {
        tr[p].apply(t);
        tag[p].apply(t);
    }

    void push(int p) {
        apply(2 * p, tag[p]);
        apply(2 * p + 1, tag[p]);
        tag[p] = Tag();
    }

    void modify(int p, int l, int r, int x, const Info& v) {
        if (r - l == 1) {
            tr[p] = v;
            return;
        }
        int m = (l + r) / 2;
        push(p);
        if (x < m) {
            modify(2 * p, l, m, x, v);
        }
        else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }

    void modify(int p, const Info& v) {
        modify(1, 0, n, p, v);
    }

    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return tr[p];
        }
        push(p);
        int m = (l + r) / 2;
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }

    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }

    void rangeApply(int p, int l, int r, int x, int y, const Tag& t) {
        if (l >= y || r <= x) {
            return;
        }
        if (l >= x && r <= y) {
            apply(p, t);
            return;
        }
        push(p);
        int m = (l + r) / 2;

        rangeApply(2 * p, l, m, x, y, t);
        rangeApply(2 * p + 1, m, r, x, y, t);

        pull(p);
    }

    void rangeApply(int l, int r, const Tag& t) {
        return rangeApply(1, 0, n, l, r, t);
    }
};
struct Tag {
    ll x;
    Tag(ll x = 0): x(x) {}
    void apply(const Tag& t) {
        x += t.x;
    }
};

struct Info {
    ll x;
    Info(ll x = 0): x(x) {}
    void apply(const Tag& t, int len) {
        x += t.x * len;
    }
};

Info operator+ (const Info& a, const Info& b) {
    return Info(a.x + b.x);
}
struct Graph // 有向图
{
    std::vector<int> e, ne, h, w;
    int idx = 0;
    int node_size;
    Graph()
    {
    }
    Graph(int n)
    {
        init(n);
    }
    Graph(int n, int m)
    {
        init(n, m);
    }
    void init(int n)
    {
        node_size = n;
        idx = 0;
        e.resize(2 * n), ne.resize(2 * n), w.resize(2 * n);
        h.resize(n, -1);
    }
    void init(int n, int m)
    {
        node_size = n;
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
    UNdigraph()
    {
    }
    UNdigraph(int a) : Graph(a)
    {
    }
    UNdigraph(int n, int m) : Graph(n, m)
    {
    }
    void insert(int a, int b)
    {
        add(a, b), add(b, a);
    }
    void insert(int a, int b, int c)
    {
        add(a, b, c), add(b, a, c);
    }
};
const int N = 1e5 + 10;
int id[N];
int rk[N];
int f[N][26];
int si = 2;
vector < LazySegmentTree<Info, Tag> la(N);
// int
void dfs(int u, int fa)
{
    vector<Info> son;
    int tem=0,tt=id[u];//儿子，本
    for (int i = gra.h[u]; ~i; i = gra.ne[i])
    {
        int j = gra.e[i];
        if (j == fa)continue;
        dfs(j,u);
        id[j] = si;
        tem=id[j];
        son.push_back(j);//
    }
    if (son.size())
    {
        la[si].init(son);
        for (int i = 0; i < son.size(); i++)
        {
            rk[son[i]] = i;
        }
        si++;
    }
    f[tt][0]=tem;
    for(int i=1;i<26;i++)
    {
        f[tt][i]=f[f[tt][i-1]][i-1];
    }
}
int get(int x,int k)
{
    for(int i=25;~i;i++)
    {
        if(k>=(1<<i))
            {
                x=f[x][i];
                k-=(1<<i);
            }
    }
    return x;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    UNdigraph gra(n);

    vector<int> a(n);
    for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        gra.insert(a, b);
    }
    id[0]=1;
    dfs(0, -1);
    int q;
    cin>>q;
    while(q--)
    {
        int flag;
        cin>>flag;
        if(flag==1)
        {
            int p,x;
            cin>>p>>x;
            if(p==1)continue;
            p--;
            int it=id[p];
            la[it].modify(rk[p],x);
        }
        else if(flag==2)
        {
            int p,k,x;
            cin>>p>>k>>x;
            int fl=get(id[p-1],k);
            if(fl)
            {
                la[fl].rangeApply1(0, la[fl].n, x);
            }
        }
        else if(flag==3)
        {
            int p,k,x;
            cin>>p>>k>>x;
            int fl=get(id[p-1],k);
            if(fl)
            {
                la[fl].rangeApply2(0, la[fl].n, x);
            }
        }
        else if(flag==4)
        {
            int p,x;
            cin>>p>>x;
            if(p==1)continue;
            p--;
            int it=id[p];
            std::cout << la[it].rangeQuery(rk[p], rk[p] + 1).x << '\n';
        }
        else
        {
            int p,k,x;
            cin>>p>>k>>x;
            int fl=get(id[p-1],k);
            if(fl)
            {
                std::cout << la[fl].rangeQuery(0, la[fl].n).x << '\n';
            }
        }
    }
    return 0;
}