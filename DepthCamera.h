//Süleyman GÜLER 25.12.2022

#pragma once
#include "PointCloud.h"
#include "Transform.h"
#include "PointCloudGenerator.h"

#ifndef _DEPTHCAMERA_H
#define _DEPTHCAMERA_H
class DepthCamera:public PointCloudGenerator {
private:
	std::string fileName;
public:
	/**

Constructor for DepthCamera class.
@param fileName Name of the file to be used by the DepthCamera object.
*/
	DepthCamera(std::string fileName);
	/**

@brief Set the file name of the DepthCamera object
@param fileName The new file name to be used by the DepthCamera object.
*/
	void setFileName(std::string fileName = "");
	/**

@brief Get the file name of the DepthCamera object
@return The file name of the DepthCamera object.
*/
	std::string getFileName();
	/**

@brief Captures the point cloud data from the file specified in the DepthCamera object.
@return PointCloud object with the captured point cloud data.
*/
	PointCloud capture();

	/**
	@brief Captures the point cloud data from the file specified in the DepthCamera object and applies a transformation to it.
	@return PointCloud object with the transformed captured point cloud data.
	*/
	PointCloud captureFor();

};
#endif




