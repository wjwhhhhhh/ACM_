#include <bits/stdc++.h>
#include <memory>
class A
{
  public:
    A()
    {
        std::cout << "开始" << std::endl;
    }
    ~A()
    {
        std::cout << "死了吧" << std::endl;
    }

  private:
};
int main()
{
    std::shared_ptr<A> val(new A());
    return 0;
}