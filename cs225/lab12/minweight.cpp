/*
   Lab 12: Minimum Weight
   Written by Sean Massung for CS 225 Spring 2011
 */

#include "minweight.h"

int minWeight(Graph & g)
{
	int minval=999999999;
	int test;
	string name1;
	string name2;
	vector<string> verts;
	verts=g.getVertices();
	int vsize=verts.size();
	for (int i = 0; i<  vsize; i++)
	{
		g.setVertexMark(verts[i],"UNEXPLORED" );
	}

	queue<string> q;
	q.push(verts[0]);

	while (!q.empty())
	{
		if ( !(g.getVertexMark(q.front())=="VISITED") )
		{
			vector<string> advert;
			advert=g.getAdjacent(q.front());
			vsize=advert.size();    
			for (int j = 0; j<  vsize; j++)
			{
				if (!(g.getEdgeMark(q.front(),advert[j])=="VISITED"))
				{
					test=g.getEdgeWeight(q.front(),advert[j]);
					q.push(advert[j]);
					if (test<=minval)
					{
						minval=test;
						name1=q.front();
						name2=advert[j];
					}

					
						g.setEdgeMark(q.front(),advert[j],"VISITED");
					
				}	
			}
		}
		g.setVertexMark(q.front(), "VISITED");
		q.pop();
	}

 	g.setEdgeMark(name1,name2,"MIN");
	return minval;
}
