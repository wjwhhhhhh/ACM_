#include <bits/stdc++.h>
using namespace std;
using i64=long long;
void slove()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    string ans="";
    int si=0;
    vector<int> tem;
    for(int i=0;i<n;i++)
    {
        if(tem.size()==0)
        {
            tem.push_back(a[i]);
            ans+='1';
            continue;
        }
        if(si==0)
        {
            if(a[i]>=tem.back())
            {
                tem.push_back(a[i]);
                ans+='1';
            }
            else if(a[i]<=tem[0])
            {
                tem.push_back(a[i]);
                ans+='1';
                si++;
            }
            else ans+='0';
        }
        else
        {
            if(a[i]>=tem.back()&&a[i]<=tem[0])
            {
                tem.push_back(a[i]);
                ans+='1';
            }
            else ans+='0';
        }


    }
    cout<<ans<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        slove();
    }
    return 0;
}