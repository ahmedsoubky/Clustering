#include <iostream>
#include <vector>
#include <set>
#include <iterator>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <conio.h>
#include "Union_Find.h"

using namespace std;



typedef struct Edge
{
	int u;
	int v;
	int wt;
	
}Edge;

bool myCompare (const Edge &a,const Edge &b)
{
	return a.wt < b.wt;
}

long long cluster (vector< Edge > edges)
{
	int verticesNo = edges.size();

	sort(edges.begin(),edges.begin()+ (verticesNo),myCompare);
	
	UF* clusters =new UF(500);
	long long max =0;
	for(int j=0;j<verticesNo;++j) 
	{
		int u = edges[j].u;
		int v = edges[j].v;
		if(!clusters->connected(u,v) )
		{
			clusters->merge(u,v);		
		}
		else
		{
			if( edges[j].wt > max)
				max = edges[j].wt;
		}
		if((clusters->count()) == 4)
			break;
	}

	return max;
}



void PA1_main ()
{
	vector< Edge > edges;
	ifstream infile;
	string line;
	int i=0;
	infile.open("clustering1.txt",ios::in);
	if(!infile)
	{
		cout<<"File does not exist."<<endl;
		exit(1);
	}
	else
	{
		while( getline(infile,line) )
		{
			istringstream is(line);
			int u,v,wt;
			while(is>>u>>v>>wt)
			{
				Edge temp;
				temp.u = u;
				temp.v = v;
				temp.wt = wt;
				edges.push_back(temp);
			}
			++i;
		}
	}
	infile.close();
	
	long long max = cluster(edges);
	
	cout<<max<<endl;

	getch();

}

