#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int a[N];
void solves()
{
    int n,x;
    cin>>n>>x;
    for(int i=1;i<=x;i++)cin>>a[i];
    set<int> st;
    int si=(n-1)/7;
    for(int i=1;i<=x;i++)
    {
        if(a[i]==1)continue;
        int tem=(a[i]-2)/7+1;
        if(tem>si)break;
        st.insert((a[i]-2)/7+1);
    }
    int ans=n*5;
    ans-=x*5;

    ans-=si*50;
    ans+=(st.size())*50;
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        solves();
    }
    return 0;
}