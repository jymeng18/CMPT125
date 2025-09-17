/*
* Filename: Circle.cpp
*
* Desc: Description: This class models a circle ...
* Class Invariant: The circle's radius must be greater than 0.0

* Author: Jerry Meng 
* Creation Data: July 25th 2025
*/

#include <iostream>
#include "Circle.h"
#include <cmath>

using std::cout;
using std::endl;

/* Method implementations */

// Default Constructor:
Circle::Circle(){
    x_coord = 0;
    y_coord = 0;
    radius = DEFAULT_VALUE;
}

// Parameterized Constructor:
Circle::Circle(int x, int y, double r){
    x_coord = x;
    y_coord = y;
    
    // Ensure class invariant is valid
    radius = (r > 0.0) ? r : DEFAULT_VALUE;
}

/* Getters: Return info about circle */

// Returns the x-coordinate of circle centre
int Circle::getX() const {
    return x_coord;
}

// Returns the y-coordinate of circle centre
int Circle::getY() const {
    return y_coord;
}

// Returns the radius of the circle
double Circle::getRadius() const {
    return radius;
}

/* Setters: Sets values of attributes*/

// Moves the circle by the given horiz and vert distances
void Circle::move(int horiz, int vert){
    x_coord += horiz;
    y_coord += vert;
    return;
}

// Sets the radius of the circle
void Circle::setRadius(double r){

    // Ensure that 'r' is not <= 0.0
    radius = (r > 0.0) ? r : DEFAULT_VALUE; 
    return;
}

/* Methods - Specific to Problem Statement */ 

// Returns the area of the circle
double Circle::computeArea() const {
    return M_PI * radius * radius;
}

// Prints out all data members of the circle 
void Circle::printCircle() const {
    cout << "This circle has a radius of " << radius;
    cout << " and its centre is at (" << x_coord << "," << y_coord << ")." << endl;
    return;
}

// Check if calling circle intersects with Circle object
bool Circle::intersect(Circle c) const {

    // Circles are intersecting if | r1 - r2 | <= distance between centers of circles <= r1 + r2
    // distance between centers of circles: sqrt(x2-x1)^2 + (y2-y1)^2)

    double distance_x = c.getX() - x_coord; 
    double distance_y = c.getY() - y_coord;
    double d = sqrt(distance_x * distance_x + distance_y * distance_y);
    double left_bound = fabs(radius - c.getRadius());
    double right_bound = radius + c.getRadius();

    if(left_bound <= d && d <= right_bound){
        return true;
    }
    else{
        return false;
    }
}
