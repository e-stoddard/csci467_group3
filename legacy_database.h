/*
 * Eric Stoddard
 * Saraswi Vollala
 * Dulguun Narmandakh
 *
 * CSCI 467 - PE1
 *
 */

#ifndef LEGACY_DATABASE_H
#define LEGACY_DATABASE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class legacy_database
{
	public:
		legacy_database() {}	// constructor
		void add(string part_num, string des, string weight, string pic, string price);

		int get_size() { return leg_data.size(); }
		std::string get_part_num(int index) const { return leg_data[index][0]; }
		std::string get_des(int index) const { return leg_data[index][1]; }
		std::string get_weight(int index) const { return leg_data[index][2]; }
		std::string get_pic(int index) const { return leg_data[index][3]; }
		std::string get_price(int index) const { return leg_data[index][4]; }
/*
		void update_part_num(int index, string new_part_num);
		void update_des(int index, string new_des);
		void update_weight(int index, string new_weight);
		void update_pic(int index, string new_pic);
		void update_price(int index, string price);
*/

		void print_legacy();


		// other public member functions
	private:
		std::vector<std::vector<std::string>> leg_data;	  // legacy database
};
#endif

