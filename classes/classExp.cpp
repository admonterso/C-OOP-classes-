#include <iostream>

using namespace std;
class person {
private: 
  string Name;
  string LastName;
  int Age;
public:
    string getName(){
        return Name;
    }
    string getLastName(){
        return LastName;
    }
    int age(){
        return Age;
    }
    void introd(){
        cout << "Name - "<< Name << endl;
        cout << "Last Name -"<< LastName << endl;
        cout << "Age -" << Age << endl; 
    }
    person(string name, string lastName, int age){
        Name = name;
        LastName = lastName;
        Age = age;
    }
    virtual void status(){
        cout << "No info" << endl;
    }
};

class sportsMan :public person{
private:
    string sport;
public:
    string getSport(){
        return sport;
    }
    void status(){
        cout << "currently at gym" << endl;
    }
    sportsMan(string name, string lastName, int age, string Sport)
        :person(name,lastName,age)
    {
        sport = Sport;
    }
};

class student :public person{
private:
    string faculy;
public:
    string getFaculty(){
        return faculy;
    }
    void status(){
        cout << "currently student" << endl;
    }
    student(string name, string lastName, int age, string Faculy)
        :person(name, lastName, age)
    {
        faculy = Faculy;
    }
};
int main()
{
    sportsMan a = sportsMan("kaxa", "gvimradze", 21, "jog");
    student b = student("kaxa", "gvimradze", 21, "IBSU");
    
    person *p1 = &a;
    person *p2 = &b;
    
    p1->status();
    p2->status();
    return 0;
}