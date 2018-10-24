#include "luint.h"
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
luint::luint()
{
}

luint::~luint()
{
}

//*******************************************************************
//                      Method:parameterized constructor
//                    Parameters: unsigned int
// Taking an unsigned int and storing them in a vector
//********************************************************************
luint::luint(unsigned int v)
{
	unsigned int nsz = pow(10, dpn) + .5;
	while (v != 0)
	{
		num.push_back(v % nsz);
		v = v / nsz;
	}

}

//*******************************************************************
//                      Method:operator+
//                    Parameters: two objects 
//Taking two objects and then adding them
//********************************************************************
luint operator+(const luint & obj1, const luint & obj2)
{
	luint tempobject;
	int carry = 0;
	vector<unsigned int>::const_iterator pointer1 = obj1.num.begin();
	vector<unsigned int>::const_iterator pointer2 = obj2.num.begin();
	int minimumsize = min(obj1.num.size(), obj2.num.size());
	int nsz = pow(10, tempobject.dpn) + .5;
	int i = 0;

	while (i < minimumsize)
	{
		tempobject.num.push_back((carry + *pointer1 + *pointer2) % nsz);
		carry = (carry + *pointer1 + *pointer2) / nsz;
		pointer1++;
		pointer2++;
		i++;

	}

	// object1 has more values than object2
	while (pointer1 != obj1.num.end()) {
		// a has some values left maybe
		tempobject.num.push_back((*pointer1 + carry) % nsz);
		carry = (carry + *pointer1) / nsz;
		pointer1++;
	}
	// object2 has more values than object1
	while (pointer2 != obj2.num.end()) {
		tempobject.num.push_back((*pointer2 + carry) % nsz);
		carry = (carry + *pointer2) / nsz;
		pointer2++;
	}
	//rest digits as carry to be pushed
	if (carry != 0)
	{
		tempobject.num.push_back(carry);
	}
	return tempobject;
}

//*******************************************************************
//                      Method:operator*
//                    Parameters: two objects 
//Taking two objects and then multiplying them
//********************************************************************
luint operator*(const luint & obj1, const luint & obj2) {
	luint ans;
	int carry = 0;

	//list<unsigned int>::const_iterator tptr
	int nsz = pow(10, ans.dpn) + .5;
	

	for (vector<unsigned int>::const_reverse_iterator it1 = obj1.num.rbegin(); it1 != obj1.num.rend(); it1++)
	{
		for (vector<unsigned int>::const_reverse_iterator it2 = obj2.num.rbegin(); it2 != obj2.num.rend(); it2++)
		{
			ans.num.push_back((carry + (*it1 * *it2)) % nsz);
			carry = (carry + (*it1 * *it2)) / nsz;
		}
	}
	if (carry != 0)
	{
		ans.num.push_back(carry);
	}
	return ans;
}
