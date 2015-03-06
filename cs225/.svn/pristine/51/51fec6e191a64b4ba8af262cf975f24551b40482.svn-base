/**
 * kdtilemapper.h
 *
 * KDTree implementation of the abstract TileMapper class. Uses a
 * K-dimensional Tree, defined in kdtree.h,  to do nearest-neighbor
 * search on images in the mosaic canvas.
 *
 * Authors:
 * Matt Sachtler
 * Scott Wegner
 *
 * Developed for CS225 PhotoMosaic MP
 * Fall 2008
 */

#ifndef _KDTILEMAPPER_H
#define _KDTILEMAPPER_H

#include <iostream>

#include "tilemapper.h"

using namespace std;

class KDTileMapper : public TileMapper
{
	public:
    KDTileMapper(const SourceImage& theSource, const vector<TileImage>& theTiles): TileMapper(theSource, theTiles) { }
    
    
		virtual MosaicCanvas* map_tiles() const;

		// declare member functions and/or variables here
		
		private:
};

#endif /* _KDTILEMAPPER_H */

