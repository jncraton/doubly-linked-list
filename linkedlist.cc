#include <cassert>
#include <print>
#include <stdexcept>

class Node {
public:
  static inline int live_count = 0;
  
  Node *next;
  Node *prev;
  int data;

  Node(int data, Node *next = nullptr, Node *prev = nullptr) : data(data), next(next), prev(prev) {++live_count;}
  ~Node() {--live_count;}
};

class LinkedList {
public:
  Node *head;
  Node *tail;

  LinkedList() : head(nullptr), tail(nullptr) {}

  ~LinkedList() {
  }

  void append(int data) {
  }

  int get(int index) {
    return 0;
  }

  void pop() {
  }

  void insert(int index, int data) {

  int length() const {
    return 0;
  }
};

void test() {
  LinkedList ll;

  ll.append(1);
  assert(("List has content", ll.head != nullptr));
  assert(("Single item appended", ll.head->data == 1));
  assert(("Length is 1", ll.length() == 1));

  ll.append(2);
  assert(("First item untouched", ll.head->data == 1));
  assert(("Second item appended", ll.head->next->data == 2));
  assert(("Tail is correct", ll.tail->data == 2));
  assert(("Length is 2", ll.length() == 2));

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
  assert(("Tail is correct after pop", ll.tail->data == 1));
  assert(("Length after pop", ll.length() == 1));

  ll.pop();
  assert(("Pop first item", ll.head == nullptr));
  assert(("Tail is null after pop", ll.tail == nullptr));
  assert(("Length after pop all", ll.length() == 0));

  ll.append(1);
  ll.append(2);
  ll.insert(0, 0);
  assert(("Insert 0 at index 0", ll.get(0) == 0));
  assert(("Insert 1 at index 1", ll.get(1) == 1));
  assert(("Insert 2 at index 2", ll.get(2) == 2));
  assert(("Length after inserts", ll.length() == 3));

  ll.insert(1, 100);
  assert(("Insert 100 at index 1", ll.get(1) == 100));
  ll.insert(2, 200);
  assert(("Insert 200 at index 2", ll.get(2) == 200));
  assert(("Length after more inserts", ll.length() == 5));

  LinkedList ll2;
  ll2.append(10);
  ll2.pop();
  assert(("Pop from single item list", ll2.head == nullptr));
  assert(("Length is 0", ll2.length() == 0));

  ll2.append(20);
  ll2.pop();
  assert(("Pop from single item list again", ll2.head == nullptr));
  assert(("Length is 0 again", ll2.length() == 0));

  try {
    ll2.get(0);
    assert(false && "Should have thrown out_of_range");
  } catch (const std::out_of_range &e) {
  }

  ll2.append(30);
  ll2.append(40);
  ll2.insert(1, 35);
  assert(("Insert in middle", ll2.get(0) == 30));
  assert(("Insert in middle", ll2.get(1) == 35));
  assert(("Insert in middle", ll2.get(2) == 40));
  assert(("Length is 3", ll2.length() == 3));

  try {
    ll2.insert(10, 100);
    assert(false && "Should have thrown out_of_range");
  } catch (const std::out_of_range &e) {
  }

  try {
    ll2.insert(-1, 100);
    assert(false && "Should have thrown out_of_range");
  } catch (const std::out_of_range &e) {
  }

  {
    LinkedList ll3;
    ll3.append(1);
    ll3.append(2);
    ll3.append(3);
    assert(("Length is 3", ll3.length() == 3));
  }
}

int main() {
  test();

  assert(("All nodes deleted", Node::live_count == 0));
  std::println("All tests passed");

  return 0;
}