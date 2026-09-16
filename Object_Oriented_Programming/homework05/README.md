# Homework5 - Rectangle Class (Aggregation)

Design a Length class having two member variables: centimeters and millimeters. The class should have constructors and member functions to input and return member variables. It should also overload the operators ==, + and *.

Design another class Rectangle that should comprise two Length objects, representing the two adjacent sides of a rectangle. The class should have the following member functions:
* `setSides` : This member function should ask the user to input the values of the sides of the rectangle and accordingly set the value of the lengths by calling the set function of the Length class.
* `getSides` : This member function should call the get function of the Length class to display the sides of the rectangle.
* `isSquare` : This function should return a Boolean value True if the rectangle is a square, that is, if. its sides are equal; otherwise it should return False.
* `getArea` : This should return the area of which is, the product of its two all its four sides. 
* `getPerimeter` : This should return the perimeter of the rectangle, which is. the sum of all its four sides.

Demonstrate the classes in a program that creates a Rectangle object and calls all its member functions.