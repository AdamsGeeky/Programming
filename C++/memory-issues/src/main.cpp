/**
 * Author: Adamu Muhammad Muhammad
 * Date: 2024-06-03
 * Description: Memory managemement in C++
 */

#include "double_free.h"
#include "memory_leak.h"
#include "null_pointer.h"
#include "race_condition.h"
#include <iostream>

int main() {
  std::cout << "Preventing Race Condition:" << std::endl;
  prevent_race_condition();

  std::cout << "\nPreventing Double Free:" << std::endl;
  prevent_double_free();

  std::cout << "\nPreventing Memory Leak:" << std::endl;
  prevent_memory_leak();

  std::cout << "\nPreventing Dangling Pointer:" << std::endl;
  prevent_dangling_pointer();

  return 0;
}
