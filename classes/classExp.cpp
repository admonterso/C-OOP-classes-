#include <iostream>
#include <string>

// Add a comment to indicate that this is a command for compiling the code
// using GCC and linking with the C++ standard library
// Note: remove the exclamation marks when copying and pasting the command
// in the terminal, they are only used here to emphasize the importance of
// this comment.
// !!!!!!!!!!!!!!!!!!!!!! gcc -o pr1 classExp.cpp -lstdc++ compyle command !!!!!!!!

using namespace std;

// Define a base class called "person"
class person {
private: 
  string Name;
  string LastName;
  int Age;
public:
    // Define three member functions to get the person's name, last name, and age
    string getName(){
        return Name;
    }
    string getLastName(){
        return LastName;
    }
    int age(){
        return Age;
    }

    // Define a member function to print the person's name, last name, and age
    void introd(){
        cout << "Name - "<< Name << endl;
        cout << "Last Name -"<< LastName << endl;
        cout << "Age -" << Age << endl; 
    }

    // Define a constructor that takes the person's name, last name, and age as input
    person(string name, string lastName, int age){
        Name = name;
        LastName = lastName;
        Age = age;
    }

    // Define a virtual member function that prints a message indicating that
    // there is no information available about the person's status
    virtual void status(){
        cout << "No info" << endl;
    }
};

// Define a derived class called "sportsMan" that inherits from "person"
class sportsMan :public person{
private:
    string sport;
public:
    // Define a member function to get the sport that the sportsman is involved in
    string getSport(){
        return sport;
    }

    // Define a member function that overrides the "status" function in the base class
    // and prints a message indicating that the sportsman is currently at the gym
    void status(){
        cout << "currently at gym" << endl;
    }

    // Define a constructor that takes the sportsman's name, last name, age, and sport as input
    sportsMan(string name, string lastName, int age, string Sport)
        :person(name,lastName,age)
    {
        sport = Sport;
    }
};

// Define another derived class called "student" that also inherits from "person"
class student :public person{
private:
    string faculy;
public:
    // Define a member function to get the faculty that the student is enrolled in
    string getFaculty(){
        return faculy;
    }

    // Define a member function that overrides the "status" function in the base class
    // and prints a message indicating that the student is currently a student
    void status(){
        cout << "currently student" << endl;
    }

    // Define a constructor that takes the student's name, last name, age, and faculty as input
    student(string name, string lastName, int age, string Faculy)
        :person(name, lastName, age)
    {
        faculy = Faculy;
    }
};
int main()
{
    //Make example objects
    sportsMan a = sportsMan("kaxa", "gvimradze", 21, "jog");
    student b = student("kaxa", "gvimradze", 21, "IBSU");
    
    person *p1 = &a;
    person *p2 = &b;
    
    p1->status();
    p2->status();
    return 0;
}