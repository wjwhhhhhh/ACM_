#include <bits/stdc++.h>
const int bug=false;
#define dug(x) if(bug)cerr << "死了吧小丑" << x << endl
#define fir(i,a,b) for(int i=a;i<b;i++)
#define far(a,b)for(auto a:b)
using namespace std;
using i64=long long;
template<class T> void chkmax(T &a, T b) {a > b ? (a = a) : (a = b);}
template<class T> void chkmin(T &a, T b) {a > b ? (a = b) : (a = a);}
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

    bool merge(int x, int y)
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
template <class T>
struct Tree_array
{
    vector<T> tr;
    int maxx;
    Tree_array(int n)
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
    virtual  void p(T &x, T c)
    {
        x += c;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> last(n);
    iota(last.begin(),last.end(),0);
    vector<vector<int> > mp;
    for(int i=0;i<n;i++)cin>>a[i];
        i64 ans=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]!=1)continue;
        int l=i,r;
        while(i<n)
        {
            if(a[i]==1)mp[a[i]].push_back(i);
            else if(mp[a[i]-1].size()==0)break;
            else
            {
                int la=mp[a[i]-1].back();
                mp[a[i]-1].pop_back();
                last[la]=i;
                mp[a[i]].push_back(i);
            }
        }
        r=i-1,i--;
        for(int j=l;j<=i;j++)
        {
            if(a[j]==1)
            {
                ans+=max(1,r-j+1);
                if(last[j]==j)continue;
                int tem=last[j];
                for(int z=j+1;z<last[j];z++)
                {
                    if(a[z]==1)
                    {
                        ans++;
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}