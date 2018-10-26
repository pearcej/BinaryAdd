/*-------------------------------------------------------------------------------
# Name:        bit.cpp
# Purpose:  a C++ object oriented representation of a bit in a binary number.
#
# Author:      Assignment concept: pearcej, converted to Python by nakazawam
#              and then back to C++ by nakazawam
#       Note that this implementation of a bit is using true OOP because
#       access to the instance variables is restricted to appropriate methods.
#
# Created:     21/09/2014
#------------------------------------------------------------------------------*/
#include <stdlib.h>	// this library contains NULL
#include <assert.h>
#include <string>
using namespace std;
class Bit {

private:
	bool bitValue;
	Bit* nextBit;

public:
	Bit(bool value = false, Bit*next = NULL) {
		//constructor creates a new bit that is by default
		//false (i.e. 0) and references None'''
		bitValue = value;
		nextBit = next;
	}

	Bit* get_next_bit() {
		//accessor method that returns the next bit this one
		//is referencing. If this bit is the last one, it returns
		//NULL, of course
		return nextBit;
	}

	bool get_bit() {
		//accessor method that returns the values of this bit.
		return bitValue;
	}

	void set_bit(bool newValue) {
		//manipulator method to set the bit to whatever is input.
		//post: the bit value for this object is set to input parameter value.'''
		bitValue = newValue;
	}

	void add_next_bit(bool initValue) {
		// manipulator method that inserts a Bit object after this one with
		//the value that is the input parameter.
		//post: this Bit will reference the new one created, and the new one
		//    will have the value that is input into this function. '''
		nextBit = new Bit(initValue);
	}

	void clear_next_bit() {
		//Removes the reference to the next bit so that Python's garbage
		//collection will take care of this dereferenced object'''
		nextBit = NULL;
	}

	string to_string() {
		//returns a string representation of this bit for printing purposes.
		// The convention is that False --> "0" and True --> "1"'''
		if (bitValue)
			return "1";
		return "0";
	}
};
