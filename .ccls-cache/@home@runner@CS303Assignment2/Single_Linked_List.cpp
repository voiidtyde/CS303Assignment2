#include "Single_Linked_List.h"

template <typename Item_Type>
// Creates an empty linked list with data "Item type". Sets head and tail to nullptr
Single_Linked_List<Item_Type>::Single_Linked_List() {
  head = nullptr;
  tail = nullptr;
  num_items = 0;
}

//The destructor uses the pop_front function to delte all nodes in the linked list
template <typename Item_Type>
Single_Linked_List<Item_Type>::~Single_Linked_List() {
  while (!empty()) {
    pop_front();
  }
}

template <typename Item_Type>
//Adds a new node with data "item" to the front of the linked list
void Single_Linked_List<Item_Type>::push_front(const Item_Type& item) {
  Node* newNode = new Node(item);
  //If the list is empty, set the head and tail of the linked list to the new node
  if (empty()) {
    tail = newNode;
    head = newNode;
  }
  //Normally, set the pointer of the new node to the head and set the head pointer to the node.
  else {
    newNode->next = head;
    head = newNode;
  }
  num_items++; // incrememnt num_items
}

template <typename Item_Type>
//Adds a new node with data "item" to the end of the linked list
void Single_Linked_List<Item_Type>::push_back(const Item_Type& item) {
  Node* newNode = new Node(item);
  //If the list is empty, set the head and tail of the linked list to the new node
  if (empty()) {
    tail = newNode;
    head = newNode;
  }
  else {
    //Normally, set the pointer of the new node to the tail and set the tail pointer to the node.
    newNode->next = tail;
    tail = newNode;
  }
  num_items++;
}

template <typename Item_Type>
//Removes the node that is at the front of the linked list
void Single_Linked_List<Item_Type>::pop_front() {
  if (!empty()) {
    Node* tempNode = head; //Set the current head to a temporary node
    head = head->next; //Set the current head to the next space.
    delete tempNode; //Remove the old head
    num_items--; //decrement num_items
  }
}

// Removes the node at the end of the list.
template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_back() {
  if (!empty()) {
    if (num_items == 1) {
      delete head;  // If there is only one node, delete it and update head and tail.
      head = nullptr;
      tail = nullptr;
    }
    else {
      Node* tempNode = head;
      while (tempNode->next != tail) {
        tempNode = tempNode->next;  // Traverse to the node before tail.
      }
      delete tail;  // Delete the current tail node.
      tail = tempNode;  // Update tail to the previous node.
      tail->next = nullptr;  // Set the next of the new tail to nullptr.
    }
    num_items--;
  }
}

// Returns the item stored in the front node.
template <typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::front() const {
  if (!empty()) {
    return head->data;  // Return the data stored in the head node.
  }
  else {
    throw std::out_of_range("Linked List is empty!");
  }
}

// Returns the item stored in the back node.
template <typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::back() const {
  if (!empty()) {
    return tail->data;  // Return the data stored in the tail node.
  }
  else {
    throw std::out_of_range("Linked List is empty!");
  }
}

// Checks if the linked list is empty.
template <typename Item_Type>
bool Single_Linked_List<Item_Type>::empty() const {
  if (num_items == 0) {
    return true;
  }
  return false;
}

// Inserts a new node with the given item at the specified index.
template <typename Item_Type>
void Single_Linked_List<Item_Type>::insert(size_t index, const Item_Type& item) {
  if (index == 0) {
    push_front(item);  // If the index is 0, insert at the front of the list.
  }
  if (index == (num_items - 1)) {
    push_back(item);  // If the index is the last element, insert at the back of the list.
  }
  else {
    Node* newNode = new Node(item);  // Create a new node with the given item.
    Node* previousNode = head;  // Initialize a pointer to traverse the list.
    for (size_t i = 1; i < index; i++) {
      previousNode = previousNode->next;  // Traverse to the node before the insertion point.
    }
    newNode->next = previousNode->next;  // Point the new node to the next node.
    previousNode->next = newNode;  // Update the previous node's next pointer.
    num_items++;
  }
}

// Removes the node at the specified index.
template <typename Item_Type>
bool Single_Linked_List<Item_Type>::remove(size_t index) {
  if (empty()) {
    return false;  // If the list is empty, no removal is possible.
  }
  if (index >= num_items) {
    return false;  // If the index is out of bounds, return false.
  }
  if (index == 0) {
    pop_front();  // If the index is 0, remove the front node.
  }
  if (index == num_items - 1) {
    pop_back();  // If the index is the last element, remove the back node.
  }
  else {
    Node* previousNode = head;  // Initialize a pointer to traverse the list.
    for (size_t i = 1; i < index; i++) {
      previousNode = previousNode->next;  // Traverse to the node before the removal point.
    }
    Node* tempNode = previousNode->next;  // Store the node to be removed.
    previousNode->next = tempNode->next;  // Update the previous node's next pointer.
    delete tempNode;  // Deallocate memory for the removed node.
    if (index == num_items - 1) {
      tail = previousNode;  // If the removed node was the tail, update the tail.
    }
    num_items--;
  }
  return true;
}

// Finds the index of the first occurrence of the given item.
template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::find(const Item_Type& item) const {
  Node* currentNode = head;  // Initialize a pointer to traverse the list.
  size_t index = 0;
  while (currentNode->data != tail->data) {  // Traverse until the tail is reached.
    if (currentNode->data == item) {
      return index;  // If the item is found, return its index.
    }
    currentNode = currentNode->next;  // Move to the next node.
    index++;
  }
  return num_items; //If the item is not found, return the number of items in the list.
}
