///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_final_exam - EE 205 - Spr 2022
///
/// @file actualfile.cpp
/// @version 1.0
///
/// @author <murrayn@hawaii.edu>
/// @date   13_May_2022
///////////////////////////////////////////////////////////////////////////////
#include <iostream>

class Shape{
public:
    virtual double compute_area() = 0;
};

class Rectangle : public Shape {
public:

    virtual double compute_area(){
        return length*width;
    }
    Rectangle(double newLength, double newWidth){
        if(newLength<0 || newWidth<0){
            throw std::invalid_argument("Length must be > 0.");
        }
        length = newLength;
        width = newWidth;
    };

    double getLength() const noexcept{
        return length;
    }

    double getWidth() const noexcept{
        return width;
    }


protected:
    double length;
    double width;
};

class Square : public Rectangle, public Shape {
public:
    double getSide(){
        return length;
    }

    Square(double newLength, double newWidth, double newSide) : Rectangle(newLength, newWidth) {
        length = newSide;
    }

};
int main() {
    std::cout << "Hello, World!" << std::endl;

    Square mySquare(2);
    std::cout << "The area of mySquare is: "
              << mySquare.compute_area()
              << std::endl;


    Rectangle myRectangle( 2, 4 );
    std::cout << "The area of myRectangle is: "
              << myRectangle.compute_area()
              << std::endl;

    return 0;
}