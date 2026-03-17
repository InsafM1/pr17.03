#include <iostream>
#include <iomanip>
#include "top-it-vector.hpp"
int testDefaultVector()
{
  Vector< int > v;
  bool c = v.empty();
  return !c;
}

int main()
{
  using test_t = bool (*)();
  using pair_t = std::pair< const char*, test_t >;
  pair_t tests[] = {
    {"Default vector is empty", testDefaultVector}
  };
  const size_t count = sizeof(tests) / sizeof(pair_t);
  for (size_t i = 0; i < count; ++i)
  {
    bool res = test[i].second();
    std::cout << test[i].first << ":" << res;
  }
}
