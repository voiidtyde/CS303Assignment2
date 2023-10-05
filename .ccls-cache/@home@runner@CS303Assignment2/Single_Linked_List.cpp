#include "Single_Linked_List.h"

template <typename Item_Type>
Single_Linked_List<Item_Type>::Single_Linked_List() {
  head = nullptr;
  tail = nullptr;
  num_items = 0;
}

template <typename Item_Type>
Single_Linked_List<Item_Type>::~Single_Linked_List() {
  while (!empty()) {
    pop_front();
  }
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_front(const Item_Type& item) {
  Node* newNode = new Node(item);
  if (empty()) {
    tail = newNode;
    head = newNode;
  }
  else {
    newNode->next = head;
    head = newNode;
  }
  num_items++;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_back(const Item_Type& item) {
  Node* newNode = new Node(item);
  if (empty()) {
    tail = newNode;
    head = newNode;
  }
  else {
    newNode->next = tail;
    tail = newNode;
  }
  num_items++;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_front() {
  if (!empty()) {
    Node* tempNode = head;
    head = head->next;
    delete tempNode;
    num_items--;
  }
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_back() {
  if (!empty()) {
    if (num_items == 1) {
      delete head;
      head = nullptr;
      tail = nullptr;
    }
    else {
      Node* tempNode = head;
      while (tempNode->next != tail) {
        tempNode = tempNode->next;
      }
      delete tail;
      tail = tempNode;
      tail->next = nullptr;
    }
    num_items--;
  }
}

template <typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::front() const {
  if (!empty()) {
    return head->data;
  }
  else {
    throw std::out_of_range("Linked List is empty!");
  }
}

template <typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::back() const {
  if (!empty()) {
    return tail->data;
  }
  else {
    throw std::out_of_range("Linked List is empty!");
  }
}

template <typename Item_Type>
bool Single_Linked_List<Item_Type>::empty() const {
  if (num_items == 0) {
    return true;
  }
  return false;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::insert(size_t index, const Item_Type& item) {
  if (index == 0) {
    push_front(item);
  }
  if (index == (num_items - 1)) {
    push_back(item);
  }
  else {
    Node* newNode = new Node(item);
    Node* previousNode = head;
    for (size_t i = 1; i < index; i++) {
      previousNode = previousNode->next;
    }
    newNode->next = previousNode->next;
    previousNode->next = newNode;
    num_items++;
  }
}

template <typename Item_Type>
bool Single_Linked_List<Item_Type>::remove(size_t index) {
  if (empty()) {
    return false;
  }
  if (index > num_items) {
    return false;
  }
  if (index == 0) {
    pop_front();
  }
  if (index == num_items - 1) {
    pop_back();
  }
  else {
    Node* previousNode = head;
    for (size_t i = 1; i < index; i++) {
      previousNode = previousNode->next;
    }
    Node* tempNode = previousNode->next;
    previousNode->next = tempNode->next;
    delete tempNode;
    if (index == num_items - 1) {
      tail = previousNode;
    }
    num_items--;
  }
  return true;
}

template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::find(const Item_Type& item) const {
  Node* currentNode = head;
  size_t index = 0;
  while (currentNode->data != tail->data) {
    if (currentNode->data == item) {
      return index;
    }
    currentNode = currentNode->next;
    index++;
  }
  return num_items;
}
