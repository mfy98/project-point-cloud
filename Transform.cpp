//Alperen Dursun 22.12.2022
#include "Transform.h"
#define _USE_MATH_DEFINES
#include <math.h>
#define M_PI 3.14159265358979323846
using namespace std;

Transform::Transform() {
	angles = {};
	trans = {};
	transMatrix = {};
}

void Transform::setAngles(double ang[])
{
	if (ang == NULL) {
		return;
	}
	for (int i = 0; i < 3; i++) {
		angles[i] = ang[i];
	}
}


void Transform::setRotation(Eigen::Vector3d ang) {
	angles = ang;

}


void Transform::setTrans(double tr[])
{
	if (tr == NULL) {
		return;
	}
	for (int i = 0; i < 3; i++) {
		trans[i] = tr[i];
	}
}

void Transform::setTranslation(Eigen::Vector3d tr) {
	trans = tr;

}


Eigen::Vector3d Transform::getAngles()
{
	return angles;
}

Eigen::Vector3d Transform::getTrans()
{
	return trans;
}


Point Transform::doTransform(Point p) {
	Eigen::Vector4d  aP(0, 0, 0, 0);
	Eigen::Vector4d  bP;
	bP[0] = p.getx();
	bP[1] = p.gety();
	bP[2] = p.getz();
	bP[3] = 1;


	double pitch = M_PI * (angles[0] / 180);
	double yaw = M_PI * (angles[1] / 180);
	double roll = M_PI * (angles[2] / 180);

	Eigen::AngleAxisd rollAngle(roll, Eigen::Vector3d::UnitZ());
	Eigen::AngleAxisd yawAngle(yaw, Eigen::Vector3d::UnitY());
	Eigen::AngleAxisd pitchAngle(pitch, Eigen::Vector3d::UnitX());

	Eigen::Quaternion<double> q = pitchAngle * yawAngle * rollAngle;

	Eigen::Matrix3d rotationMatrix = q.matrix();

	transMatrix.setIdentity();
	transMatrix.block<3, 3>(0, 0) = rotationMatrix;
	transMatrix.block<3, 1>(0, 3) = trans;


	aP = transMatrix * bP;

	Point newP;
	newP.setx(aP(0));
	newP.sety(aP(1));
	newP.setz(aP(2));


	return newP;
}


PointCloud Transform::doTransform(PointCloud pc) {

	int max = pc.PointNumber();
	Point p;
	PointCloud newpc(1);

	for (int i = 0; i < max; i++) {
		p = pc.getPoint(i);
		newpc.setPoints(doTransform(p));
	}

	return newpc;
}