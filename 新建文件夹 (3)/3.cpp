#include <iostream>
using namespace std;
// 递归版本
int DFS(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    return DFS(n - 1) + DFS(n - 2);
}
int GET(int n)
{
    auto a1 = 0, a2 = 1, a3 = 0;
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    for (int i = 2; i <= n; i++)
    {
        a3 = a1 + a2;
        a1 = a2, a2 = a3;
    }
    return a3;
}
int main()
{
    for (int i = 0; i < 20; i++)
    {
        if (DFS(i) != GET(i))
            cout << "false" << endl;
    }
}