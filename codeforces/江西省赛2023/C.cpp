#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int>a(10000);
    a[0]=0;
    for(int i=1;i<100;i++)
    {
        set<int> st;
        st.clear();
        for(int j=1;j<=i;j*=n)
        {
            st.insert(a[i-j]);
        }
        int l=0;
        while(st.find(l)!=st.end())l++;
        a[i]=l;
        cout<<l<<endl;
    }
    return 0;
}