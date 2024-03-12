#include <bits/stdc++.h>
using namespace std;
using i64=long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n);
    int sum=0;
    for(int i=0;i<n;i++)cin>>a[i];
    for(auto i:a)sum+=i;
    vector<int> dp(sum+1);
    vector<int> from(sum+1);
    dp[0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=sum;j>=a[i];j--)
        {
            if(dp[j-a[i]])
            {
                //cout<<i<<' '<<j<<endl;

                if(dp[j]==0)from[j]=i;
                dp[j]=1;
            }

        }
    }
    if(sum%2==0&&dp[sum/2])
    {
        cout<<"second"<<endl;
        set<int> x,y;
        sum/=2;
        while(sum)
        {
           // cout<<sum<<endl;
            x.insert(from[sum]);
            sum-=a[from[sum]];
        }
        for(int i=0;i<n;i++)
        {
            if(x.find(i)==x.end())
            {
                y.insert(i);
            }
        }
        int i,j;
        while(cin>>i,i)
        {
            i--;
            if(x.find(i)!=x.end())
            {
                j=*y.begin();
                int tem=min(a[j],a[i]);
                a[i]-=tem,a[j]-=tem;
                if(a[i]==0)x.erase(i);
                if(a[j]==0)y.erase(j);
            }
            else
            {
                j=*x.begin();
                int tem=min(a[j],a[i]);
                a[i]-=tem,a[j]-=tem;
                if(a[j]==0)x.erase(j);
                if(a[i]==0)y.erase(i);
            }
            cout<<j+1<<endl;
        }
    }
    else
    {
        cout<<"first"<<endl;
        int i=0,j;
        while(1)
        {
            cout<<i+1<<endl;
            cin>>j;
            if(j==0)break;
            j--;
            int tem=min(a[i],a[j]);
            a[i]-=tem,a[j]-=tem;
            while(a[i]==0)i++;
        }
    }
    return 0;
}