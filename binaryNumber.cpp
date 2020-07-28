/*-------------------------------------------------------------------------------
# Purpose:  A linked list implementation of a binary number.
#
# Original Authors: Assignment concept by Jan Pearce, 
#		    converted to Python and back to C++ by Mario Nakazawa
#			C++ improvements by Jan Pearce
#
#
# Originally Created:     21/09/2014
#------------------------------------------------------------------------------*/

#include "bit.cpp"
#include <string>
using namespace std;
class BinaryNumber {

private:
	Bit* leastSignificantBit;   // in C++, we need to declare these variables
	int numBits;
	//------------------------------------------------------------

public:
	BinaryNumber() {
		// Initialize this binary number is empty  with no bits in it.'''
		leastSignificantBit = NULL;
		numBits = 0;
	}

	int __len__() {
		//post: returns number of items in the list
		return numBits;
	}

	Bit* get_least_significant_bit() {
		return leastSignificantBit;
	}

	void convert_decimal_to_binary(int decimal) {
		//pre: The decimal input >= 0, leastSignificantBit = None
		//    If there IS a number in this object already, it will be clobbered.
		//post: leastSignificantBit will point to the first link
		//of a linked list representing the "decimal" number in reverse
		//order (least to most significant bit)

		if (decimal < 0)
			return;

		// Now use an algorithm to convert a decimal number to binary.
		// Repeatedly divide the number by 2 and keep the remainder.
		// It will build the binary number this way.

		// Start the process with the first binary number.
		if (decimal % 2 == 1) {
			leastSignificantBit = new Bit(true);
		}
		else {
			leastSignificantBit = new Bit(false);
		}
		numBits += 1;

		// Now loop through the decimal and convert to binary.
		Bit* bitRef = leastSignificantBit;
		int remainder = 0;
		int quotient = decimal / 2;

		while (quotient > 0) {
			remainder = quotient % 2;
			quotient = quotient / 2;

			bitRef->add_next_bit(remainder == 1);
			bitRef = bitRef->get_next_bit();	// Advance the reference
			numBits += 1;
		}
	}

	string to_string() {
		// returns the string representation of this binary number.
		//post: The string representation of this BinaryNumber will be returned.
		//    if there is no linked list, a blank string, "" is returned
		Bit* bitRef = leastSignificantBit;
		string output = "";

		if (bitRef == NULL) {
			return output;
		}

		for (int i = 0; i < numBits; i++) {
			output = bitRef->to_string() + output;
			bitRef = bitRef->get_next_bit();
		}
		return output;
	}

	void remove_all() {
		//pre: none
		//post: All the links in the linked list started by leastSignificantBit
		//	will be de-allocated.'''

		if (leastSignificantBit == NULL) {
			return;
		}

		Bit* trailingBit = leastSignificantBit;
		Bit* leadingBit = trailingBit->get_next_bit();

		for (int i = 0; i < numBits - 1; i++) {
			trailingBit->clear_next_bit();
			delete trailingBit; // this operation explicitly deallocates
			trailingBit = leadingBit;
			leadingBit = leadingBit->get_next_bit();
		}

		leastSignificantBit = NULL;
		numBits = 0;
	}
	/* TODO:
	# You are to implement this method that will increment the binary
	# number stored in a linked list by one, making sure to propogate any
	# carries that are generated.
	# For example, if the number 15 is stored as "1111" and this
	# method is called,the result would be "10000" (really
	# represented as 0->0->0->0->1, where the carry "rippled" up the
	# bits, and an additional bit was added at the end because the 4th
	# 1 really became a "10"
	*/
	void increment() {
	}
};