#include "memory_leak.h"
#include <iostream>
#include <memory>

void prevent_memory_leak() {
  std::unique_ptr<int> ptr(new int(10));
  // Memory is automatically freed when ptr goes out of scope
}
