#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    std::vector<int> a(2000);
    a[0] = 1;
    for (int i = 1; i < 2000; i++)
    {
        if (i % 3 == 0)a[i] = a[i / 3] + 1;
        else a[i] = a[i - 1] + 1;
    }
    for (int i = 1; i < 2000; i++)
    {
        if(i%9==1)cout << a[i] << " ";
        //if(i%3==0)cout<<endl;
        if(i%9==0)cout<<endl;
    }
    return 0;
}