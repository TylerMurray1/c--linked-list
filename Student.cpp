#include "Student.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

//This is the default constructor of the student class                                                                        
Student::Student(){
  studentID = 0;
  studentName = "";
}//Constructor

//This is the overlaoded constructor that takes in a passed in ID number and name for the student
Student::Student(int IDNumber, string Name){
  studentID = IDNumber;
  studentName = Name;
}//Constructor

//This function sets the ID for the student
void Student::setID(int ID){
  studentID = ID;

}//setID

//This function sets the name of the student
void Student::setName(string Name){
  studentName = Name;
}//setName

//This function gets the ID of the student object calling on it
int Student::getID(){
  return studentID;
}//getID

//This function gets the name of the student object calling on it
string Student::getName(){
  return studentName;
}//getName

//This is the assignment operator overload for the student class
bool Student::operator==(Student s){
  if(this->studentID == s.studentID){
    return true;
  }
  else{
    return false;
  }
}//operaterOverload==

//This is the not equal to assignment operator overload
bool Student::operator!=(Student s){
  if(this->studentID != s.studentID){
    return true;
  }
  else{
    return false;
  }
}//operatorOverload!=

//This is the less than assignment operator overload
bool Student::operator<(Student s){
  if(this->studentID < s.studentID){
    return true;
  }
  else{
    return false;
  }
}//operatorOverload<

//This is the greater than assignment operator overload
bool Student::operator>(Student s){
  if(this->studentID > s.studentID){
    return true;
  }
  else{
    return false;
  }
}//operatorOverload>

//This is the stream operator overload that is not a member function
ostream& operator<<(ostream& os, Student s){
  os << s.getID() << " " << s.getName();
  return os;
}//operatorOverload<<

//This is the stream operator overload that is not a member function 
istream& operator>>(istream &is, Student s){
  string name;
  int ID;

  is >> ID;
  is >> name;

  s.setID(ID);
  s.setName(name);
    
  return is;
}
