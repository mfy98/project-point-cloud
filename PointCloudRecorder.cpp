//Mevlüt Talha DOĞANAY 04.01.2023

#include "Point.h"
#include "PointCloud.h"
#include "PointCloudRecorder.h"
using namespace std;
/**
Saves a PointCloud object to a file.
@param pntcloud The PointCloud object to save.
@return True if the PointCloud was successfully saved, false otherwise.
*/
bool PointCloudRecorder::save(PointCloud pntcloud)
{
	ofstream outfile(fileName);
	if (!outfile.is_open()) {
		cout << "File Couldn't Open!\n";
	}

	else {
		int i=0;

		list<Point> p = pntcloud.getPoints();

		for (list<Point>::iterator it = p.begin(); it != p.end(); ++it) {
			outfile << it->x << " " << it->y << " " << it->z << endl;
		}


		return i >= pntcloud.PointNumber();
	}
}
