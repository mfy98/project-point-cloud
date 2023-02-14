//Oğuzhan Baklacıoğlu 17.12.2022
#pragma once

#include"Point.h"
#include<iostream>
#include<cmath>
using namespace std;

/*Constructor*/

Point::Point() {
	x = 0;
	y = 0;
	z = 0;
}


/*
	Set x value
	@param double x
 */
void Point::setx(double x) {
	this->x = x;
}
/*
	Set y value
	@param double y
 */
void Point::sety(double y) {
	this->y = y;
}
/*
	Set z value
	@param double z
 */
void Point::setz(double z) {
	this->z = z;
}

/*
		get x value
		@return x value.
*/
double Point::getx() {
	return this->x;
}
/*
		get y value
		@return y value.
*/
double Point::gety() {
	return this->y;
}
/*
		get z value
		@return z value.
*/
double Point::getz() {
	return this->z;
}
/*Calculate distance
*@param Point& point value
*@return double distance value
*/
double const Point::distance(const Point& q) {
	return sqrt(pow((this->x - q.x), 2) + pow((this->y - q.y), 2) + pow((this->z - q.z), 2));
}

