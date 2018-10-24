//**************************************************************
//           Project #2 Multiple Precision Arithematic 
//                    Name: SAIKIRAN PALIMPATI
//                   Algorithm Analysis Date: 02/26/2018
//***************************************************************
/*
output file: output.txt
To store very long unsigned integers in an vector or list and then
carry out addition operation by using operator overloading and then 
calculating 2^(some constant) as it directly calls the addition 
operator  overloading function
then try multiplication operator overloading
*/
//*****************************************************************

#pragma once
#include <vector>
#include <list>
#include <string>
#include <iomanip>
using namespace std;

class luint
{
	// When you get this working change vector to list
	// and see if it still works
	vector<unsigned int> num;
	// here num[0] is the least significant digit
	// You should be able to change dpn to be any value from 1 thru 9
	unsigned int dpn = 4;// node size Number of digits/node
public:
	luint();
	~luint();
	// This is a parameterized constructor
	luint(unsigned int v);
	// The following overloaded + adds two luint's
	friend luint operator+(const luint&, const luint&);
	// This is the overloaded * operator(extra credit)
	// extra credit will be given only if everything else works.
	friend luint operator*(const luint&, const luint&);
	// This is the overloaded << output operator
	friend ostream & operator<<(ostream & os, const luint & n) {
		// must print it backwards using reverse iterators

		vector<unsigned int>::const_reverse_iterator rit = n.num.rbegin();
		for (; rit != n.num.rend(); ++rit)
		{

			os << *rit;
		}
		return os;

	}
};
