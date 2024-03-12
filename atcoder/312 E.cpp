#include <bits/stdc++.h>
const int bug=false;
#define dug(x) if(bug)cerr << "死了吧小丑" << x << endl
#define fir(i,a,b) for(int i=a;i<b;i++)
#define far(a,b)for(auto a:b)
using namespace std;
using i64=long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    array< array<array<int,101>,101>,101> mp;
    fir(i,0,n)
    {
        array<int,6> a;
        fir(j,0,6)cin>>a[j];
        fir(x,a[0],a[3])fir(y,a[1],a[4])fir(z,a[2],a[5])mp[x][y][z]=i+1;
    }
    std::vector<set<int>> ans(n+1);
    // auto add=[&](int x,int y)
    // {
    //     if(x==0||y==0)return ;
    //     ans[x].insert(y);
    //     ans[y].insert(x);
    // };
    // fir(x,0,100)fir(y,0,100)fir(z,0,100)
    // {
    //     if(mp[x][y][z]!=mp[x+1][y][z])add(mp[x][y][x],mp[x+1][y][z]);
    //     if(mp[x][y][z]!=mp[x][y+1][z])add(mp[x][y][x],mp[x][y+1][z]);
    //     if(mp[x][y][z]!=mp[x][y][z+1])add(mp[x][y][x],mp[x][y][z+1]);
    // }
    fir(i,1,n+1)cout<<ans[i].size()<<endl;
    return 0;
}