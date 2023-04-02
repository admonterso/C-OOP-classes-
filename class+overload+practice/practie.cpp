#include <iostream>

using namespace std;

// Define a class called "box"
class box{
private:
    int height;  // the height of the box
    int length;  // the length of the box
    int width;   // the width of the box
public:
    // Getter methods for the box's height, length, and width
    int getHeight(){
        return height;
    }
    int getLength(){
        return length;
    }
    int getWidth(){
        return width;
    }
    // A method that calculates and returns the volume of the box
    int getValue(){
        return height*width*length;
    }    
    // A constructor for the box class that takes in the height, length, and width
    box(int Height, int Length, int Width){
        height = Height;
        length = Length;
        width = Width;
    }

    // Overloaded "+" operator to add two boxes together
    box operator + (box& New){
        int NewHeight = height + New.height;
        int NewWidth = width + New.width;
        int NewLength = length + New.length;

        return box(NewHeight, NewLength, NewWidth);

    }

    // Overloaded "-" operator to subtract one box from another
    box operator - (box& New){
        int NewHeight = height - New.height;
        int NewWidth = width - New.width;
        int NewLength = length - New.length;
        if(NewLength >= 0 && NewHeight >=0 && NewWidth >=0){
            
            return box(NewHeight, NewLength, NewWidth);
        }
        cout<<"cant subtract"<<endl;

    }

    // Overloaded "++" operator to increment the box's height, length, and width by 1
    box operator++(int) {
            box result(height, length, width);  // create a copy with original values
            height++;
            length++;
            width++;
            return result;
    }

    // Overloaded "+" operator to add an integer to the box's height, length, and width
    box operator + (int num){
        int NewHeight = height + num;
        int NewWidth = width + num;
        int NewLength = length + num;

        return box(NewHeight, NewLength, NewWidth);

    }

    // Overloaded "==" operator to check if two boxes have the same height, length, and width
    bool operator==(box& BOX){
        if(height == BOX.height && length == BOX.length && width == BOX.width){
            return true;
        }
        else{
            return false;
        }
    }

    // Overloaded "--" operator to decrement the box's height, length, and width by 1
    box operator--(int) {
            box result(height, length, width);  // create a copy with original values
            height--;
            length--;
            width--;
            return result;
    }

};

// Overloaded "<<" operator to output the box's height, length, width, and volume
ostream& operator<<(ostream& COUT, box& BOX){
    cout << "height: " << BOX.getHeight() << endl;
    cout << "width: " << BOX.getWidth() << endl;
    cout << "length: " << BOX.getLength() << endl;
    cout << "volume: " << BOX.getValue() << endl;

}

int main()
{
    // create box objects with given dimensions
    box box1(2, 3, 4);
    box box2(1, 2, 3);

    // add the two box objects together and assign the result to box3
    box box3 = box1 + box2;

    // print the dimensions and volume of box3
    cout << box3 << endl;

    // increment the dimensions of box3 by 1 using the ++ operator
    box3++;

    // print the updated dimensions and volume of box3
    cout << box3 << endl;

    // add 2 to the dimensions of box3 using the + operator
    box3 = box3 + 2;

    // print the updated dimensions and volume of box3
    cout << box3 << endl;

    // decrement the dimensions of box3 by 1 using the -- operator
    box3--;

    // print the updated dimensions and volume of box3
    cout << box3 << endl;

    // check if box1 is equal to box2 using the == operator
    if (box1 == box2) {
        cout << "box1 is equal to box2" << endl;
    } else {
        cout << "box1 is not equal to box2" << endl;
    }

    return 0;
}
