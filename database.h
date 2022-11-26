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
		database() {}	// constructor
		void new_stock(int amt);	// for adding a new product
		void add_stock(int index, int amt);
		void remove_stock(int index, int amt);

		int get_stock(int index) { return stock[index]; }
		void show_stock(int index) { cout << stock[index]; }

		// other public functions
	
	private:
		std::vector<std::vector<std::string>> orders;   // stores customer orders
		std::vector<int> stock;		// index = part number, int = amount in stock	   
};
#endif
