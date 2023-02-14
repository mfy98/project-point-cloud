//Alperen Dursun 22.12.2022
#pragma once
#include "PointCloud.h"
#include<Eigen/Dense>
#ifndef TRANSFORM_H
#define TRANSFORM_H


/*!
Transform class is for transforming points or points cloud on a axis by using <Eigen/Dense> library
 */
class Transform
{
private:

	Eigen::Vector3d angles;//!<rotation values in a 3d vector
	Eigen::Vector3d trans;//!<distance from origin to coordinate axis in a 3d vector
	Eigen::Matrix4d transMatrix;//!<transforming matrix in a 4d matrix
public:
	/**
	Default constructor for Transform class.
	*/
	Transform();
	
	/**
	Sets the rotation angles for the Transform object.
	@param ang An array containing the new rotation angles for the Transform.
	*/
	void setAngles(double ang[]);

	/**
	Sets the rotation angles for the Transform object.
	@param ang An Eigen Vector3d containing the new rotation angles for the Transform.
	*/
	void setRotation(Eigen::Vector3d ang);

	/**
	Sets the translation values for the Transform object.
	@param tr An array containing the new translation values for the Transform.
	*/
	void setTrans(double tr[]);

	/**
	Sets the translation values for the Transform object.
	@param tr An Eigen Vector3d containing the new translation values for the Transform.
	*/
	void setTranslation(Eigen::Vector3d tr);

	/**
	Retrieves the rotation angles of the Transform object.
	@return An Eigen Vector3d containing the rotation angles of the Transform.
	*/	
	Eigen::Vector3d getAngles();

	/**
	Retrieves the translation values of the Transform object.
	@return An Eigen Vector3d containing the translation values of the Transform.
	*/
	Eigen::Vector3d getTrans();
	
	/**
	Transforms a single Point object using the Transform's rotation and translation values.
	@param p The Point object to transform.
	@return The transformed Point object.
	*/
	Point doTransform(Point p);
	
	/**
	Transforms a PointCloud object using the Transform's rotation and translation values.
	@param pc The PointCloud object to transform.
	@return The transformed PointCloud object.
	*/
	PointCloud doTransform(PointCloud pc);
};
#endif 