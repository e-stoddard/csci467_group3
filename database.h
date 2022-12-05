/*
 * Eric Stoddard
 *
 * CSCI 467 - PE1
 *
 */

#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <vector>
#include <string>

#include "legacy_database.h"

using namespace std;

class database : public legacy_database
{
	public:
		database() {}	// constructor
		void new_stock(int amt);	// for adding a new product
		void add_stock(int index, int amt);
		void remove_stock(int index, int amt);

		int get_stock(int index) { return stock[index]; }
		void show_stock(int index) { cout << stock[index]; }

		//void new_order(string user_name, string prod_name, string quantity, string email, string addr);
		
		void add_order(vector<string> next) { orders.push_back(next); }

		std::string get_order_id(int index) { return orders[index][0]; }	
		std::string get_prod_name(int index) { return orders[index][1]; }	
		std::string get_quantity(int index) { return orders[index][2]; }	
		std::string get_total_price(int index) { return orders[index][3]; }	
		std::string get_email(int index) { return orders[index][4]; }
		std::string get_address(int index) { return orders[index][5]; }
		std::string get_status(int index) { return orders[index][6]; }

		void display_all_orders();

		// other public functions
	
	private:
		std::vector<std::vector<std::string>> orders;   // stores customer orders
		std::vector<int> stock;		// index = part number, int = amount in stock	   
};
#endif
