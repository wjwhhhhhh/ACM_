#include <bits/stdc++.h>
const int bug=false;
#define dug(x) if(bug)cerr << "死了吧小丑" << x << endl
#define fir(i,a,b) for(int i=a;i<b;i++)
#define far(a,b)for(auto a:b)
using namespace std;
using i64=long long;
template<class T> void chkmax(T &a, T b) {a > b ? (a = a) : (a = b);}
template<class T> void chkmin(T &a, T b) {a > b ? (a = b) : (a = a);}
void solve()
{
    string a;
    cin>>a;
    if(a[0]>='5')
    {
        cout<<"1";
        for(int i=0;i<a.size();i++)cout<<'0';
            cout<<endl;
        return ;
    }
    int t=0;
    int last;
    for(int i=a.size()-1;i>=0;i--)
    {
        t+=a[i]-'0';
        if(t>=5)
        {
            last=i;
            t=1;
        }
        else t=0;
    }
    if(t)
    {
        cout<<"1";
        for(int i=0;i<a.size();i++)cout<<'0';
            cout<<endl;
        return ;
    }
    for(int i=0;i<last;i++)cout<<a[i];
    cout<<a[last]+1;
    for(int i=last+1;i<a.size();i++)cout<<'0';
    cout<<endl;
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