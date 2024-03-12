#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin>>n;
    vector<string> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int ans=0x3f3f3f3f;
    auto check=[&](int x)
    {
        int res=0;
        vector<string> b=a;
        for(int i=0;i<n;i++)
        {
            if(b[0][i]==x+'0')
            {
                res++;
                for(int j=0;j<n;j++)b[i][j]=='0'?b[i][j]='1':b[i][j]='0';
            }
        }
        for(int j=0;j<n;j++)
        {
            if(b[j][0]==x+'0')
            {
                res++;
                for(int i=0;i<n;i++)b[i][j]=='0'?b[i][j]='1':b[i][j]='0';
            }
        }
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(b[i][j]==x+'0')return -1;
        return res;
    };
    int te=check(0);
    if(te!=-1)ans=min(ans,te);
      te=check(1);
    if(te!=-1)ans=min(ans,te);
    if(ans==0x3f3f3f3f)cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}