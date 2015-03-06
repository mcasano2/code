/*
    Lab 12: Minimum Path
    Written by Sean Massung for CS 225 Spring 2011
*/

#include "minpath.h"

int minPath(Graph & g, string start, string end){


	int minval=9999;
	int test;
	vector<string> verts;
	verts=g.getVertices();
	int vsize=verts.size();
	for (int i = 0; i<  vsize; i++)
	{
		g.setVertexMark(verts[i],"UNEXPLORED" );
	}

	queue<string> q;
	queue<int> s;
	q.push(start);
	s.push(1);

	while (!q.empty())
	{
		if ( !(g.getVertexMark(q.front())=="VISITED") )
		{
		  test=s.front();
			vector<string> advert;
			advert=g.getAdjacent(q.front());
			vsize=advert.size();    
			for (int j = 0; j<  vsize; j++)
			{
				
				if (!(g.getEdgeMark(q.front(),advert[j])=="MINPATH"))
				{
					if ((advert[j]==end)&&(test<=minval))
					{
					minval=test;
					}
					q.push(advert[j]);
					s.push(test+1);

					g.setEdgeMark(q.front(),advert[j],"MINPATH");
					}	
				
			}
		}
		g.setVertexMark(q.front(), "VISITED");
		q.pop();
		s.pop();
	}


	vector<string> vertos=g.getVertices();
	vsize=vertos.size();
	for (int a = 0; a<  vsize; a++)
	{
		g.setVertexMark(vertos[a],"MINPATH" );
	}


	return minval;
}
