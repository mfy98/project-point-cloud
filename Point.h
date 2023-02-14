//Oğuzhan Baklacıoğlu 17.12.2022
#pragma once

#include <iostream>
using namespace std;


class Point {

private:
	friend class PointCloudRecorder;
	double x, y, z;

public:
	/*Constructor*/
	Point(); 
	
/*
	Set x value
	@param double x
 */
	void setx(double x);
/*
	Set y value
	@param double y
 */
	void sety(double y);
/*
	Set z value
	@param double z
 */
	void setz(double z);


/*
		get x value
		@return x value.
*/
	double getx();
/*
		get y value
		@return y value.
*/
	double gety();
/*
		get z value		
		@return z value.
*/
	double getz();

	/*Calculate distance 
	*@param Point& point value
	*@return double distance value
	*/
	double const distance(const Point&);

	/**
Overloaded equality operator to compare two Point objects.
@param other The Point object to compare to.
@return True if the two points are equal (have the same x, y, and z values), false otherwise.
*/
	virtual bool operator==(const Point& other) const
	{
		if (this->x == other.x && this->y == other.y && this->z == other.z)
			return true;

		else
			return false;
	}
};
