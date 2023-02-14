#pragma once
#include <Eigen/Dense>
#include "PointCloud.h"
#include"Point.h"
#include "PointCloudRecorder.h"

class Map {
public:
	// constructor
	Map();

	// set/get functions
	void setXOrigin(double x);
	double getXOrigin() const;
	void setYOrigin(double y);
	double getYOrigin() const;
	void setResolution(double resolution);
	double getResolution() const;

	// pure virtual functions
	virtual void insertPointCloud(PointCloud& pc) = 0;
	virtual void insertPoint(Point& p) = 0;
	virtual bool loadMap(const string& fileName) = 0;
	virtual bool saveMap(const string& fileName) = 0;

private:
	// member variables
	Eigen::MatrixXd map;
	double xOrigin;
	double yOrigin;
	double resolution;
};
