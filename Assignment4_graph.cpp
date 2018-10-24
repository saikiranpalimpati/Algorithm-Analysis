#include "graph.h"
#include"disjointSets.h"
#include<fstream>
#include<algorithm>
#include<set>

graph::graph()
{
}


//*******************************************************************
//                      ObjectName::addedge()   
//Parameters: three integers (the integers represent, edge strat, 
//             edge end , weight of an edge      
//                   Complexity: O(1)
//this method add an edge into a vector
//********************************************************************
void graph::addedge(int from, int to, int weight)
{
	v.push_back(edges(from, to, weight));

}



//*******************************************************************
//                      ObjectName::addEdges()   
//Parameters: two integers( the integers represent the edge
//            start and edge end
//                   Complexity: O(1)
//this method calculates the weight and passes the values to addedge method
//********************************************************************
void graph::addEdges(int from, int to)
{
	int weight = 0;
	if (from > to)
	{
		weight = abs(from - to);
		addedge(from, to, weight);
	}
}


//*******************************************************************
//                      ObjectName::sortEdges()   
//                   Complexity: O(1)
//this method sorts the vector conatining edges in order 
// of increasing weights
//********************************************************************
void graph::sortEdges()
{
	sort(v.begin(), v.end(), byweight());
}


//*******************************************************************
//                      ObjectName::printGraph()   
//                   Complexity: O(N),N is size of a graph
//this method prints the graph

//********************************************************************
void graph::printGraph()
{
	ofstream temp;
	temp.open("temout1.txt");
	int count = 0;
	cout << "vector size" << v.size() << endl;
	for (auto it = v.begin(); it != v.end(); ++it)
	{

		temp << "from" << (*it).from;
		temp << "   to" << (*it).to;
		temp << "   weight" << (*it).weight;
		temp << endl;
		count++;
	}
	temp << "the total number of edges is" << count;
}



//*******************************************************************
//                      ObjectName::kruskals()   
//Parameters: two integers (the integers represent he set elements to
//             whom the union operation is performed
//                   Complexity: O(NlogN), n is the number of edges
//this method performs the krsukals algorithm
//********************************************************************
void graph::kruskals()
{
	disjointSets dj(5242);


	//intialise a set with zeros in it

	set<int> mst = { 0 };

	//sort each edge
	sortEdges();
	int count = 0;
	//run till the last edge
	for (auto it = v.begin(); it != v.end(); ++it)
	{
		
		int parent_from = dj.findSet((*it).from);//find the element in the tree

		int parent_to = dj.findSet((*it).to);//find the element in the tree 

		if (parent_from != parent_to)
		{
			mst.insert((*it).from);
			mst.insert((*it).to);


			//perform the union between the edges
			dj.Union((*it).from, (*it).to);
		}
	}

	//print the size of each tree
	dj.printSize();
}

//destructor
graph::~graph()
{
}
