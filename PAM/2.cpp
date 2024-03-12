#include <bits/stdc++.h>
using namespace std;
struct PAM
{
    static int M;
    int sz, tot, last;
    vector<int> cnt, len, fail;//本质不同出现的次数
    vector<array<int, 26>> ch;
    vector<char> s;
    PAM()
    {
    }
    PAM(int n) // 开大点
    {
        init(n);
    }
    int node(int l)
    {
        sz++;
        fill(ch[sz].begin(), ch[sz].end(), 0);
        len[sz] = l;
        fail[sz] = cnt[sz] = 0;
        return sz;
    }
    void init(int n)
    {
        cnt.resize(n), len.resize(n), fail.resize(n);
        ch.resize(n), s.resize(n);
        clear();
    }
    void clear()
    {
        sz = -1, last = 0;
        s[tot = 0] = '$';
        node(0);
        node(-1);
        fail[0] = 1;
    }
    int getfail(int x)
    {
        while (s[tot - len[x] - 1] != s[tot])
            x = fail[x];
        return x;
    }
    void insert(char c)
    {
        s[++tot] = c;
        int now = getfail(last);
        if (!ch[now][c - 'a'])
        {
            int x = node(len[now] + 2);
            fail[x] = ch[getfail(fail[now])][c - 'a'];
            ch[now][c - 'a'] = x;
            cnt[x]=cnt[fail[x]]+1;
        }
        last = ch[now][c - 'a'];
    }
    long long solve()
    {
        long long ans=0;
        for(int i=sz;i>=2;i--)
        {
            cnt[fail[i]]+=cnt[i];
        }
        for(int i=2;i<=sz;i++)
        {
             ans = max(ans, 1ll * len[i] * cnt[i]);
        }
        return ans;
    }
};
const int N=5e5+10;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.txt", "r", stdin);
    PAM pan(N);
    string a;
    cin>>a;
    for(int i=0;i<a.size();i++)
    {
        if(i)a[i]=(a[i]-97+a[i-1])%26+97;
        pan.insert(a[i]);
        cout<<pan.cnt[pan.last]<<" ";
    }
    cout<<pan.solve()<<endl;
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}