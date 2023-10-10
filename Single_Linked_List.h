#include <iostream>
#include <cstddef>
using namespace std;

#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

template <typename Item_Type>
class Single_Linked_List {
private:
  //Node struct that contains the data, pointer to the next node, and the constructor for the node struct
  struct Node {
    Item_Type data;
    Node* next;
    Node(const Item_Type& item) : data(item), next(nullptr) {}
  };

  Node* head; //Node pointer to the top of the list
  Node* tail; //Node pointer to the end of the list
  size_t num_items;  //number of items in the list

public:
  Single_Linked_List();
  ~Single_Linked_List();
  void push_front(const Item_Type& item);
  void push_back(const Item_Type& item);
  void pop_front();
  void pop_back();
  Item_Type front() const;
  Item_Type back() const;
  bool empty() const;
  void insert(size_t index, const Item_Type& item);
  bool remove(size_t index);
  size_t find(const Item_Type& item) const;
};

#endif