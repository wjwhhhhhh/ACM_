#include <bits/stdc++.h>
using namespace std;

const int N = 12;
const int offset = 3, mask = (1 << offset) - 1; // 111
int n, m;
__int128 ans;
const int MaxSZ = 16796, Prime = 9973;
__int128 b[N + 1], bb[N + 1];
__int128 encode() // 就是把bb变成一个数字来存储
{
    __int128 s = 0;
    memset(bb, -1, sizeof bb);
    int bn = 1; // 最小轮到几了
    bb[0] = 0;
    for (int i = m; i >= 0; i--)
    {
        // 因为初始化为了-1，所以这个用来判断是不是-1
        if (!~bb[b[i]])
            bb[b[i]] = bn++;
        s <<= offset;
        s |= bb[b[i]]; // 其实就是加法
    }
    return s;
}
void decode(__int128 s) // 解码，把s变为b数组，感觉是原bb更合适
{
    for (int i = 0; i < m + 1; i++)
    {
        b[i] = s & mask;
        s >>= offset;
    }
}
struct hashTable
{
    int head[Prime], ne[MaxSZ], sz; // sz就是哈希表的数量
    __int128 state[MaxSZ];         // 就是记下这个节点的状态，就是s
    __int128 key[MaxSZ];
    inline void clear()
    {
        sz = 0;
        memset(head, -1, sizeof head);
    }
    inline void push(__int128 s, __int128 d)
    {
        int x = s % Prime;
        for (int i = head[x]; ~i; i = ne[i])
        {
            if (state[i] == s)
            {
                key[i] += d;
                return; // 找到了要转的变量，肯定直接return
            }
        }
        // 如果没有找到就要新开一个节点
        state[sz] = s, key[sz] = d;
        ne[sz] = head[x];
        head[x] = sz++;
    }
    inline void roll()
    {
        for (int i = 0; i < sz; i++)
            state[i] <<= offset;
    }
} H[2], *H0, *H1;                             // 用来替代那个滚动数组
void push(int j, int dn, int rt, __int128 d) // dn为第一个要改的,rt为第二个
{
    b[j] = dn;
    b[j + 1] = rt;
    H1->push(encode(), d);
}
void print(__int128 x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}
signed main()
{
    cin >> n >> m;
    if (m > n)
        swap(n, m);
    H0 = H, H1 = H + 1;
    H1->clear();
    H1->push(0, 1); // 初始为就啥都没的时候为1很正常
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            swap(H0, H1);
            H1->clear();
            for (int ii = 0; ii < (H0->sz); ii++)
            {
                decode(H0->state[ii]);
                __int128 d = H0->key[ii];
                int lt = b[j], up = b[j + 1];
                bool dn = i != n - 1, rt = j != m - 1;
                if (lt && up)
                {
                    if (lt == up)
                    {
                        if (i == n - 1 && j == m - 1)
                            push(j, 0, 0, d);
                    }
                    else
                    {
                        for (int i = 0; i < m + 1; i++)
                        {
                            if (b[i] == lt)
                                b[i] = up;
                        }
                        push(j, 0, 0, d);
                    }
                }
                else if (lt || up)
                {
                    int t = lt | up; // 就是唯一的那个插头的编号
                    if (dn)
                    {
                        push(j, t, 0, d);
                    }
                    if (rt)
                    {
                        push(j, 0, t, d);
                    }
                }
                else
                {
                    if (dn && rt)
                    {
                        push(j, m, m, d); // m这个编号一定没有用
                    }
                }
            }
        }
        H1->roll();
    }
    // assert(0);
    if(n==1||m==1)cout<<1<<endl;
    else 
    {
        ans=  (H1->sz == 1 ? H1->key[0] : 0)*(__int128)2;
        print(ans);
    }
    return 0;
}