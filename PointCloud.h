//Oğuzhan Baklacıoğlu 17.12.2022
#pragma once

#include <iostream>
#include "Point.h"
#include <list>
using namespace std;

class PointCloud : public Point
{
private:
	list<Point> points; // list
	int pointNumber; // size of list
	friend class PointCloudRecorder;
public:

	/**
	Constructor for PointCloud class.
	@param PointNumber The number of points in the PointCloud.
	*/
	PointCloud(int PointNumber);

	/**	
	Copy constructor for PointCloud class.
	@param other The PointCloud object to copy.
	*/
	PointCloud(const PointCloud& other);//Copy Constructor

	/**
	Default constructor for PointCloud class.
	*/
	PointCloud();//default constructor

	/**
	Sets the number of points in the PointCloud.
	@param PointNumber The new number of points in the PointCloud.
	*/
	void setPointNumber(int PointNumber);

	/**
	Adds a Point object to the PointCloud.
	@param point The Point object to add to the PointCloud.
	*/
	void  setPoints(const Point& point);

	/**
	Retrieves the list of Point objects in the PointCloud.
	@return The list of Point objects in the PointCloud.
	*/
	list<Point> getPoints();

	/**
	Retrieves a Point object from the PointCloud by its point number.
	@param PointNumber The point number of the Point object to retrieve.
	@return The Point object with the specified point number.
	*/
	Point getPoint(int PointNumber);

	/**
	Retrieves the number of points in the PointCloud.
	@return The number of points in the PointCloud as an integer.
	*/
	int PointNumber();
	
	/**
	Overloaded assignment operator to copy one PointCloud object to another.
	@param other The PointCloud object to copy.
	@return A reference to the PointCloud object being assigned to.
	*/
	PointCloud& operator=(const PointCloud& other);

	/**
	Overloaded addition operator to merge two PointCloud objects into a new one.
	@param other The PointCloud object to merge with.
	@return A new PointCloud object that is the combination of the two PointCloud objects.
	*/
	PointCloud operator+(const PointCloud& other) const ;
};