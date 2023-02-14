//Mehmet Furkan YİĞİT 26.12.2022

#include <fstream>
#include <iomanip>
#include "Point.h"
#include "PointCloud.h"
#include "GridMap.h"
/**

@brief Constructor for the GridMap class.
@param gridSize The size of the grid in the map.
@param depth The depth of the map.
*/
GridMap::GridMap(float gridSize, int depth)
	: gridSize(gridSize)
	, depth(depth)
{
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			for (int k = 0; k < 100; k++) {
				map[i][j][k] = 0;
			}
		}
	}
}
/**

@brief Set the size of the grid in the map.
@param gridSize The new size of the grid in the map.
*/
void GridMap::setGridSize(float gridSize)
{
	this->gridSize = gridSize;
}
/**

@brief Get the size of the grid in the map.
@return The size of the grid in the map.
*/
float GridMap::getGridSize() const
{
	return gridSize;
}
/**

@brief Set the depth of the map.
@param depth The new depth of the map.
*/
void GridMap::setDepth(int depth)
{
	this->depth = depth;
}
/**

@brief Get the depth of the map.
@return The depth of the map.
*/
int GridMap::getDepth() const
{
	return depth;
}
/**

@brief Insert a point cloud into the map.
@param pc The point cloud to be inserted into the map.
*/
void GridMap::insertPointCloud(PointCloud& pc)
{
	// point cloudda iterasyon islemi yapilir ve map e ekleme
	for (int i = 1; i <= pc.PointNumber (); i++) {
		Point p = pc.getPoint(i);
		insertPoint(p);
	}
}
/**

@brief Insert a point into the map.	
@param p The point to be inserted into the map.
*/
void GridMap::insertPoint(Point& p)
{
	// point koordinatlarini izgaraya donusturme
	int x = static_cast<int>(p.getx() / gridSize);
	int y = static_cast<int>(p.gety() / gridSize);
	int z = static_cast<int>(p.getz() / gridSize);

	// pointi haritaya ekle
	map[x][y][z] = true;
}
/**

@brief Get the value at a specific grid location in the map.
@param x The x-coordinate of the grid location.
@param y The y-coordinate of the grid location.
@param z The z-coordinate of the grid location.
@return The value at the specified grid location in the map.
*/
bool GridMap::getGrid(int x, int y, int z) const
{
	return map[x][y][z];
}

/**

@brief Load a map from a file.
@param fileName The name of the file containing the map data.
@return True if the map was successfully loaded from the file, false otherwise.
*/
bool GridMap::loadMap(const std::string& fileName)
{
	std::ifstream inputStream(fileName);
	if (inputStream.fail())
	{
		return false;
	}

	// dosyadan izgara boyutu ve derinligi okuma
	inputStream >> gridSize >> depth;

	// dosyadan map verilerini okuma
	for (int x = 0; x < 100; ++x)
	{
		for (int y = 0; y < 100; ++y)
		{
			for (int z = 0; z < 100; ++z)
			{
				inputStream >> map[x][y][z];
			}
		}
	}

	return true;
}
/**

@brief Save a map to a file.
@param fileName The name of the file to save the map data to.
@return True if the map was successfully saved to the file, false otherwise.
*/
bool GridMap::saveMap(const std::string& fileName)
{
	std::ofstream outputStream(fileName);
	if (outputStream.fail())
	{
		return false;
	}

	// izgara boyutunu ve derinligini dosyaya yazdirma
	outputStream << gridSize << ' ' << depth << '\n';
		
	// map verilerini dosyaya yazdirma
	for (int x = 0; x < 100; ++x)
	{
		for (int y = 0; y < 100; ++y)
		{
			for (int z = 0; z < 100; ++z)
			{
				outputStream << map[x][y][z] << ' ';
			}
			outputStream << '\n';
		}
		outputStream << '\n';
	}

	return true;
}