#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;
 
#ifndef SortedList_h
#define SortedList_h

template<class ItemType>
struct NodeType{
  
  ItemType info;
  NodeType<ItemType> * next;
  
};


template<class ItemType>
class SortedList{
  
 public:
  //constructor for the sorted list object
  SortedList();
  
  //destructor for the sorted list object
  ~SortedList();
  
  //checks to see if the list is empty
  bool isEmpty() const;

  //gets the length of the list and returns the number
  int getLength() const;

  //inserts a new item into the list
  void insertItem (ItemType newItem);

  //deletes an item from the list if it is already in there
  void deleteItem (ItemType item);

  //gets an item from the list with an index passed as a parameter
  ItemType get(int index);

  //sets the length of the list to 0
  void makeEmpty();

  //prints out the items in the list
  void printList(ofstream&);

  //merges two lists together and sorts them
  SortedList<ItemType> merge(SortedList<ItemType> otherList);

 private:

  //a pointer that points to the first node in the list
  NodeType<ItemType> * listData;
  
  //this represents the length of the list
  int length;

  //this finds an item in the list
  bool findItem(ItemType item, NodeType<ItemType> *&predecessor);
 
  
};

#endif
