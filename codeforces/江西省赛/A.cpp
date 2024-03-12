#include <bits/stdc++.h>
using namespace std;
void solves()
{
     int a[3];
     cin>>a[0]>>a[1]>>a[2];
     sort(a,a+3);
     cout<<(a[1]-a[0])*(a[1]*a[0])+(a[2]+2*a[0])*(a[2]+2*a[0])<<endl;
 }
int main()
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