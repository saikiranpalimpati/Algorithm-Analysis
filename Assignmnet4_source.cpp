//**************************************************************
//                   Project #4 Minimum Spannin Tree
//                    Name: SAIKIRAN PALIMPATI
//                    Algorithm Analysis Date: 05/02/2018
//***************************************************************
//      In this proghram a data set is taken and is used to
//      implement a graph and then find a minimum spanning tree 
//      in the graph
//      The number of nodes is printed out for each tree in the 
//      mimimum spanning tree
//      "rawinput.txt" is the collection of data taken from website
//      "input.txt"has the edges for which we are making a graph 
// "size.txt" has the size of each tree in the minimum spannig tree

//*****************************************************************
//I have written the entire program as turned in and have not copied 
//this code, or parts of this code from the internet or another student.   
//Signature____________________
//****************************************************************

#include<iostream>
#include<fstream>
#include<vector>
#include<set>
#include<algorithm>
#include"graph.h"
#include"disjointSets.h"

using namespace std;

//*******************************************************************
//                      ObjectName::readInput()                
//                    complexity:O(ElogE)
// This method reads the input from newly created input file("input.txt")
// where the data set is of range 0 to 5242
// After we read the data the data is sent to addedges method in the
// graph class 
// Then kruskal algorithm is called and minimum spanning trees are obtained

//********************************************************************
void readInput();



int main()
{
	

	//file variable for taking the input dat afrom text file
	ifstream rawinput;

	//rawinput  file contains the data set which has out of bound values
	rawinput.open("rawinput.txt");

	//ofstream object to create and operate input.txt
	ofstream output;

	output.open("input.txt");

	//a set is created and all the values are stored in it so that it avoid duplicates while storing the data
	set<int> set;

	//In this vector the data after eliminating duplicates is copied
	vector<int> v;

	//input variable to hold the data
	int number = 0;

	//read till end of file
	while (!rawinput.eof())
	{
	rawinput >> number;
	//insert each element into a set
	set.insert(number);
	}

	//copy every element in a set into a vector
	for (auto it = set.begin(); it != set.end(); ++it)
	{
	v.push_back(*it);

	}

	//close the rawinput file
	rawinput.close();

	//open the rawinput again
	rawinput.open("rawinput.txt");

	//input variable to hold the data in the file
	int raw = 0;

	//read till the end of file
	while (!rawinput.eof())
	{
	rawinput >> raw;
	//data conversion

	vector<int>::iterator lower;
	//finding the element in the vector by using binary search tree

	lower = lower_bound(v.begin(), v.end(), raw);

	//print the converted value of each input data on to a new input file("input.txt")

	output << (lower - v.begin()) << endl;

	}
	output.close();
	
	//call the other function to read the new input file
	readInput();

	system("pause");

}
//readInput() function definition
void readInput()
{
	//object to graph class
	graph g;

	//input dta variable
	ifstream input;

	//open the new input file
	input.open("input.txt");

	//read till the end of file
	while (!input.eof())
	{

		int from = 0;
		int to = 0;
		input >> from;
		input >> to;

		//call the add edges medthod in the graph class to store all the edges
		g.addEdges(from, to);
	}

	//call the kruskal methos to find the minimum spanning tree
	g.kruskals();

}
