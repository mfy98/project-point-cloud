#include "Map.h"

Map::Map() : xOrigin(0.0), yOrigin(0.0), resolution(0.0) {}

void Map::setXOrigin(double x) {
	xOrigin = x;
}

double Map::getXOrigin() const {
	return xOrigin;
}

void Map::setYOrigin(double y) {
	yOrigin = y;
}

double Map::getYOrigin() const {
	return yOrigin;
}

void Map::setResolution(double resolution) {
	this->resolution = resolution;
}

double Map::getResolution() const {
	return resolution;
}

void Map::insertPointCloud(PointCloud& pc) {
	
}

void Map::insertPoint(Point& p) {

}

bool Map::loadMap(const string& fileName) {


	return true;
}

bool Map::saveMap(const string& fileName) {
	

	return true;
}