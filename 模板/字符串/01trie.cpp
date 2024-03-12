#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct Tire // 在树上维护异或值
{
    static const int W = 2;
    static const int MAXH = 25; // 最剩的深度
    int tot;
    vector<array<int, W>> ch; // ch[o][0/1] 指节点 o 的两个儿子，ch[o][0] 指下一位是 0，同理 ch[o][1] 指下一位是 1。
    vector<int> w; // w[o] 指节点 o 到其父亲节点这条边上数值的数量（权值）。每插入一个数字 x，x 二进制拆分后在 trie 上
                   // 路径的权值都会 +1。
    vector<int> xorv; // xorv[o] 指以 o 为根的子树维护的异或和
    vector<int> rt;   // 根
    Tire(){};
    Tire(int n)    {
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

    virtual void insert(int &o, int x, int dp = 0) // 插入节点，x为权重，dp为深度
    {
        if (!o)
            o = mknode();
        if (dp > MAXH)
            return (void)(w[o]++);
        insert(ch[o][x & 1], x >> 1, dp + 1);
        maintain(o);
    }

    virtual void erase(int o, int x, int dp = 0)
    {
        if (dp > MAXH)
            return (void)(w[o]--);
        erase(ch[o][x & 1], x >> 1, dp + 1);
        maintain(o);
    }
    int merge(int a, int b)
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
