#include <iostream>
#include "DepthCamera.h"
#include "Point.h"
#include "PointCloud.h"
#include "Transform.h"
#include "PointCloudRecorder.h"
#include "GridMap.h"


using namespace std;

int main()
{

	PointCloud pc1, pc2, pc3, pc4, result;

	DepthCamera cam("cam.txt"), cam2("cam2.txt"), cam3("cam3.txt"), cam1("cam1.txt");
	cam.setFileName("cam.txt");
	cam1.setFileName("cam1.txt");
	cam2.setFileName("cam2.txt");
	cam3.setFileName("cam3.txt");
	  

	Transform t1, t2;
	Eigen::Vector3d rt1(0, 0, -90);
	Eigen::Vector3d tr1(100, 500, 50);

	Eigen::Vector3d rt2(0, 0, 90);
	Eigen::Vector3d tr2(550, 150, 50);

	t1.setRotation(rt1);
	t1.setTranslation(tr1);

	t2.setRotation(rt2);
	t2.setTranslation(tr2);
	pc1 = cam.capture();
	pc2 = cam1.capture();
	pc3 = cam2.capture();
	pc4 = cam3.capture();
	result = pc1 + pc2 + pc3 + pc4;
	PointCloudRecorder r("result.txt");
	r.save(result);
	GridMap map(100, 100);
	map.getGrid(15, 55, 51);

	map.loadMap("cam.txt");

	return 0;
}