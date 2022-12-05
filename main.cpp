/*
 * Eric Stoddard
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

void display_inventory(legacy_database legacy_data, database data);
void display_orders_user(vector<vector<string>> next_order);
void populate_orders(database &data);

int shipping_charge_A = 5;
int shipping_charge_B = 10;
int shipping_charge_c = 15;

int shipping_weight_A = 20;
int shipping_weight_B = 50;

int get_shipping_charge(int weight)
{
	if (weight < shipping_weight_A) { return shipping_charge_A; }
	
	if ((weight > shipping_weight_A) && (weight < shipping_weight_B))
	{ return shipping_charge_B; }
	
	if (weight > shipping_weight_B) { return shipping_charge_c; }
	else { return 0; }
}

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

//	Create / populate the initial database	

	legacy_database legacy_data;
	legacy_data.add("0", "bolt", "1", "picture.link", "1");
	legacy_data.add("1", "washer", "1", "picture.link", "1");
	legacy_data.add("2", "nut", "1", "picture.link", "1");
	legacy_data.add("3", "screw", "1", "picture.link", "1");
	legacy_data.add("4", "nail", "1", "picture.link", "1");
	legacy_data.add("5", "screw driver", "8", "picture.link", "5");
	legacy_data.add("6", "hammer", "32", "picture.link", "10");
	legacy_data.add("7", "wrench", "16", "picture.link", "10");
	legacy_data.add("8", "level", "16", "picture.link", "10");
	legacy_data.add("9", "gloves", "8", "picture.link", "5");

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

	populate_orders(data);
	int order_number = 2; 	// first 2 order numbers are in initial database


// This if statement will contain all the input and output for the 
// user interface. It will also make calls to class member functions 
// to handle the processing of any input
	while (uflag == true)
	{
		cout << "User Interface" << endl;
		
		std::string user_name;
		cout << "enter user name: ";
		cin >> user_name;

		cout << "Welcome " << user_name << ", take a look at our products below!" << endl;
		display_inventory(legacy_data, data);
			
		// loop to order products
		vector<vector<string>> next_order;
		int total_order_price = 0;
		int total_order_weight = 0;
		bool lflag = true;  // loop flag
		while (lflag == true)
		{
			vector<string> temp;
			
			std::string order_id = std::to_string(order_number);
			temp.push_back(order_id);

			int prod_num, quantity;
			// enter product ID and quantity
			cout << "Enter the product name you would like to order: ";
			cin >> prod_num;
			cout << endl;

			cout << "Enter quantity: ";
			cin >> quantity;

			// add products to temp order
			string prod_name = std::to_string(prod_num);
			temp.push_back(prod_name);
			string quant_string = std::to_string(quantity);
			temp.push_back(quant_string);

			// add weight * quantity
			string weight = legacy_data.get_weight(prod_num);
			int weight_calc = std::stoi(weight);
			int total_weight_calc = weight_calc * quantity;
			total_order_weight += total_weight_calc;
			string total_weight = std::to_string(total_weight_calc);
			temp.push_back(total_weight);

			// add price to total price
			string price = legacy_data.get_price(prod_num);

			int price_calc = std::stoi(price);

			int total_calc = quantity * price_calc;
			total_order_price += total_calc;
			string total = std::to_string(total_calc);

			temp.push_back(total);

			// display current order and total
			cout << "You selected " << quantity << " " << prod_name << "('s) for a total of $"
				<< total << endl;

			// add another product or checkout? (set lflag)
			cout << "To add another product to your order, enter '1'" << endl;
			cout << "To checkout, enter '2'" << endl;
			cout << "To cancel product, press 'enter'" << endl;
			int checkout;
			cin >> checkout;

			if (checkout == 1)
			{
				next_order.push_back(temp);
			}
			if (checkout == 2)
			{
				next_order.push_back(temp);
				lflag = false;
			}
			temp.clear();
		}

		// Display final order information
		display_orders_user(next_order);
		cout << "         Order Price: $" << total_order_price << endl;
		int ship_cost = get_shipping_charge(total_order_weight);
		cout << " Shipping / handling: $" << ship_cost << endl;
		cout << "                    = $" << total_order_price + ship_cost << endl;

		// Enter credit card information
		std::string ccn;
		cout << "Enter your credit card number: ";
		cin.ignore();
		getline(cin, ccn);
		
		// Enter email
		std::string email;
		cout << "Enter your email: ";
		getline(cin, email);
		
		// Enter address
		std::string address;
		cout << "Enter your address: ";
		getline(cin, address);

		// Add the order to the vector of orders in database
		for (int i = 0; i < next_order.size(); i++)
		{	
			next_order[i].push_back(email);
			next_order[i].push_back(address);
			next_order[i].push_back("Pending");
			data.add_order(next_order[i]);	
		}

		order_number += 1;

		data.display_all_orders();

		// Remove selected products from database
		for (int j = 0; j < next_order.size(); j++)
		{
			for (auto& elem : next_order[j])
			{
				std::string name = next_order[j][1];
				int num = std::stoi(name);
				std::string quant_ch = next_order[j][2];
				int quant = std::stoi(quant_ch);
				data.remove_stock(num, quant);
			}
		}
			
		// Place another order?
		char ans;
		cout << "email confirmation has been sent." << endl;
		cout << "Place another order? (y/n): ";
		cin >> ans;
		if (ans == 'n' || ans == 'N')
		{
			cout << "Thank you for shopping with us!" << endl;
			uflag = false;
		}

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

void display_inventory(legacy_database legacy_data, database data)
{
	cout << "Product name " << "Description  " << "pic link     " 
	       << "Price        " << "Quantity     " << endl;
	for (int i = 0; i < legacy_data.get_size(); i++)
	{
		cout << setw(13) << left << legacy_data.get_part_num(i);
		cout << setw(13) << left << legacy_data.get_des(i);
		cout << setw(13) << left << legacy_data.get_pic(i);
		cout << setw(13) << left << legacy_data.get_price(i);
		cout << setw(13) << data.get_stock(i);
		cout << endl;
	}
}

void display_orders_user(vector<vector<string>> next_order)
{
	cout << "***Summary of Current Order***" << endl;
	for (int i = 0; i < next_order.size(); i++)
	{
		string s1 = next_order[i][0];	// product name
		string s2 = next_order[i][1];	// quantity
		string s3 = next_order[i][2];	// price * quantity
		
		cout << "Product name: " << s1 << ", Quantity: " << s2 << ", = $" << s3 << endl;

	}
}

void populate_orders(database &data)
{
	vector<string> temp;
	temp.push_back("0");
	temp.push_back("4");
	temp.push_back("10");
	temp.push_back("40");
	temp.push_back("40");
	temp.push_back("example@gmail.com");
	temp.push_back("31 main st");
	temp.push_back("Completed");
	data.add_order(temp);
	temp.clear();

	temp.push_back("0");
	temp.push_back("1");
	temp.push_back("5");
	temp.push_back("5");
	temp.push_back("5");
	temp.push_back("example@gmail.com");
	temp.push_back("31 main st");
	temp.push_back("Completed");
	data.add_order(temp);
	temp.clear();

	temp.push_back("1");
	temp.push_back("9");
	temp.push_back("2");
	temp.push_back("16");
	temp.push_back("10");
	temp.push_back("random@gmail.com");
	temp.push_back("571 south st");
	temp.push_back("Completed");
	data.add_order(temp);
	temp.clear();

	temp.push_back("1");
	temp.push_back("7");
	temp.push_back("1");
	temp.push_back("16");
	temp.push_back("10");
	temp.push_back("random@gmail.com");
	temp.push_back("571 south st");
	temp.push_back("Completed");
	data.add_order(temp);
	temp.clear();

	temp.push_back("1");
	temp.push_back("0");
	temp.push_back("20");
	temp.push_back("20");
	temp.push_back("20");
	temp.push_back("random@gmail.com");
	temp.push_back("571 south st");
	temp.push_back("Completed");
	data.add_order(temp);
	temp.clear();
}
