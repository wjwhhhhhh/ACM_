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
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
        i64 sum=0;
    for(int i=0;i<n;i++)sum+=a[i];
    vector<int> ans(n);
    for(int i=0;i<n;i++)ans[i]=sum/n;
    for(int i=n-1;i>=0&&sum>1ll*ans[0]*n;i--)
    {
        ans[i]++;
        sum--;
    }
    sort(a.begin(),a.end());
    i64 res=0;
    for(int i=0;i<n;i++)res+=abs(a[i]-ans[i]);
        cout<<res/2<<endl;
    return 0;
}