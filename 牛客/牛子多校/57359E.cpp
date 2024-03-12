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
    int n,m;
    cin>>n>>m;
    vector<array<int,3>>a(m);
    fir(i,0,m)fir(j,0,3)cin>>a[i][j];
    fir(i,0,m)
    {
        if(a[i][0]==a[i][1]&&a[i][2]==1)
        {
            cout<<"-1"<<endl;
            return 0;
        }
    }
    set<int> can;
    set<int> ans;
    vector<array<int,3>>b;
    fir(i,0,m)
    {
            if(a[i][2]==1)
        {
            a[i][1]--;
            b.push_back(a[i]);
        }
        else
        {
            for(int j=a[i][0];j<a[i][1];j++)can.insert(a[i][0]);
        }
    }
    vector<int> o(b.size());
    iota(o.begin(), o.end(), 0);
        sort(o.begin(),o.end(), [&](int x, int y) {
            return b[x][0]<b[y][0]||(b[x][0]==b[y][0]&&b[x][1]<b[y][1]);
        });
    for(int i=0;i<b.size();i++)
    {
        int id=o[i];
        int si=0;
        for(int j=a[id][0];j<a[id][1];j++)
        {
            if(ans.find(j)!=ans.end())si++;
        }
        if(si%2==0)
        {
            cout<<"-1"<<endl;

        }
    }
    return 0;
}