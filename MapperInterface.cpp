#include "MapperInterface.h"

#include <vector>



MapperInterface::MapperInterface()   {
	recorder = new PointCloudRecorder("result.txt"); }

void MapperInterface::addGenerator(PointCloudGenerator* gen) {
	this->generators.push_back(gen);
}

void MapperInterface::setRecorder(PointCloudRecorder* recorder) {
	recorder = recorder;
}

bool MapperInterface::generate() {
	// Iterate through all generators and generate a point cloud
	for (int i = 0; i < generators.size(); i++)
	{
		patch = generators[i]->captureFor();
		for (int j = 0; j < patch.PointNumber(); j++)
		{
			pointCloud.setPoints(patch.getPoint(j));
		}
	}

	return true;
}
void MapperInterface::setMap(Map* map) {
	map = map;
}

bool MapperInterface::recordPointCloud() {
	if (recorder == nullptr) {
		return false;
	}

	return recorder->save(pointCloud);
}

bool MapperInterface::recordMap() {
	if (recorder == nullptr || map == nullptr) {
		return false;
	}
	return map->saveMap("result.txt");
	return true;
}

bool MapperInterface::insertMap() {
	if (map == nullptr) {
		return false;
	}

	{
		for (int x = 0; x < 100; ++x)
		{
			for (int y = 0; y < 100; ++y)
			{
				for (int z = 0; z < 100; ++z)
				{
					map->insertPointCloud(pointCloud);
				}
				map->insertPointCloud(pointCloud);
			}
			map->insertPointCloud(pointCloud);;
		}
	}
		return true;
}