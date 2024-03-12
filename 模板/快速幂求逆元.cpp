
#include <bits/stdc++.h>
using namespace std;
const int M = 998244353;
template<class T>
T qmi(T k, long long p = M - 2,long long P=M)
{
    T res = 1;
    while (p)
    {
        if (p & 1)
            res = 1ll*res * k % P;
        k = 1ll*k * k % P;
        p >>= 1;
    }
    return res%P;
}
int main()
{
    int a, b;
    cin >> a;
    cout << qmi(a);
}