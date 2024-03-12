#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
struct DNA
{
    int fa, w, lw, rw, wm, lwm, rwm, sum;
    DNA()
    {
        fa = w = lw = rw = wm = lwm = rwm = sum = 0;
    }
};
struct Node
{
    DNA dna[26];
    int depth;
    void init(int v)
    {
        dna[0].w = max(0, v), dna[0].lw = max(0, v), dna[0].rw = max(0, v);
        dna[0].wm = min(0, v), dna[0].lwm = min(0, v), dna[0].rwm = min(0, v);
        dna[0].sum = v;
    }
} ;
void solve()
{
    bool st=false;
    int q;
    cin >> q;
    if(q!=8)st=true;
    vector<Node> node(q + 10);
    vector<int> lg(q+10);
    lg[0]=-1;
    for(int i=1;i<q+10;i++)lg[i]=lg[i>>1]+1;
    node[0].init(1);
    node[0].depth = 1;
    node[0].dna[0].fa = -1;
    int si = 0;
    auto change = [&](DNA & a, DNA & b, DNA & c) //c更右
    {
        a.w = max({0, b.w, c.w, b.rw + c.lw});
        a.rw = max({c.rw, 0, b.rw + c.sum});
        a.lw = max({b.lw, 0, b.sum + c.lw});
        a.wm = min({0, b.wm, c.wm, b.rwm + c.lwm});
        a.rwm = min({c.rwm, 0, b.rwm + c.sum});
        a.lwm = min({b.lwm, 0, b.sum + c.lwm});
        a.sum = b.sum + c.sum;
    };
    bool fl=false;
    auto lca = [&](int x, int y) -> std::pair<int, int>
    {

         if (node[x].depth < node[y].depth)swap(x, y),fl=true;
        for (int i = lg[node[x].depth-1]; ~i; i--)
        {
            if (node[node[x].dna[i].fa].depth >= node[y].depth)x = node[x].dna[i].fa,fl=true;
        }
        if (x == y)return make_pair(x,0);
        for (int i = lg[node[x].depth-1]; ~i; i--)
        {
            //cerr<<node[y].depth-1;
            if (node[x].dna[i].fa != node[y].dna[i].fa)
            {
                x = node[x].dna[i].fa, y = node[y].dna[i].fa;
            }
        }
        return make_pair(node[x].dna[0].fa,x);
    };
    auto check = [&](int x, int y)
    {
        if (node[x].depth > node[y].depth)swap(x, y);
        DNA an;
        int len = y;
        for (int i = __lg(node[y].depth - node[x].depth + 1); ~i; i--)
        {
            if (len >= x && node[len].depth - node[x].depth + 1 >= (1 << i))
            {
                DNA tem;
                change(tem, node[len].dna[i], an);
                an = tem;
                len = node[len].dna[i].fa;
            }
        }
        return an;
    };
    while (q--)
    {
        char flag;
        cin >> flag;
        if (flag == '+')
        {
            int v, x;
            cin >> v >> x;
            v--;
            node[++si].init(x);
            node[si].depth = node[v].depth + 1;
            node[si].dna[0].fa = v;
            for (int k = 1; k <= __lg(node[si].depth); k++)
            {
                int fath = node[si].dna[k - 1].fa;
                node[si].dna[k].fa = node[fath].dna[k - 1].fa;
                change(node[si].dna[k], node[fath].dna[k - 1], node[si].dna[k - 1]);
            }
        }
        else
        {
            int u, v, k;
            cin >> u >> v >> k;
            u--, v--;
            fl=false;
            auto tem=lca(u,v);
            if(tem.first==-1)tem.first=0;
            tem={0,0};
            if(tem.first==u||tem.first==v)
            {
                auto an=check(u,v);
                if(an.w>=k&&an.wm<=k)
                {
                    cout<<"YES"<<endl;
                }
                else cout<<"NO"<<endl;
            }
            else
            {
                if(fl)swap(u,v);
                DNA te;
                auto an=check(v,tem.second);
                swap(an.lw,an.rw),swap(an.lwm,an.rwm);
                auto an1=check(u,tem.first);
                change(te,an,an1);
                if(te.w>=k&&te.wm<=k)
                {
                    cout<<"YES"<<endl;
                }
                else cout<<"NO"<<endl;
            }
        }
    }
    return ;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}