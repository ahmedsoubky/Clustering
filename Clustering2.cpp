#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <bitset>

#define NUMBER_OF_NODES 200000
#define NUMBER_OF_BITS 24

using namespace std;

typedef struct Node 
{
	int id;
	std::bitset< NUMBER_OF_BITS > bits;
}Node;

void main ()
{
	vector< Node > nodes(NUMBER_OF_NODES);
	ifstream infile;
	string line;
	int i=0;
	infile.open("clustering_big.txt",ios::in);
	if(!infile)
	{
		cout<<"File does not exist."<<endl;
		exit(1);
	}
	else
	{
		for(i=0;i<NUMBER_OF_NODES;++i)
		{
			nodes[i].id =i;
			for(int j=NUMBER_OF_BITS-1;j>=0;--j)
			{
				int tmp;
				infile>>tmp;
				nodes[i].bits[j] =tmp;
			}
		}
	}


	int fsize = nodes.size();

	for(i=0;i<fsize;++i)
	{
		for(int j=NUMBER_OF_BITS-1;j>=0;--j)
			cout<<nodes[i].bits[j]<<' ';
		cout<<endl;

	}

	nodes[2].bits =nodes[0].bits & nodes[1].bits;



}
