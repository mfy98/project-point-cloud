//Alperen Dursun 04.01.2023

#pragma once
#include "Transform.h"
class PointCloudGenerator {
private:
	Transform transform;
public:
	/**

	@brief Default constructor for the PointCloudGenerator class.
	*/

	PointCloudGenerator();
	/**

@brief Constructor for the PointCloudGenerator class that takes a file name as an argument.
@param F The file name to be used by the point cloud generator.
*/
	PointCloudGenerator(string F);

	virtual PointCloud capture()=0;

	virtual PointCloud captureFor() = 0;
	/**

	@brief Set the transform to be applied to the generated point cloud.
	@param tr A Transform object to be applied to the generated point cloud.
	@return void
	*/
	void setTransform(Transform);
	/**

@brief Get the transform applied to the generated point cloud.
@return A Transform object representing the transform applied to the generated point cloud.
*/
	Transform getTransform();
};
