/*
 * Eric Stoddard
 *
 * CSCI 467 - PE1
 *
 */

#include "database.h"

// function definitions database class

void database::new_stock(int amt)
{
	stock.push_back(amt);
}

void database::add_stock(int index, int amt)
{
	stock[index] += amt;
}
void database::remove_stock(int index, int amt)
{
	if (amt < get_stock(index))
	{
		stock[index] -= amt;
	}
	else 
	{ 
		cout << "Not enough in stock. Only " << stock[index] << " available" << endl; 
	}
}
/*
void database::new_order(string user_name, string prod_name, string quantity, string email, string addr)
{


	vector<string> temp;
	temp.push_back(user_name);
	temp.push_back(prod_name);
	temp.push_back(quantity);

	std::size_t pos1{};
	std::stoi(prod_name, &pos1);
	int prod_id = pos1;
	string price = legacy_database::get_price(prod_id);
	
	std::size_t pos2{};
	std::stoi(price, &pos2);
        int price_calc = pos2;	
	
	std::size_t pos3{};
	std::stoi(quantity, &pos3);
	int amount = pos3;

	int total_price = amount * price_calc;
	string total = std::to_string(total_price);
	temp.push_back(total);

	temp.push_back(email);
	temp.push_back(addr);
	temp.push_back("Received");

	orders.push_back(temp);
}
*/
void database::display_all_orders()
{
	cout << "***All Orders***" << endl;
	for (int i = 0; i < orders.size(); i++)
	{
		for (auto& elem : orders[i])
		{
			cout << elem << ", ";
		}
		cout << endl;
	}
}

