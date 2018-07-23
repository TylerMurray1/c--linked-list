#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#ifndef Student_h
#define Student_h

class Student{
 public:
  
  //the constructor for the student object
  Student();

  //an overloaded constructor that takes in a name and IDnumber
  Student(int IDNumber, string Name);

  //setter for the name of the object
  void setName(string name);

  //setter for the ID of an object
  void setID(int ID);

  //gets the ID of a student object
  int getID();

  //gets the name of a student object
  string getName();

  //sets a student to another student
  void setStudent(Student s);

  //operator overload for ==
  bool operator==(Student s);

  //operator overload for !=
  bool operator!=(Student s);

  //operator overload for <
  bool operator<(Student s);

  //operator overload for >
  bool operator>(Student s);


 private:
  
  //variable that contains the ID of the student
  int studentID;

  //variable that contains the name of the student
  string studentName;
  
};

#endif
