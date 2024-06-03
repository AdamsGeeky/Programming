#include "double_free.h"
#include <iostream>
#include <memory>

void prevent_double_free() {
  std::unique_ptr<int> ptr1(new int(10));
  std::cout << "Value: " << *ptr1 << std::endl;
  // No double free error possible because unique_ptr automatically handles
  // deallocation
}
