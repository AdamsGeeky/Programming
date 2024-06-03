#include "null_pointer.h"
#include <iostream>
#include <optional>

void prevent_dangling_pointer() {
  auto get_pointer = []() -> std::optional<int> { return std::nullopt; };

  if (auto ptr = get_pointer()) {
    std::cout << *ptr << std::endl;
  } else {
    std::cout << "No valid pointer" << std::endl;
  }
}
