//Oğuzhan Baklacıoğlu 17.12.2022
#include<iostream>
#include "PointCloud.h"

//constructor
PointCloud::PointCloud(int PointNumber)
{
    pointNumber = PointNumber;
}
//copyconstructor
PointCloud::PointCloud(const PointCloud& other)
{
    pointNumber = other.pointNumber;
    points = other.points;

}
//DefaultConstructor
PointCloud::PointCloud() {

}
//setpointnumber
void PointCloud::setPointNumber(int PointNumber)
{
    pointNumber = PointNumber;
}
//setpoints
void PointCloud::setPoints(const Point& point)
{

    this->points.push_back(point);
    this->setPointNumber(points.size());
 
}
//return point
Point PointCloud::getPoint(int PointNumber) //düzenlenecek
{
    
    PointNumber = pointNumber;
    list<Point>::iterator it = this->points.begin();
    for (int i = 0; i < PointNumber; i++) {
        ++it;
    }
    return *it;

}
//return list
list<Point> PointCloud::getPoints()
{
     return points;
}
//getpointnumber
int PointCloud::PointNumber()
{
    return pointNumber;
}
// = operator
PointCloud& PointCloud::operator=(const PointCloud& other)
{
    if (this != &other)
    {
        pointNumber = other.pointNumber;
        points = other.points;
    }
    return *this;
}
//+operator
PointCloud PointCloud::operator+(const PointCloud& other) const {
    PointCloud result(points.size() + other.points.size());
    result.points.insert(result.points.end(), points.begin(), points.end());
    result.points.insert(result.points.end(), other.points.begin(), other.points.end());
    return result;
}