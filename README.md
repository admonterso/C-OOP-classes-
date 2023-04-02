Person class
A simple C++ program that demonstrates the use of inheritance and polymorphism.

Overview
The program defines three classes: person, sportsMan, and student. sportsMan and student both inherit from person.

A person object has three data members: Name, LastName, and Age. It also has a constructor that initializes these data members, as well as getter methods to access them. The person class also defines a virtual method called status, which outputs "No info".

sportsMan is a subclass of person and adds a new data member sport. It also overrides the status method to output "currently at gym".

student is another subclass of person and adds a new data member faculty. It also overrides the status method to output "currently student".

The main function creates instances of sportsMan and student objects, and assigns them to person pointers. It then calls the status method on each pointer, demonstrating the use of polymorphism.

Running the Program
To run the program, compile the source code with a C++ compiler and run the resulting executable. The program will output:


currently at gym
currently student
This demonstrates that the status method is being correctly overridden by the sportsMan and student subclasses of person.
