#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);

    int x, y;
    std::cin >> x >> y;

    int a = 0, b = 0, c = 0;
    c=y/2500;
    y-=2500*c;
    if(y%1000!=0)
    {
        c--,y+=2500;
    }

    //cout<<y;
    if(y%1000!=0||y/1000>(x-c))
    {
        cout<<"-1"<<endl;
    }
    else
    {
        b=y/1000;
        a=x-b-c;
        cout<<a<<" "<<b<<' '<<c<<endl;
    }

    return 0;
}