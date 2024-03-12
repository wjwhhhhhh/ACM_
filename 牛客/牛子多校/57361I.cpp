#include <bits/stdc++.h>
const int bug=false;
#define dug(x) if(bug)cerr << "死了吧小丑" << x << endl
#define fir(i,a,b) for(int i=a;i<b;i++)
#define far(a,b)for(auto a:b)
using namespace std;
using i64=long long;
template<class T> void chkmax(T &a, T b) {a > b ? (a = a) : (a = b);}
template<class T> void chkmin(T &a, T b) {a > b ? (a = b) : (a = a);}
const int M=998244353;
i64 get(int len,vector<string>&a)
{
    string b(len,'0');
    int res=0;
    auto check=[&]()
    {
        for(auto x:a)
        {
            bool fl=true;
            for(int i=0;i<b.size();i++)
            {
                if(x[i]=='?'||x[i]==b[i])continue;
                else fl=false;
            }
        }
        return false;
    };
    function<void(int)>dfs=[&](int u)
    {
        if(u==len)
        {
            if(check())res++;
        }
        dfs(u+1);
        b[u]='1';
        dfs(u+1);
        b[u]='0';
    };
    dfs(0);
    return res;
}
bool cmp(string &a,string &b)
{
    if(a.size()!=b.size())return false;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]=='?'||b[i]=='?')continue;
        if(a[i]!=b[i])return false;
    }
    return true;
}
i64 get2(int len,vector<string> &a)
{
    int n=a.size();
    i64 ans=0;
    vector<vector<int>>st(n,vector<int>(n));
    for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)
    {
        st[i][j]=cmp(a[i],a[j]);
    }
    for(int i=0;i<1<<n;i++)
    {
        vector<int> all;
        int tem=i;
        for(int i=0;i<n;i++)
        {
            if(tem>>i&1)all.push_back(i);
        }
        bool fl=false;
        for(int i=0;i<all.size();i++)for(int j=i+1;j<all.size();j++)
        {
            if(!st[all[i]][all[j]])fl=true;
        }
        i64 res=1;
        for(int j=0;j<n;j++)
        {
            bool fl=false;
            for(auto x:all)
            {
                if(a[x][j]!='?')fl=true;
            }
            if(!fl)res=(res*2)%M;
        }
        ans=(ans+(all.size()%2?1:-1)*res%M+M)%M;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<string> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    map<int,vector<string>>mp;
    for(int i=0;i<n;i++)
    {
        mp[a[i].size()].push_back(a[i]);
    }
    i64 ans=0;
    for(auto [len,cnt]:mp)
    {
        if(len<20)
        {
            ans=(ans+get(len,cnt))%M;
        }
        else ans=(ans+get2(len,cnt))%M;
    }
    return 0;
}