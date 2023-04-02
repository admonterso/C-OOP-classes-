#include <iostream>
#include <list>
using namespace std;

// Define a struct representing a car
struct car
{
    string model;    // Car model
    string color;    // Car color
    double engVal;   // Car engine value
    int trip;        // Car trip value

    // Constructor to initialize the member variables
    car(string Model, string Color, double EngVal, int Trip){
        model = Model;
        color = Color;
        engVal = EngVal;
        trip = Trip;
    }

    // Overload the == operator to compare cars based on their model
    bool operator==(car CAR){
        return this->model == CAR.model;
    }
};

// Overload the << operator to print car information to console
ostream& operator<<(ostream& COUT, car& Car){
    cout << "model: " << Car.model << endl;
    cout << "color: " << Car.color << endl;
    cout << "engine Value: " << Car.engVal << endl;
    cout << "trip: " << Car.trip << endl;
}

// Define a struct representing a collection of cars
struct myCars
{
    list<car>mycars;    // List of car objects
    
    // Overload the += operator to add a car to the list
    void operator+=(car& CAR){
        this->mycars.push_back(CAR);
    }

    // Overload the -= operator to remove a car from the list
    void operator-=(car& CAR){
        this->mycars.remove(CAR);
    }
};

// Overload the << operator to print the list of cars to console
ostream& operator<<(ostream& COUT, myCars& Car){
    for(car CAR: Car.mycars){
        COUT<<CAR<<endl;
    }
};

// Main function
int main()
{
    // Create two car objects
    car mecedes = car("G-Class", "red", 5.5, 0);
    car BMW = car("M5", "blue", 4.4, 100);
    
    // Create a myCars object and add one car to it
    myCars MYCARS;
    MYCARS += mecedes;
    
    // Remove a car from the myCars object
    MYCARS -= BMW;
    
    // Print the list of cars to console
    cout << MYCARS;
    
    return 0;
}
