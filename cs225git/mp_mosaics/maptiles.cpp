/**
 * @file maptiles.cpp
 * Code for the maptiles function.
 */

#include <iostream>
#include <map>
#include "maptiles.h"
#include <map>
//#include "cs225/RGB_HSL.h"

using namespace std;


Point<3> convertToXYZ(LUVAPixel pixel) {
    return Point<3>( pixel.l, pixel.u, pixel.v );
}

MosaicCanvas* mapTiles(SourceImage const& theSource,
                       vector<TileImage>& theTiles)
{
    /**
     * @todo Implement this function!
     */
     /*
     It creates a new dynamically allocated MosaicCanvas,
     with the same number of rows and columns as the SourceImage,
     and returns a pointer to this object.
     */
    MosaicCanvas *mosaic = new MosaicCanvas(theSource.getRows(),theSource.getColumns());

     map<Point<3>, TileImage*> map;

     vector<Point<3>> newPoints;
     for(int i = 0; i < int(theTiles.size()); i++) {
       LUVAPixel pixel = theTiles[i].getAverageColor();
       Point<3> point = convertToXYZ(pixel);
       map[point] = &theTiles[i];
       newPoints.push_back(point);
     }
     KDTree<3> kdtree =  KDTree<3>(newPoints);

    for (int i = 0; i < int(theSource.getRows()); i++){
      for (int j = 0; j < int(theSource.getColumns()); j++){
        LUVAPixel old_color = theSource.getRegionColor(i,j);
        Point<3> target = convertToXYZ(old_color);
        Point<3> result = kdtree.findNearestNeighbor(target);
        TileImage* tiles = map[result];
        mosaic->setTile(i, j, tiles);
      }
    }
    return mosaic;
}
