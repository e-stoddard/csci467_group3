/*
 * Eric Stoddard
 * Saraswi Vollala
 * Dulguun Narmandakh
 *
 * CSCI 467 - PE1
 *
 */

#include <iostream>
#include <unistd.h>
#include <iomanip>	//for setw() and setfill()

#include "legacy_database.h"
#include "database.h"

using namespace std;

void display_inventory(legacy_database legacy_data);

static void usage()
{
	cerr << "Usage: prog [-u] [-w] [-a] [-d]" << endl;
	cerr << "   -u access user interface" << endl;
	cerr << "   -w access warehouse interface" << endl;
	cerr << "   -a access admin interface" << endl;
	cerr << "   -d access warehouse receiving desk interface" << endl;
	cerr << "Must select one, and only one, interface." << endl;
	exit(1);
}

int main(int argc, char **argv)
{
	int opt;
	bool uflag = false;	// for user interface
	bool wflag = false;	// for warehouse interface
	bool aflag = false;	// for admin interface
	bool dflag = false;	// for warehouse receiving desk interface

	while ((opt = getopt(argc, argv, "uwad")) != -1)
	{
		switch(opt)
		{
		case 'u':
			{
				uflag = true;
				break;	
			}
		case 'w':
			{
				wflag = true;
				break;
			}
		case 'a':
			{
				aflag = true;
				break;
			}
		case 'd':
			{
				dflag = true;
				break;
			}
			break;
		default:
			usage();
		}
	}

//	Create / populate the database	

	legacy_database legacy_data;
	legacy_data.add("1", "bolt", "1", "picture.link", "1");
	legacy_data.add("2", "washer", "1", "picture.link", "1");
	legacy_data.add("3", "nut", "1", "picture.link", "1");
	legacy_data.add("4", "screw", "1", "picture.link", "1");
	legacy_data.add("5", "nail", "1", "picture.link", "1");
	legacy_data.add("6", "screw driver", "8", "picture.link", "5");
	legacy_data.add("7", "hammer", "32", "picture.link", "10");
	legacy_data.add("8", "wrench", "16", "picture.link", "10");
	legacy_data.add("9", "level", "16", "picture.link", "10");
	legacy_data.add("10", "gloves", "8", "picture.link", "5");

	database data;
	data.new_stock(1000);
	data.new_stock(1000);
	data.new_stock(1000);
	data.new_stock(1000);
	data.new_stock(1000);
	data.new_stock(100);
	data.new_stock(50);
	data.new_stock(100);
	data.new_stock(50);
	data.new_stock(100);

// This if statement will contain all the input and output for the 
// user interface. It will also make calls to class member functions 
// to handle the processing of any input
	if (uflag == true)
	{
		cout << "User Interface" << endl;
		
		std::string user_name;
		cout << "enter user name: ";
		cin >> user_name;

		cout << "Welcome " << user_name << ", take a look at our products below!" << endl;
		display_inventory(legacy_data);
			
		// loop to order products
/*		bool lflag = true;  // loop flag
		while (lflag == true)
		{
			// enter product ID and quantity
			// add products to order
			// add price to total price
			// display current order and total
			// add another product or checkout? (set lflag)
		}
*/
		// Display final order information

		// Enter credit card information

		// Add the order to the vector of orders in database
		
		// Remove selected products from database

	}

	if (wflag == true)
	{
		cout << "Warehouse Interface" << endl;
		// This if statement will contain all the input and output for the 
		// warehouse interface. It will also make calls to class member functions 
		// to handle the processing of any input
	}

	if (aflag == true)
	{
		cout << "Admin Interface" << endl;
		// This if statement will contain all the input and output for the 
		// admin interface. It will also make calls to class member functions 
		// to handle the processing of any input
	}

	if (dflag == true)
	{
		cout << "Warehouse receiving desk Interface" << endl;
		// This if statement will contain all the input and output for the 
		// warehouse receiving desk interface. It will also make calls to class 
		// member functions to handle the processing of any input
	}
	return 0;
}

void display_inventory(legacy_database legacy_data)
{
	cout << "Product name " << "Description  " << "pic link     " 
	       << "Price        " << "Quantity     " << endl;
	for (int i = 0; i < legacy_data.get_size(); i++)
	{
		cout << setw(13) << left << legacy_data.get_part_num(i);
		cout << setw(13) << left << legacy_data.get_des(i);
		cout << setw(13) << left << legacy_data.get_pic(i);
		cout << setw(13) << left << legacy_data.get_price(i);
		cout << setw(13) << "quantity";
		cout << endl;
	}
}


