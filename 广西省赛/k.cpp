#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    int n=a.size(),m=b.size();
    if(m%n!=0)
    {
        cout<<"Lazy Dog's Great Failure..."<<endl;
        return 0;
    }
    int si=0;
    for(int i=0,j=0;i<b.size();i++,j++)
    {
        if(a[j%n]!=b[i])
        {
            cout<<"Lazy Dog's Great Failure..."<<endl;
            return 0;
        }
        if(j%n==0)si++;
    }
    if(si!=si&-si)
    {
        cout<<"Lazy Dog's Great Failure..."<<endl;
    }
    else
    {
        cout<<"Smart People's Big Win!"<<endl;
    }
    return 0;
}