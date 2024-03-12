#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    if(n<=k)
    {
        cout<<n<<endl;
        return 0;
    }
    else cout<<k<<endl;

    return 0;
}