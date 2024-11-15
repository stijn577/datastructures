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
    list.append(dis(gen));
  }

  std::cout << "Using iterator to print list:\n";
  for (auto iter = list.begin(); iter != list.end(); ++iter) {
    std::cout << *iter << "\t";
  }
  std::cout << "X\n\n";

  std::cout << list;
  list.clear();
  std::cout << list;

#endif
}
