
#include "race_condition.h"
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

int counter = 0; // Shared resource
std::mutex mtx;  // Mutex to protect shared resource

void increment() {
  for (int i = 0; i < 1000000; ++i) {
    std::lock_guard<std::mutex> lock(
        mtx); // Lock the mutex before modifying the shared resource
    ++counter;
    // Mutex is automatically unlocked when lock goes out of scope
  }
}

void prevent_race_condition() {
  std::vector<std::thread> threads;

  // Create and start multiple threads
  for (int i = 0; i < 2; ++i) {
    threads.push_back(std::thread(increment));
  }

  // Wait for all threads to finish
  for (auto &t : threads) {
    t.join();
  }

  std::cout << "Counter: " << counter << std::endl; // Should print 2000000
}
