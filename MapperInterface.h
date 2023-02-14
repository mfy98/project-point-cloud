#pragma once
#include <Eigen/Dense>
#include <vector>
#include "Map.h"
#include "PointCloud.h"
#include "PointCloudRecorder.h"

// PointCloud, PointCloudGenerator, and PointCloudRecorder classes should be defined elsewhere

class MapperInterface {
public:
	// constructor
	MapperInterface();
	// functions
	void addGenerator(PointCloudGenerator* generator);
	void setRecorder(PointCloudRecorder* recorder);
	bool generate();
	bool recordPointCloud();
	bool recordMap();
	bool insertMap();
	void setMap(Map* map);

private:
	// member variables
	PointCloud pointCloud;
	PointCloud patch;
	std::vector<PointCloudGenerator*> generators;
	PointCloudRecorder* recorder;
	Map* map;
};