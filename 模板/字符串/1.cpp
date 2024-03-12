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
        int n,k;
    cin>>n>>k;
    vector<int> b(n);
    for(int i=1;i<n;i++)cin>>b[i];
    bool fl=false;
    for(int i=1;i<n;i++)if(b[i])fl=true;
    if(!fl)
    {
        for(int i=0;i<n;i++)cout<<k-1<<" ";
            return ;
    }
    int last=-1;
    int l=1;
    while(b[l]==0)l++;
    bitset<30> all;
    for(int i=l;i<n;i++)
    {
        int ing=-1;
        for(int j=0;j<=29;j++)
        {
            if(b[i]>>j&1)
            {

                ing=j;
            }

        }
        all[ing]=true;
        if(ing<=last)
        {
            cout<<"-1"<<endl;
            return ;
        }
        last=ing;
    }
    last=30-all.count();
    if(pow(2,last)<k)
    {
        cout<<"-1"<<endl;
        return ;
    }
    k--;
    bitset<30> ans;
    vector<int> xi;
    for(int i=0;i<30;i++)if(all[i]==0)xi.push_back(i);
    //cout<<xi[0]<<endl;
    k-1;
    for(int i=0;i<=29;i++)
    {
        if(k>>i&1)
        {
            //cout<<i<<endl;
            ans[xi[i]]=true;
            //cout<<xi[i]<<endl;
        }
    }
    int tr=0;
    for(int i=29;i>=0;i--)
    {
        tr=tr*2+(ans[i]);
    }
    vector<int> a(n);
    a[l-1]=tr;
    for(int i=l-2;i>=0;i--)a[i]=a[i+1];
    for(int i=l;i<n;i++)
    {
        a[i]=b[i]^a[i-1];
    }
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
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