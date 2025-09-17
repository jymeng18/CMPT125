/*
 * Filename: InRectangle.h
 *
 * Description: Header file for checking if points are in rectangle
 *
 * Author: Jerry Meng
 * Date: June 20, 2025
 */

#ifndef IN_RECTANGLE_H
#define IN_RECTANGLE_H

#define POINTS 2
#define CORNERS 4

// Desc: Given a point(x,y), and two corners(x1, y1, x2, y2), check if Point(x,y)
// is within the rectangles boundary
int InRectangle( float pt[POINTS], float rect[CORNERS] );

#endif
