//Süleyman GÜLER 25.12.2022

#include <iostream>
#include <string>
#include <fstream>
#include "Point.h"
#include "PointCloud.h"
#include "DepthCamera.h"
#include "Transform.h"

using namespace std;
/**

Constructor for DepthCamera class.
@param fileName Name of the file to be used by the DepthCamera object.
*/
DepthCamera::DepthCamera(std::string fileName) {
	this->fileName = fileName;
}
/**

@brief Set the file name of the DepthCamera object
@param fileName The new file name to be used by the DepthCamera object.
*/
void DepthCamera::setFileName(std::string fileName) { this->fileName = fileName; }
/**

@brief Get the file name of the DepthCamera object
@return The file name of the DepthCamera object.
*/
std::string DepthCamera::getFileName() { return this->fileName; }

/**

@brief Captures the point cloud data from the file specified in the DepthCamera object.
@return PointCloud object with the captured point cloud data.
*/
PointCloud DepthCamera::capture() {

	//Creating some variabe to get information about file
	string temp = "";
	int dataSize = 0;

	ifstream pts(fileName, ios::in);
	//To skip first line that has no value
	getline(pts, temp);

	//Since the second line of the file keeps the size of the file,
	//this code assigns the second line of the file to the dataSize variable
	pts >> dataSize;
	PointCloud pC(dataSize);

	//Reads the remaining data in the file
	for (int i = 0; i < dataSize; i++) {
		//pC.setPoint(getData(pts));
		//Creating variables
		Point pt;
		double valX, valY, valZ;
		double rgb;
		string temp;

		//Reads and stores x, y, z values
		pts >> valX;
		pts >> valY;
		pts >> valZ;

		//To pass rgb (colour) part
		pts >> rgb;
		pts >> rgb;
		pts >> rgb;

		//Creates a point with the x,y,z values read from the file
		pt.setx(valX);
		pt.sety(valY);
		pt.setz(valZ);
		pC.setPoints(pt);
	}
	pts.close();

	return pC;
}

/**
@brief Captures the point cloud data from the file specified in the DepthCamera object and applies a transformation to it.
@return PointCloud object with the transformed captured point cloud data.
*/
PointCloud DepthCamera::captureFor()
{
	//Creating some variabe to get information about file
	string temp = "";
	int dataSize = 0;
	Transform tr;

	ifstream pts(fileName, ios::in);
	//To skip first line that has no value
	getline(pts, temp);

	//Since the second line of the file keeps the size of the file,
	//this code assigns the second line of the file to the dataSize variable
	pts >> dataSize;
	PointCloud pC(dataSize);

	//Reads the remaining data in the file
	for (int i = 0; i < dataSize; i++) {
		//pC.setPoint(getData(pts));
		//Creating variables
		Point pt;
		double valX, valY, valZ;
		double rgb;
		string temp;

		//Reads and stores x, y, z values
		pts >> valX;
		pts >> valY;
		pts >> valZ;

		//To pass rgb (colour) part
		pts >> rgb;
		pts >> rgb;
		pts >> rgb;

		//Creates a point with the x,y,z values read from the file
		pt.setx(valX);
		pt.sety(valY);
		pt.setz(valZ);
		pC.setPoints(pt);
	}
	pts.close();
	pC = tr.doTransform(pC);

	return pC;
}
