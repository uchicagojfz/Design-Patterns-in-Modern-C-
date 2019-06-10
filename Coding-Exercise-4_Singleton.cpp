#include <functional>
using namespace std;

struct SingletonTester
{
  template <typename T>
  bool is_singleton(function<T*()> factory)
  {
    auto f1 = factory();
    auto f2 = factory();
    return (f1 == f2);
  }
};
