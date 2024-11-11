#pragma once

#include <iostream>
#include <memory>
#include <ostream>

template <typename T> class LinkedList {
private:
  // Node class is private and nested within LinkedList
  class Node {
  private:
    T data;
    std::unique_ptr<Node> next;

  public:
    Node() = default;
    Node(T data) : data(data), next(nullptr) {}
    ~Node() {}

    // Move constructor
    Node(Node &&other) noexcept
        : data(std::move(other.data)), next(std::move(other.next)) {}

    // Move assignment operator
    Node &operator=(Node &&other) noexcept {
      if (this != &other) {
        data = std::move(other.data);
        next = std::move(other.next);
      }
      return *this;
    }

    // Copy constructor that sets next to nullptr
    Node(const Node &other) : data(other.data), next(nullptr) {}

    // Copy assignment operator that sets next to nullptr
    Node &operator=(const Node &other);
    // Allow LinkedList to access private members of Node
    friend class LinkedList<T>;

    friend std::ostream &operator<<(std::ostream &os, const Node &obj) {

      if (obj.next) {
        os << obj.data << "\t";
        os << *obj.next;
      } else {
        os << obj.data << "\tX";
      }

      return os;
    }
  };

  Node inner;

public:
  LinkedList() = default;
  LinkedList(T data) : inner(data) {}
  ~LinkedList() { std::cout << "Deleted Linkedlist\n"; }

  // Move constructor
  LinkedList(LinkedList &&other) noexcept : inner(std::move(other.inner)) {}

  // Move assignment operator
  LinkedList &operator=(LinkedList &&other) noexcept {
    if (this != &other) {
      inner = std::move(other.inner);
    }
    return *this;
  }

  // Delete the copy constructor and copy assignment operator
  LinkedList(const LinkedList &) = delete;
  LinkedList &operator=(const LinkedList &) = delete;

  friend std::ostream &operator<<(std::ostream &os, const LinkedList<T> &obj) {
    os << "LinkedList with nodes: " << obj.inner << "\n\n";
    return os;
  }

  void push_back(T data) {
    if (!inner.next) {
      inner.next = std::make_unique<Node>(Node(data));
      return;
    }

    Node *iter = inner.next.get();
    while (iter->next != nullptr) {
      iter = iter->next.get();
    }

    iter->next = std::make_unique<Node>(Node(data));
  }
};