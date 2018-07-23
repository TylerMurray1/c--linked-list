#include "SortedList.h"
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

template<class ItemType>
SortedList<ItemType>::SortedList(){
  listData = NULL;
  length = 0;
}//SortedList

template<class ItemType>
SortedList<ItemType>::~SortedList(){
  length = 0;
}//destructor

template<class ItemType>
bool SortedList<ItemType>::isEmpty() const{
  if(length == 0){
    return true;
  }
  else{
    return false;
  }
}//isEmpty

template<class ItemType>
int SortedList<ItemType>::getLength() const{
  return length;
}//getLength

template<class ItemType>
void SortedList<ItemType>::insertItem(ItemType newItem){
  NodeType<ItemType> * newNode; //pointer to inserted node
  NodeType<ItemType> * predLoc; //follower pointer
  NodeType<ItemType> * location; //traveling pointer
  location = listData;
  predLoc = NULL;


  //Find insertion point
  while(location != NULL){
    if(newItem > location -> info){
      predLoc = location;
      location = location->next;
    }
    else if(newItem < location->info){
      break;
    }
  }//while
  
  //Prepare node for insersion
  newNode = new NodeType<ItemType>;
  newNode->info = newItem;
  
  //insert node into list
  if(predLoc == NULL){
    newNode->next = listData;
    listData = newNode;
  }
  else{
    newNode->next = location;
    predLoc->next = newNode;
  }
  
  length++;

}//insertItem

template<class ItemType>
void SortedList<ItemType>::deleteItem(ItemType item){
  //findItem and then delete Item
  NodeType<ItemType> * pred;
  NodeType<ItemType> * temp;
  
  temp = listData;
  
  if(findItem(item, pred) && pred == NULL){
    temp = listData;
    listData = listData->next;
  }
  else{
    temp = pred -> next;
    pred->next = temp->next;
  }
  
  delete temp;
  length--;

}//deleteItem

template<class ItemType>
ItemType SortedList<ItemType>::get(int index){
  NodeType<ItemType> * temp;
  int i = 1;
  
  temp = listData;
  
  while(temp != NULL){
    if(i == index){
      return temp->info;
    }//if
    temp = temp->next;
    i++;
  }//while
  
}//get

template<class ItemType>
void SortedList<ItemType>::makeEmpty(){
  while(listData != NULL){
    NodeType<ItemType> * temp;
    temp = listData;
    listData = listData->next;
    delete temp;
  }
  
  length = 0;
}//makeEmpty

template<class ItemType>
void SortedList<ItemType>::printList(ofstream& file){
  NodeType<ItemType> * temp;
  temp = listData;
  while(temp != NULL){
    file << temp->info << " ";
    temp = temp->next;
  }//while
  file << endl;
}//printList

template<class ItemType>
SortedList<ItemType> SortedList<ItemType>::merge(SortedList<ItemType> otherList){
  
  NodeType<ItemType> * temp;
  temp = otherList.listData;
  
  while(temp != NULL){
    insertItem(temp->info);
    temp = temp->next;
  }
  
  
}//merge

template<class ItemType>
bool SortedList<ItemType>::findItem(ItemType item, NodeType<ItemType> *&predecessor){
  NodeType<ItemType> * temp;
  bool flag = false;
  temp = listData;
  
  //special case for if Item is in spot 1
  if(temp->info == item){
    predecessor = NULL;
    flag = true;
    return flag;
  }
  
  //set predecessor to spot 1 and temp to spot 2
  predecessor = listData;
  temp = temp->next;
  
  //go through until you find it incrementing temp and predecessor each iteration
  while(temp != NULL){
    if(temp->info == item){
      flag == true;
      break;
    }
    else{
      predecessor = predecessor->next;
      temp = temp->next;
    }
  }
    
  return flag;

}//findItem
