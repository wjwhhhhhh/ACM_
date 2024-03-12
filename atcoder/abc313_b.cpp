#include <bits/stdc++.h>
const int bug=false;
#define dug(x) if(bug)cerr << "死了吧小丑" << x << endl
#define fir(i,a,b) for(int i=a;i<b;i++)
#define far(a,b)for(auto a:b)
using namespace std;
using i64=long long;
template<class T> void chkmax(T &a, T b) {a > b ? (a = a) : (a = b);}
template<class T> void chkmin(T &a, T b) {a > b ? (a = b) : (a = a);}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> in(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        in[b]++;
    }
    vector<int> ans;
    for(int i=1;i<=n;i++)if(in[i]==0)ans.push_back(i);
    cout<<(ans.size()==1?ans[0]:-1)<<endl;
    return 0;
}