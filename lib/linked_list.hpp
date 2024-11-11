#pragma once

#include <iostream>
#include <memory>

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
    ~Node() { std::cout << "Deleted node with data: " << data << "\n"; }

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
};
