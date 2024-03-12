#include <bits/stdc++.h>
const int bug=false;
#define dug(x) if(bug)cerr << "死了吧小丑" << x << endl
#define fir(i,a,b) for(int i=a;i<b;i++)
#define far(a,b)for(auto a:b)
using namespace std;
using i64=long long;
void solve()
{
    vector<array<int,3>>a(4);
    fir(i,0,4)fir(j,0,3)cin>>a[i][j];
    for(int i=0;i>=0;i--)
    {
        if(a[0][0]*i>a[3][0]||a[0][1]*i>a[3][1]||a[0][2]*i>a[3][2])break;
    }
    cout<<"NO"<<endl;
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