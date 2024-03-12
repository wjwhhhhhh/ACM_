#include <bits/stdc++.h>
using i64 = long long;
using namespace std;
int gauss(vector<vector<double>> &a)
{
    const int n = a.size();
    int c = 0, r = 0;
    for (; c < n; c++)
    {
        int t = r;
        for (int i = r; i < n; i++)
        {
            if (fabs(a[i][c]) > fabs(a[t][c]))
            {
                t = i;
            }
        }
        if (fabs(a[t][c]) < 1e-6)
        {
            continue;
        }
        for (int j = c; j <= n; j++)
        {
            swap(a[r][j], a[t][j]);
        }
        for (int j = n; j >= c; j--)
        {
            a[r][j] /= a[r][c];
        }
        for (int i = r + 1; i < n; i++)
        {
            if (fabs(a[i][c]) > 1e-6)
            {
                for (int j = n; j >= c; j--)
                {
                    a[i][j] -= a[r][j] * a[i][c];
                }
            }
        }
        r++;
    }
    if (r < n)
    {
        for (int i = r; i < n; i++)
        {
            if (fabs(a[i][n]) > 1e-6)
            {
                return 1;
            }
        }
        return 2;
    }
    else
    {
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                a[i][n] -= a[i][j] * a[j][n];
            }
        }
    }
    return 0;
}
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    cout << "2107040340 王俊伟\n";
    vector<double> r1{0.9428, 0.3475, -0.8468, 0.4127};
    vector<double> r2{0.3475, 1.8423, 0.4759, 1.7321};
    vector<double> r3{-0.8468, 0.4759, 1.2147, -0.8621};
    vector<vector<double>> a{r1, r2, r3};
    gauss(a);
    for (int i = 0; i < 3; i++)
    {
        cout << "x" << i + 1 << " = " << a[i][3] << "\n";
    }
    return 0;
}