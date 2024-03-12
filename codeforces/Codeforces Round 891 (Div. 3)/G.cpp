#include <bits/stdc++.h>
const int bug=false;
#define dug(x) if(bug)cerr << "死了吧小丑" << x << endl
#define fir(i,a,b) for(int i=a;i<b;i++)
#define far(a,b)for(auto a:b)
using namespace std;
using i64=long long;
template<class T> void chkmax(T &a, T b) {a > b ? (a = a) : (a = b);}
template<class T> void chkmin(T &a, T b) {a > b ? (a = b) : (a = a);}
struct EDGE
{
    int fr, to, w;
    void init(int a, int b, int c)
    {
        fr = a, to = b, w = c;
    }
    friend bool operator<(const EDGE &x, const EDGE &y)
    {
        return x.w < y.w;
    }
};
const int M=998244353;
struct DSU
{
    std::vector<int> f, siz;

    DSU()
    {
    }
    DSU(int n)
    {
        init(n);
    }

    void init(int n)
    {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }

    int find(int x)
    {
        while (x != f[x])
        {
            x = f[x] = f[f[x]];
        }
        return x;
    }

    bool same(int x, int y)
    {
        return find(x) == find(y);
    }

    bool merge(int x, int y)//
    {
        x = find(x);
        y = find(y);
        if (x == y)
        {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x)
    {

        return siz[find(x)];
    }
};
template<class T>
T qmi(T k, long long p = M - 2,long long P=M)
{
    T res = 1;
    while (p)
    {
        if (p & 1)
            res = res * k % P;
        k = k * k % P;
        p >>= 1;
    }
    return res;
}
void solve()
{
    int n,s;
    cin>>n>>s;
    DSU f(n);
    vector<EDGE> Edge(n-1);
    vector<int> dp(n,1);
    for(int i=0;i<n-1;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        a--,b--;
        Edge[i].init(a,b,c);
    }
    sort(Edge.begin(),Edge.end());
    for(auto [x,y,z]:Edge)
    {
        i64 cnt=1ll*f.size(x)*f.size(y)%M-1;
        cnt=(qmi((s-z)+1,cnt)-1)%M;
        cout<<cnt<<endl;
        dp[f.find(x)]=(cnt*dp[f.find(x)]%M)*dp[f.find(y)];
        f.merge(x,y);
    }
    cout<<dp[f.find(0)]<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}