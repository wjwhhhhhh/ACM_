#include <bits/stdc++.h>
using namespace std;
struct Tire // 在树上维护异或值
{
    static const int W = 2;
    static const int MAXH = 22; // 最剩的深度
    int tot;                    // 0其实没用
    vector<array<int, W>> ch; // ch[o][0/1] 指节点 o 的两个儿子，ch[o][0] 指下一位是 0，同理 ch[o][1] 指下一位是 1。
    vector<int> w; // w[o] 指节点 o 到其父亲节点这条边上数值的数量（权值）。每插入一个数字 x，x 二进制拆分后在 trie 上
    // 路径的权值都会 +1。
    vector<int> xorv; // xorv[o] 指以 o 为根的子树维护的异或和
    vector<int> rt;   // 不同tire的root
    Tire(){};
    Tire(int n)
    {
        init(n);
    }
    void init(int n) // 初始化
    {
        ch.resize(n * (MAXH + 1)); // 根据需要修改
        w.resize(n * (MAXH + 1));
        xorv.resize(n * (MAXH + 1));
        rt.resize(n * (MAXH + 1));
    }
    virtual int mknode() // 增加节点
    {
        ++tot;
        ch[tot][1] = ch[tot][0] = w[tot] = xorv[tot] = 0;
        return tot;
    }

    virtual void maintain(int o) // 维护节点值
    {
        w[o] = xorv[o] = 0;
        if (ch[o][0])
        {
            w[o] += w[ch[o][0]];
            xorv[o] ^= xorv[ch[o][0]] << 1;
        }
        if (ch[o][1])
        {
            w[o] += w[ch[o][1]];
            xorv[o] ^= (xorv[ch[o][1]] << 1) | (w[ch[o][1]] & 1);
        }
        w[o] = w[o] & 1;
    }

    virtual void insert(int x, int &o, int dp = 0) // 插入节点，x为权重，dp为深度
    {
        if (!o)
            o = mknode();
        if (dp > MAXH)
            return (void)(w[o]++);
        insert(x >> 1, ch[o][x & 1], dp + 1);
        maintain(o);
    }

    virtual void erase(int x, int o = 0, int dp = 0)
    {
        if (dp > MAXH)
            return (void)(w[o]--);
        erase(x >> 1, ch[o][x & 1], dp + 1);
        maintain(o);
    }
    int merge(int a, int b) // 合并两个tire
    {
        if (!a)
            return b; // 如果 a 没有这个位置上的结点，返回 b
        if (!b)
            return a; // 如果 b 没有这个位置上的结点，返回 a
        /*
          如果 `a`, `b` 都存在，
          那就把 `b` 的信息合并到 `a` 上。
        */
        w[a] = w[a] + w[b];
        xorv[a] ^= xorv[b];
        /* 不要使用 maintain()，
          maintain() 是合并a的两个儿子的信息
          而这里需要 a b 两个节点进行信息合并
         */
        ch[a][0] = merge(ch[a][0], ch[b][0]);
        ch[a][1] = merge(ch[a][1], ch[b][1]);
        return a;
    }
    void addall(int o)
    {
        swap(ch[o][0], ch[o][1]);
        if (ch[o][0])
            addall(ch[o][0]);
        maintain(o);
    }
};
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
        idx = 0, e.resize(m), ne.resize(m), w.resize(2 * n);
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
        fill(h.begin(), h.begin() + si, -1);
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
const int N = 525020;
int root = 1;
long long ans = 0;
UNdigraph gra(N);
Tire trie(N);
int v[N];
void dfs(int u, int fath = -1)
{
    for (int i = gra.h[u]; ~i; i = gra.ne[i])
    {
        int j = gra.e[i];
         if (j != fath)
        {
            dfs(j, u);
            trie.rt[u] = trie.merge(trie.rt[u], trie.rt[j]);
        }
    }
    trie.addall(trie.rt[u]);
    trie.insert(v[u], trie.rt[u]);
    ans += trie.xorv[trie.rt[u]];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 2; i <= n; i++)
    {
        int tem;
        cin >> tem;
        gra.add(tem, i);
    }
    dfs(root);
    cout << ans << endl;
    return 0;
}