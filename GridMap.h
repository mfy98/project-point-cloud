//Mehmet Furkan YİĞİT 26.12.2022

#ifndef GRIDMAP_GRIDMAP_H
#define GRIDMAP_GRIDMAP_H
#include <array>
#include <string>
#include "Map.h"
class GridMap:public Map
{
public:
	/**

@brief Constructor for the GridMap class.
@param gridSize The size of the grid in the map.
@param depth The depth of the map.
*/
	GridMap(float gridSize, int depth);
	/**

@brief Set the size of the grid in the map.
@param gridSize The new size of the grid in the map.
*/
	void setGridSize(float gridSize);
	/**

@brief Get the size of the grid in the map.
@return The size of the grid in the map.
*/
	float getGridSize() const;
	/**

@brief Set the depth of the map.
@param depth The new depth of the map.
*/
	void setDepth(int depth);
	/**

@brief Get the depth of the map.
@return The depth of the map.
*/
	int getDepth() const;


	/**

	@brief Insert a point cloud into the map.
	@param pc The point cloud to be inserted into the map.
	*/
	void insertPointCloud(PointCloud& pc);
	/**

@brief Insert a point into the map.
@param p The point to be inserted into the map.
*/
	void insertPoint(Point& p);

	/**

	@brief Get the value at a specific grid location in the map.
	@param x The x-coordinate of the grid location.
	@param y The y-coordinate of the grid location.
	@param z The z-coordinate of the grid location.
	@return The value at the specified grid location in the map.
	*/
	bool getGrid(int x, int y, int z) const;
	/**

@brief Load a map from a file.
@param fileName The name of the file containing the map data.
@return True if the map was successfully loaded from the file, false otherwise.
*/
	bool loadMap(const std::string& fileName);
	/**

@brief Save a map to a file.
@param fileName The name of the file to save the map data to.
@return True if the map was successfully saved to the file, false otherwise.
*/
	bool saveMap(const std::string& fileName);



private:
	std::array<std::array<std::array<bool, 100>, 100>, 100> map;
	float gridSize;
	int depth;
};

#endif 
