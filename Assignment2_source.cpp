#include <iostream>
#include <vector>
#include<fstream>
#include "luint.h"
using namespace std;

/*
I have written the entire program as turned in and have not copied this code, 
or parts of this code from the internet or another student  signature:___________
*/
int main() {
	int a, b;
	ofstream outfile;
	outfile.open("output.txt");
	while (cin >> a >> b) {
		luint p(2);
		luint x(a);
		luint y(b);
		luint z = x + y;
		outfile << x << " + " << y << " = " << z << endl;
		luint d = x * y;
		outfile << x << "*" << y << "=" << d << endl;
		for (int i = 1; i < a; i++)
			p = p + p;

		outfile << "2^" << a << " is " << p << endl;
	}
	return 0;
}
