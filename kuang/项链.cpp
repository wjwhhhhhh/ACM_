#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void Minimum_representation(string &sec)
{
    int n = sec.size();
    int k = 0, i = 0, j = 1;
    while (k < n && i < n && j < n)
    {
        if (sec[(i + k) % n] == sec[(j + k) % n])
        {
            k++;
        }
        else
        {
            sec[(i + k) % n] > sec[(j + k) % n] ? i = i + k + 1 : j = j + k + 1;
            if (i == j)
                i++;
            k = 0;
        }
    }
    i = min(i, j);
    sec = sec.substr(i + 1) + sec.substr(0, i + 1);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    string a, b;
    cin >> a >> b;
    Minimum_representation(a), Minimum_representation(b);
    //cout << a << endl;
    if (a == b)
    {
        cout << "Yes" << endl;
        cout << a << endl;
    }
    else
        cout << "No" << endl;
    return 0;
}