#include <bits/stdc++.h>
using namespace std;
using i64=long long;
// #define read(x) scanf("%d",&x)
typedef long long LL;
typedef std::pair<int, int> PII;
struct SAM
{
    struct state
    {
        int len, link;
        int next[26];
        state()
        {
            for (int i = 0; i < 26; i++)
                next[i] = -1;
        }
    };
    vector<state> st;
    int sz,last;
    SAM(int n)
    {
        vector<state>st(2*n);
        sam_init();
    }
    void sam_init()
    {
        st[0].len = 0;
        st[0].link = -1;
        sz++;
        last = 0;
    }
    void sam_extend(char ch)
    {
        int c = ch - 'a';
        int cur = sz++;
        st[cur].len = st[last].len + 1;
        int p = last;
        while (p != -1 && !st[p].next[c])
        {
            st[p].next[c] = cur;
            p = st[p].link;
        }
        if (p == -1)
        {
            st[cur].link = 0;
        }
        else
        {
            int q = st[p].next[c];
            if (st[p].len + 1 == st[q].len)
            {
                st[cur].link = q;
            }
            else
            {
                int clone = sz++;
                st[clone].len = st[p].len + 1;
                for (int i = 0; i < 26; i++)
                    st[clone].next[i] = st[q].next[i];
                st[clone].link = st[q].link;
                while (p != -1 && st[p].next[c] == q)
                {
                    st[p].next[c] = clone;
                    p = st[p].link;
                }
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    SA sa;
    cin>>sa.s;
    int n=sa.s.size();
    sa.work();
    for(int i=1;i<=n;i++)
    {
        
    }
    return 0;
}