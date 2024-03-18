#include <iostream>
using namespace std;
bool IsSame(const char *a, const char *b)
{
    auto aa = a, bb = b;
    while (*aa != '\0' && *bb != '\0')
    {
        if (*aa != *bb)
            return false;
        aa++, bb++;
    }
    return true;
}
const char *strstr(const char *string, const char *strSearch)
{
    auto aa = string, bb = strSearch;
    while (*aa != '\0')
    {
        if (IsSame(aa, bb))
            return aa;
        aa++;
    }
    return nullptr;
}
int main()
{
    char *a = "123456";
    char *b = "3";
    cout << strstr(a, b);
}