/*
* Circle.h
*
* Description: This class models a circle ...
* Class Invariant: The circle's radius must be greater than 0.0

* Author: Jerry Meng 
* Creation date: July 25th 2025
*/

#ifndef CIRCLE_H
#define CIRCLE_H

// Definition of a circle class
class Circle {

  private: //everything that follows is private and cannot be "seen" from outside the class

  // Attributes
  int x_coord;
  int y_coord;
  double radius; 

  const double DEFAULT_VALUE = 10.0;

  public: //everything that follows is public

  /* Constructors */

  // Default Constructor: creates circle radius 10, centered at (0,0) 
  Circle();
  
  // Parameterized Constructor: Parameters x, y, radius
  Circle(int x, int y, double radius);


  /* Getters */

  // Returns the circle's centre x coordinate
  int getX() const;

  // Returns the circle's centre y coordinate
  int getY() const;

  // Returns the circle's radius
  double getRadius() const;

  /* Setters */

  // Moves the circle by the given horiz and vert distances
  void move(int horiz, int vert);

  // Changes circle's radius to 10.0  if radius is invalid 
  void setRadius(double r);

  /* Methods - Specific to Problem Statement */

  // Computes and returns area of circle
  double computeArea() const;

  // Prints circle's data members
  void printCircle() const;

  // Check for intersection
  bool intersect(Circle c) const;

}; // Note the ";" - don't forget it!

// End of Circle.h
#endif