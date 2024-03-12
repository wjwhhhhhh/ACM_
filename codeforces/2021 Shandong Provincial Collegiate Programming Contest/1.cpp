#include <bits/stdc++.h>
#define endl '\n';
using namespace std;
const int N = 510;
string a[N], A[N], B[N];
int f[N * N];
int n, m;
int main()
{

    cin >> n >> m;
    for (int i = 0; i < n * m + 10; i++)
        f[i] = i;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        A[i] = a[i], B[i] = A[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m - 1; j++)
        {
            if (j == 0)
                A[i][j] = '1';
            if (a[i][j] == '1')
                A[i][j] = '1';
            if (i % 2 == 0)
                A[i][j] = '1';
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '1')
                B[i][j] == '1';
            else if (A[i][j] == '1')
                B[i][j] = '0';
            else
                B[i][j] = '1';
        }
    // cout<<n<<' '<<m<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << A[i][j];
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << B[i][j];
        cout << endl;
    }
    return 0;
}