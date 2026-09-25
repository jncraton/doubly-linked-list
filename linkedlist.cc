#include <cassert>
#include <print>
#include <stdexcept>

class Node {
public:
  Node *next;
  int data;

  Node(int data, Node *next = nullptr) : data(data), next(next) {}
};

class LinkedList {
public:
  Node *head;

  LinkedList() { head = nullptr; }

  void append(int data) {
  }

  int get(int index) {
    return 0;
  }

  void pop() {
  }

  void insert(int index, int data) {
  }
};

int main() {
  LinkedList ll;

  ll.append(1);
  assert(("List has content", ll.head != nullptr));
  assert(("Single item appended", ll.head->data == 1));

  ll.append(2);
  assert(("First item untouched", ll.head->data == 1));
  assert(("Second item appended", ll.head->next->data == 2));

  assert(("Get first item", ll.get(0) == 1));
  assert(("Get second item", ll.get(1) == 2));

  try {
    ll.get(2);
    assert(false && "Should have thrown out_of_range");
  } catch (const std::out_of_range &e) {
  }

  ll.pop();
  assert(("Pop last item", ll.head->next == nullptr));
  assert(("Get first item after pop", ll.get(0) == 1));

  ll.pop();
  assert(("Pop first item", ll.head == nullptr));

  ll.append(1);
  ll.append(2);
  ll.insert(0, 0);
  assert(("Insert 0 at index 0", ll.get(0) == 0));
  assert(("Insert 1 at index 1", ll.get(1) == 1));
  assert(("Insert 2 at index 2", ll.get(2) == 2));

  ll.insert(1, 100);
  assert(("Insert 100 at index 1", ll.get(1) == 100));
  ll.insert(2, 200);
  assert(("Insert 200 at index 2", ll.get(2) == 200));

  std::println("All tests passed");

  return 0;
}
