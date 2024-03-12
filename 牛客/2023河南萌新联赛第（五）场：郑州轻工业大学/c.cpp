#include <bits/stdc++.h>
const int bug=false;
#define dug(x) if(bug)cerr << "死了吧小丑" << x << endl
#define fir(i,a,b) for(int i=a;i<b;i++)
#define far(a,b)for(auto a:b)
using namespace std;
using i64=long long;
template<class T> void chkmax(T &a, T b) {a > b ? (a = a) : (a = b);}
template<class T> void chkmin(T &a, T b) {a > b ? (a = b) : (a = a);}
const int M=1e9+7;
vector<array<int,10>> st;
map<int,array<int,3>>mp;
string a;
array<int,3> dfs(int wei)
{
    if(wei==0)
    {
        array<int,3> tr={0,0,0};
        return tr;
    }
    if(mp.find(wei)!=mp.end())return mp[wei];
    array<int,3> tr={};
    tr[(a[wei-1]-'0')%3]=1;
    for(int i=0;i<10;i++)
    {
        auto get=dfs(st[wei-1][i]);
        for(int i=0;i<3;i++)tr[i]=(tr[i]+get[i])%M;
    }
    return mp[wei]=tr;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    cin>>a;
    a+='0';
    st.resize(a.size()+1);
    st[0].fill(-1);
    for(int i=1;i<=a.size();i++)
    {
        st[i]=st[i-1];
        st[i][a[i-1]-'0']=i;
    }
    auto get=dfs(a.size());
    cout<<(get[1]+get[2])%M;
    return 0;
}