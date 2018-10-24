#pragma once
#include<iostream>
#include<vector>
using namespace std;
class disjointSets
{
public:
	//empty constructor
	disjointSets();

	//constructor and also the makeset function
	disjointSets(int n);

	//to create union of two sets
	void Union(int x, int y);

	//to find the parent of each set
	int findSet(int element);

	//function to print the parent array 
	void printParent();

	//function to print the size of node
	void printSize();

	~disjointSets();
private:
    //vector to hold the parent of each set
	vector<int> parent;

	//vector to hold the rank of each set
	vector<int> rank;

	//vector to hold the size of each tree associated with that node
	vector<int> size;

};
