// Test driver SortedListDr.cpp                                                                                                 
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>
#include "SortedList.h"
#include "SortedList.cpp"
#include "Student.h"
#include "Student.cpp"

using namespace std;

//This function tests the SortedList() with integers
void testIntegersList();

//This function tests the SortedList() with characters
void testCharactersList();

//This function tests the SortedList() with Students
void testStudentsList();

//the main driver function of the program
int main(){
  int datatype;
  // Prompt user to enter type of elements                                                                                      
  cout << "Enter Elements Type\n1 for integer\n2 for character\n3 for Student\n";
  cin >> datatype;
  switch (datatype){
  case 1: testIntegersList();
    break;
  case 2: testCharactersList();
    break;
  case 3: testStudentsList();
    break;
  }
  //....append any needed code here                                                                                       
  return 0;
}


void testIntegersList(){
  SortedList<int> list;
  string command;
  ifstream inFile;
  ofstream outFile;
  inFile.open("intcommands.txt");
  outFile.open("outFile.txt");
  inFile >> command; // read commands from a text file                                                                            
  while (command != "Quit"){
    if (command == "isEmpty"){
      if(list.isEmpty())
	outFile << "list is empty" << endl;
      else
	outFile << "list is not empty" << endl;
    }
    else if (command == "insertItem"){
      int number;
      inFile >> number;
      bool isFound = false;
      for(int i = 1; i <= list.getLength(); i++){
	  if(list.get(i) == number){
	    isFound = true;
	    break;
	  }
      }//for                                                                                                     
      
      if(!isFound){
	list.insertItem(number);
      }
      else{
	outFile << "item is a duplicate" << endl;
      }
    }
    else if (command == "merge"){
      
      SortedList<int> otherList;
      int item;
      
      while(inFile.peek() != '\n'){
	inFile >> item;
	bool isFound = false;
	for(int i = 1; i <= list.getLength(); i++){
	  if(list.get(i) == item){
	    isFound = true;
	    break;
	  }
	}//for                                                                                                            
	
	if(!isFound){
	  otherList.insertItem(item);
        }
	
      }//while
      
      list.merge(otherList);
      
    }
    else if (command == "printList"){
      list.printList(outFile);
    }
    else if (command == "deleteItem"){
      bool isFound = false;
      int number;
      inFile >> number;
      for(int i = 1; i <= list.getLength(); i++){
	if(list.get(i) == number){
	  isFound = true;
	  break;
	}
      }//for                                                                                                  
      
      if(isFound){
	list.deleteItem(number);
      }
      else{
	outFile << "item not in list" << endl;
      }
      
    }
    else if (command == "get"){
      int number;
      inFile >> number;
      if(number >= 1 && number <= list.getLength()){
	outFile << list.get(number) << endl;
      }
      else{
	outFile << "index out of range" << endl;
      }
      
    }
    else if (command == "makeEmpty"){
      list.makeEmpty();
    }
    else if(command == "getLength"){
      outFile << list.getLength() << endl;
    }
    else{
      outFile << "undefined command" << endl;
    }
    // add other cases here to cover all possible commands and any invalid command....                                     
    inFile >> command;
  } // while                                                                                                                
  
} //testIntegersList

void testCharactersList(){
  SortedList<char> list;
  string command;
  ifstream inFile;
  ofstream outFile;
  inFile.open("chcommands.txt");
  outFile.open("outFile.txt");
  inFile >> command; // read commands from a text file                                                                      
  while (command != "Quit"){
    if (command == "isEmpty"){
      if(list.isEmpty())
	outFile << "list is empty" << endl;
	   else
	     outFile << "list is not empty" << endl;
    }
    else if (command == "insertItem"){
      char number;
      inFile >> number;
      bool isFound = false;
      for(int i = 1; i <= list.getLength(); i++){
	if(list.get(i) == number){
	  isFound = true;
	  break;
	}
      }//for                                                                                                 
      
      if(!isFound){
	list.insertItem(number);
      }
      else{
	outFile << "item is a duplicate" << endl;
      }
    }
    else if (command == "merge"){
      SortedList<char> otherList;
      char item;
      while(inFile.peek() != '\n'){
	inFile >> item;
	bool isFound = false;
	for(int i = 1; i <= list.getLength(); i++){
	  if(list.get(i) == item){
	    isFound = true;
	    break;
	  }
	}//for                                                                                                        
	
	if(!isFound){
	  otherList.insertItem(item);
	}
	
      }//while 
 
      list.merge(otherList);
      
    }
    else if (command == "printList"){
      list.printList(outFile);
    }
    else if (command == "deleteItem"){
      bool isFound = false;
      char character;
      inFile >> character;
      for(int i = 1; i <= list.getLength(); i++){
	if(list.get(i) == character){
	  isFound = true;
	  break;
	}
      }//for                                                                                                  
      
      if(isFound){
	list.deleteItem(character);
      }
      else{
	outFile << "item not in list" << endl;
      }
      
    }
    else if (command == "get"){
      int number;
      inFile >> number;
      if(number >= 1 && number <= list.getLength()){
	outFile << list.get(number) << endl;
      }
      else{
	outFile << "index out of range" << endl;
      }
      
    }
    else if (command == "makeEmpty"){
      list.makeEmpty();
    }
    else if(command == "getLength"){
      outFile << list.getLength() << endl;
    }
    else{
      outFile << "undefined command" << endl;
    }
    // add other cases here to cover all possible commands and any invalid command....                                 
    inFile >> command;
  } // while
}//characterTest

void testStudentsList(){
  SortedList<Student> list;
  string command;
  ifstream inFile;
  ofstream outFile;
  Student StudentObj;
  int ID;
  string name;
  inFile.open("studcommands.txt");
  outFile.open("outFile.txt");
  inFile >> command; // read commands from a text file                                                                       
  while (command != "Quit"){
    if (command == "isEmpty"){
      if(list.isEmpty())
	outFile << "list is empty" << endl;
      else
	outFile << "list is not empty" << endl;
    }
    else if (command == "insertItem"){
      inFile >> ID >> name;
      StudentObj.setID(ID);
      StudentObj.setName(name);
      bool isFound = false;
      for(int i = 1; i <= list.getLength(); i++){
	if(list.get(i) == StudentObj){
	  isFound = true;
	  break;
	}
      }//for                                                                                                           
      
      if(!isFound){
	list.insertItem(StudentObj);
      }
      else{
	outFile << "item is a duplicate" << endl;
      }
    }
    else if (command == "merge"){
      SortedList<Student> otherList;
      Student item;

      while(inFile.peek() != '\n'){
	inFile >> item;
	item.setID(ID);
	item.setName(name);
	bool isFound = false;
	for(int i = 1; i <= list.getLength(); i++){
	  if(list.get(i) == item){
	    isFound = true;
	    break;
	  }
	}//for                                                                                              
	
	if(!isFound){
	  otherList.insertItem(item);
	}
	
      }//while 
      
      list.merge(otherList);
      
    }
    else if (command == "printList"){
      list.printList(outFile);
    }
    else if (command == "deleteItem"){
      bool isFound = false;
      inFile >> ID;
      Student s;
      for(int i = 1; i <= list.getLength(); i++){
	if(list.get(i).getID() == ID){
	  s = list.get(i);
	  isFound = true;
	  break;
	}
      }//for                                                                                                       
      
      if(isFound){
	list.deleteItem(s);
      }
      else{
	outFile << "item not in list" << endl;
      }
      
    }
    else if (command == "get"){
      int number;
      inFile >> number;
      if(number >= 1 && number <= list.getLength()){
	outFile << list.get(number) << endl;
      }
      else{
	outFile << "index out of range" << endl;
      }
      
    }
    else if (command == "makeEmpty"){
      list.makeEmpty();
    }
    else if(command == "getLength"){
      outFile << list.getLength() << endl;
    }
    else{
      outFile << "undefined command" << endl;
    }
    // add other cases here to cover all possible commands and any invalid command....                                      
    inFile >> command;
  } // while 
}//studentList
