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
    set<string> x,y;
    int n;
    cin>>n;
    string x1="sudo pacman -S ";
    while(n--)
    {
        string a;
        cin>>a;
        if(a=="sudo rm -rf /*")
        {
            cout<<"wuwuwu"<<endl;
            return ;
        }
        if(a[0]=='1')
        {

        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}