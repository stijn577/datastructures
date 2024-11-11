#include <cstddef>
#include <utility>

#include "linked_list.hpp"

int main(void) {
#ifdef LINKED_LIST
  auto list = LinkedList<int>(10);
  list.print();
#endif
}
