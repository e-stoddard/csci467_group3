/*
 * Eric Stoddard
 * Saraswi Vollala
 * Dulguun Narmandakh
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


