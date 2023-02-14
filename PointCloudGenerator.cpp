//Alperen Dursun 04.01.2023

#include "PointCloudGenerator.h"

using namespace std;
/**

@brief Default constructor for the PointCloudGenerator class.
*/
PointCloudGenerator::PointCloudGenerator() {
	
}
/**

@brief Constructor for the PointCloudGenerator class that takes a file name as an argument.
@param F The file name to be used by the point cloud generator.
*/
PointCloudGenerator::PointCloudGenerator(string F) {
	string fileName = F;
}

/**

	@brief Set the transform to be applied to the generated point cloud.
	@param tr A Transform object to be applied to the generated point cloud.
	@return void
	*/
void PointCloudGenerator::setTransform(Transform tr) {
	transform = tr;
}
/**

@brief Get the transform applied to the generated point cloud.
@return A Transform object representing the transform applied to the generated point cloud.
*/
Transform PointCloudGenerator::getTransform() {
	return transform;
}