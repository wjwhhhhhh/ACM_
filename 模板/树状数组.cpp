#include <bits/stdc++.h>
const int bug = false;
#define dug(x)                                                                                                         \
    if (bug)                                                                                                           \
    cerr << "死了吧小丑" << x << endl
#define fir(i, a, b) for (int i = a; i < b; i++)
#define far(a, b) for (auto a : b)
using namespace std;
using i64 = long long;
template <class T> void chkmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
}
template <class T> void chkmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
}
template <class T> T min(T a, T b)
{
    return a > b ? b : a;
}
template <class T> T max(T a, T b)
{
    return a < b ? b : a;
}
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
    virtual  void op(T &x, T c)
    {
        x |= c;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string a;
    cin >> a;
    vector<int> all[20];
    for(int i=0;i<n;i++)all[a[i]-'a'].push_back(i);
        Tree_array <int> tr(n);
    for(int i=n-1;i>=0;i--)tr.insert(n-i,1<<a[i]-'a');
        array<int,20>st={};
    string ans,res;
    function<void(int)>dfs=[&](int l)
    {
        if(l>=n||tr.ask(n-l)==0)
        {
            chkmax(ans,res);
            return ;
        }
        int ll=l,rr=n-1;
        while(ll<rr)
        {
            int mid=ll+rr+1>>1;
            if(tr.ask(mid)==tr.ask(n-l))ll=mid;
            else rr=mid-1;
        }
        array<pair<int,int>,20> st;
        for(int i=0;i<20;i++)
        {
            if(st[i])continue;

        }
    dfs(0);
    };
    cout<<ans<<endl;
    return 0;
}