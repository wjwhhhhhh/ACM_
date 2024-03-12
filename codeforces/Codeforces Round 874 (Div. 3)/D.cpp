#include <bits/stdc++.h>
using namespace std;
void solves()
{
    int n, m;
    cin >> n;
    m = n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)cin >> a[i];
    if (n == 1)
    {
        cout << "1" << '\n';
        return ;
    }
    if (a[0] == n)m--;
    int si = 0;
    for (int i = 1; i < n; i++)if (a[i] == m)si = i;
    if (si == n - 1)
    {
        if (a[0] >= a[si - 1])
        {
            cout << a[si] << " ";
            for (int i = 0; i < si; i++)cout << a[i] << " ";
            cout << "\n";
            return ;
        }
    }
    for(int i=si;i<n;i++)cout<<a[i]<<" ";
        cout<<a[--si]<<" ";
    while(si-1>0&&a[si-1]>a[0])cout<<a[--si]<<" ";
    for(int i=0;i<si;i++)cout<<a[i]<<" ";
        cout<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solves();
    }
    return 0;
}