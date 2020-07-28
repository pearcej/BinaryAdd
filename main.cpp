/*-------------------------------------------------------------------------------
# Purpose: TODO:
#
# Original Authors:           Mario Nakazawa & Jan Pearce
# Original Creation date:     21/09/2014
# Increment implementation by: FIXME
#------------------------------------------------------------------------------*/

#include "binaryNumber.cpp"
#include <iostream> // has cout and cin defined therein
using namespace std;

int main() {

	char slowexit;

	BinaryNumber testing = BinaryNumber();
	cout << "instantiation of testing list.\n" << endl;

	int mynumber = 17;

	testing.convert_decimal_to_binary(mynumber);
	cout << " My number is " << mynumber << " which is:" << endl;
	cout << testing.to_string() << endl;

	testing.increment();
	cout <<"After incrementing we have "<< mynumber+1 << " which is: (needs to be implemented):" << endl;
	cout << testing.to_string() << endl;

	testing.remove_all();
	cout << testing.to_string() << endl;

	cin >> slowexit; //to keep window open in some cases

	return 0;
}
