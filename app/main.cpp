#include <iostream>
#include <random>

#include "linked_list.hpp"

int main(void) {
  std::random_device rd;

  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(1, 100);

#ifdef LINKED_LIST

  auto list = LinkedList<int>(dis(gen));

  for (size_t i = 0; i < 20; i++) {
    list.push_back(dis(gen));
  }

  std::cout << list;

#endif
}
