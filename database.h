/*
 * Eric Stoddard
 * Saraswi Vollala
 * Dulguun Narmandakh
 *
 * CSCI 467 - PE1
 *
 */

#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class database
{
	public:
		// constructor

		// other public functions
	
	private:
		std::vector<std::vector<std::string>> orders;   // stores customer orders
		std::vector<int> stock;		// index = part number, int = amount in stock	   
};
#endif
