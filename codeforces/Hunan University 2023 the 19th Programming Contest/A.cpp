#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a;
    cin >> a;
    int l = 0, r = a.size() - 1;
    while (l < r)
    {
        while (l < r && a[l] != 'C')l++;
        while (l < r && a[r] != 'A')r--;
        if (l < r)swap(a[l], a[r]);
    }
    l = 0, r = 0;
    int ans = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == 'A')l++;
        else if (a[i] == 'B' && l)r++, l--;
        else if (a[i] == 'C' && r)ans++, r--;
    }
    cout<<ans<<endl;
    return 0;
}