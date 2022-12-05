/*
 * Eric Stoddard
 *
 * CSCI 467 - PE1
 *
 */

#include "legacy_database.h"

// function definitions for legacy_database class

void legacy_database::add(string part_num, string des, string weight, string pic, string price)
{
	vector<string> record;
	record.push_back(part_num);
	record.push_back(des);
	record.push_back(weight);
	record.push_back(pic);
	record.push_back(price);
	leg_data.push_back(record);
}

void legacy_database::print_legacy()
{
	for (int i = 0; i < leg_data.size(); i++)
	{
		for (auto& elem : leg_data[i])
		{
			cout << elem << ", ";
		}
		cout << endl;
	}
}

