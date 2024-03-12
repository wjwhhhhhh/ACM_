#include <bits/stdc++.h>
const int bug=false;
#define dug(x) if(bug)cerr << "死了吧小丑" << x << endl
#define fir(i,a,b) for(int i=a;i<b;i++)
#define far(a,b)for(auto a:b)
using namespace std;
using i64=long long;
template<class T> void chkmax(T &a, T b) {a > b ? (a = a) : (a = b);}
template<class T> void chkmin(T &a, T b) {a > b ? (a = b) : (a = a);}
string solve(string &a)
{

    bool fl=true;
    for(int i=1;i<a.size();i++)if(a[i]!=a[0])fl=false;
    if(fl)
    {
        return "-1";
    }
    char mi=*min_element(a.begin(),a.end());
    vector<int>l,r;
    int si=0;
    int n=a.size();
    for(int i=0;i<n;i++)
    {
        if(a[i]==a[si])continue;
        else
        {
            l.push_back(si);
            r.push_back(i-1);
            si=i;
        }
    }
    l.push_back(si),r.push_back(n-1);
    int maz=0,last=-1;
    si=0;
    for(int i=0;i<l.size();i++)
    {
        if(a[l[i]]==mi)
        {
            si++;
            last=r[i];
            chkmax(maz,r[i]-l[i]+1);
        }
    }
    if(si>=2)
    {
        string ans(maz+1,mi);
        return ans;
    }
    string ans(maz,mi);
    auto get=solve(a.substr(last+1));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        cin>>a;

    }
    return 0;
}