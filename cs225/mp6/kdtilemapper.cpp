
#include "kdtilemapper.h"
#include "kdtree.h"
#include <iostream>


using namespace std;

// define KDTileMapper member functions here

MosaicCanvas* KDTileMapper::map_tiles() const
{
	int row=source.get_rows();
	int col=source.get_columns();
	MosaicCanvas* canvas=new MosaicCanvas(row,col);
	if (row==0)
	{
	  canvas=NULL;
		return canvas;
	}
	int size= static_cast<int>(points.size());
	vector<Point<3> > myPoints;
	int a=0;
	TileImage tempA;
	bool tempB;
	for (int i=0; i<size; i++)
	{
	  tempA=tile_avg_map.find(points[i])->second;
	  tempB=tile_avg_map.find(points[i])->second.is_valid();
	  if (tempA.get_height()<1) {
	  tempB=false;
	  }
	  if (tempA.get_width()<1) {
	  tempB=false;
	  }
	  if (tempB) {	 
	  
			if ( !(points[i].enable_mines) )
			{
				myPoints.push_back(points[i]);
			}
	 }
	}
	if (myPoints.empty())
	{
	  canvas=NULL;
		return canvas;
	}


	Point<3> colorPoint;
	Point<3> tilePoint;
	Color temp;
	KDTree<3> tree(myPoints);
	for (int x=0; x<col; x++)
	{
		for (int y=0; y<row; y++)
		{
			temp=source.get_region_color(row,col);
			colorPoint.set(0, temp.rValue);
			colorPoint.set(1, temp.gValue);
			colorPoint.set(2, temp.bValue);
			tilePoint=tree.findNearestNeighbor(colorPoint); 
			int test=canvas->set_tile(row,col,tile_avg_map.find(tilePoint)->second);
			if ( !(test==0) )
			{
	  canvas=NULL;
		return canvas;
		}
	}
}
return canvas;
}

