#include <iostream>
#include <vector>
using namespace std;
int GET(vector<int> &a)
{
    if (a.empty())
        return 0;
    if (a.size() == 1)
        return 1;
    for (int i = 0; i < (int)a.size() - 1; i++)
    {
        if (a[i] > a[i + 1])
            return i + 2;
    }
    return 1;
}
int main()
{
    vector<int> a{1, 8, 9};
    cout << GET(a) << endl;
}