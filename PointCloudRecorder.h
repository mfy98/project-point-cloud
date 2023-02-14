//Mevlüt Talha DOĞANAY 04.01.2023

#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "DepthCamera.h"
#include "Map.h"


class PointCloudRecorder : public Point {		//save  operations to txt file.
private:
	string fileName;	// an argument to set result file name.
public:
	/**
	Constructor for PointCloudRecorder class.
	@param _filename The file name to use for saving the PointCloud.
	*/
	PointCloudRecorder(string _filename) : fileName(_filename) {}

	/**
	Saves a PointCloud object to a file.
	@param pntcloud The PointCloud object to save.
	@return True if the PointCloud was successfully saved, false otherwise.
	*/
	bool save( PointCloud pntcloud);
};