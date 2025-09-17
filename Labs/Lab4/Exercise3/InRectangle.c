/*
* Filename: InRectangle.c
*
* Desc: Checks if a point (x,y) lies within a rectangle
*
* Name: Jerry Meng
*
* Date: June 20, 2025
*/

#include <stdio.h>
#include <math.h>
#include "InRectangle.h"

int InRectangle( float pt[POINTS], float rect[CORNERS] ){

    float x_min, x_max, y_min, y_max;

    // Obtain the boundaries of rectangle; x_smallest, x_largest, y_smallest, y_largest ...
    x_min = fmin(rect[0], rect[2]);
    x_max = fmax(rect[0], rect[2]);
    y_min = fmin(rect[1], rect[3]);
    y_max = fmax(rect[1], rect[3]);

    // Check if our x and y coordinates is within bounds
    if((pt[0] >= x_min && pt[0] <= x_max) && (pt[1] >= y_min && pt[1] <= y_max)){
        return 1; // Return 1 if point lies in rectangle, 0 otherwise
    }
    else{
        return 0;
    }
}