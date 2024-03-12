#include <bits/stdc++.h>
const int bug=false;
#define dug(x) if(bug)cerr << "死了吧小丑" << x << endl
#define fir(i,a,b) for(int i=a;i<b;i++)
#define far(a,b)for(auto a:b)
using namespace std;
using i64=long long;
template<class T> void chkmax(T &a, T b) {a > b ? (a = a) : (a = b);}
template<class T> void chkmin(T &a, T b) {a > b ? (a = b) : (a = a);}
template <class T>
struct Tree_array
{
    vector<T> tr;
    int maxx;
    Tree_array(int n=0)
    {
        init(n);
    }
    Tree_array(vector<T> a)
    {
        int n=a.size();
        init(n+1);
        for(int i=1;i<n;i++)insert(i,a[i]);
    }
    void init(int n)
    {
        maxx = n;
        tr.resize(n + 1);
    }
    void insert(int x, T c)
    {
        for (int i = x; i <= maxx; i += lowbit(i))
            op(tr[i], c);
    }
    T ask(int x)
    {
        T res = 0;
        for (int i = x; i; i -= lowbit(i))
            op(res, tr[i]);
        return res;
    }
    int lowbit(int x)
    {
        return x & -x;
    }
    void op(T &x, T c)
    {
        x += c;
    }
};
struct Two_dimensional
{
    Tree_array<int> tr;
    int W;//值域
    vector<array<int,2>> w,q;
    Two_dimensional(int _w=0,int _n=0,int _m=0)
    {
        init(_w,_n,_m);
    }
    void init(int _w,int _n,int _m)
    {
        W=_w;
        tr.init(_w);
        w.resize(_n),q.resize(_m);
    }
    bool cmp(const array<int,2>&a,const array<int,2>&b)
    {
        return a[0]>b[0]||(a[0]==b[0]&&a[1]>b[1]);
    }
    void sor(vector<int>& o, const vector<array<int, 2>>& a)
    {
         iota(o.begin(), o.end(), 0);
        sort(o.rbegin(), o.rend(), [&](const int x, const int y) {
            return cmp(a[x],a[y]);
        });
    }
    vector<int> query()
    {
        vector<int> ans(q.size());
        vector<int> o1(w.size()),o2(q.size());
        sor(o1,w);
        sor(o2,q);
        int idx=0;
        fir(i,0,q.size())
        {
            int id=o2[i];
            while(idx<w.size()&&!cmp(w[o1[idx]],q[id]))
            {
                tr.insert(w[o1[idx]][1],1);
                idx++;
            }
            ans[id]=tr.ask(q[id][1]);
        }
        return ans;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n,k;
    cin>>n>>k;
    vector<int> a(n),b(n),c(n);
    for(int i=0;i<n;i++)cin>>a[i]>>b[i]>>c[i];
    auto cmp2=[&](int x,int y)
    {
        return a[x]>a[y]||(a[x]==a[y]&&b[x]>b[y])||(a[x]==a[y]&&b[x]==b[y]&&c[x]>c[y]);
    };
    auto same=[&](int x,int y)
    {
        return a[x]==a[y]&&b[x]==b[y]&&c[x]==c[y];
    };
        vector<int> o(n);
        iota(o.begin(), o.end(), 0);
            sort(o.rbegin(),o.rend(), [&](int x, int y) {return cmp2(x,y);
            });
    vector<int> dp(n);
    function<void(int,int)> solve=[&](int l,int r)
    {
        if(l==r)return ;
        int mid=l+r>>1;
        solve(l,mid),solve(mid+1,r);
        int cl=0,cr=0;
        for(int i=mid;i>mid-cl;i--)dp[o[i]]+=cr;
        Two_dimensional te(k,mid-l+1,r-(mid));
        for(int i=l;i<=mid;i++)
        {
            te.w[i-l]={b[o[i]],c[o[i]]};
        }
        for(int i=mid+1;i<=r;i++)
        {
            te.q[i-mid-1]={b[o[i]],c[o[i]]};
        }
        auto get=te.query();
        for(int i=mid+1;i<=r;i++)dp[o[i]]+=get[i-mid-1];
        return ;
    };
    solve(0,n-1);
    vector<int> ans(n);
   for(int i=0;i<n;i++)ans[dp[i]]++;
    for(int i=0;i<n;i++)cout<<ans[i]<<"\n";
        return 0;
}