#include <bits/stdc++.h>
#define int long long
const int N = 7, M = 1000000007;
int ans[N][N] =
    {
        {1, 1, 1, 8, 4, 2, 1},
},
    f[N][N], tem[N] = {16, 1, 0, 27, 9, 3, 1};
void mul(int A[N][N], int B[N][N], int C[N][N])
{
    int tem[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
            {
                tem[i][j] = (tem[i][j] + B[i][k] * C[k][j]) % M;
            }
    memcpy(A, tem, sizeof tem);
}
signed main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        int n;
        std::cin >> n;
        memset(f, 0, sizeof f), memset(ans, 0, sizeof ans);
        for (int i = 0; i < N; i++)
            ans[0][i] = tem[i];
        for (int i = 0; i < N; i++)
            f[0][i] = 1;
        f[0][2] = 0;
        f[1][0] = 1, f[2][1] = 1, f[3][3] = 1, f[3][4] = 3, f[3][5] = 2, f[3][6] = 2;
        f[4][4] = 1, f[4][5] = 2, f[4][6] = 1, f[5][5] = 1, f[5][6] = 1, f[6][6] = 1;
        if (n == 0)
            puts("0");
        else if (n == 1)
            puts("1");
        else
        {
            n -= 2;
            while (n)
            {
                if (n & 1)
                    mul(ans, ans, f);
                mul(f, f, f);
                n >>= 1;
            }
            std::cout << ans[0][0] << std::endl;
        }
    }
}