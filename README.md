# csci467_group3

General Notes:

compile/link with:		

g++ -g -Wall -std=c++14 -c -o main.o main.cpp		

g++ -g -Wall -std=c++14 -c -o database.o database.cpp

g++ -g -Wall -std=c++14 -c -o legacy_database.o legacy_database.cpp

g++ -g -Wall -std=c++14 -o prog main.o legacy_database.o database.o

run with:

./prog -u 	for user interface

./prog -w	for warehouse interface 

./prog -a	for admin interface 

./prog -d	for warehouse receiving desk interface 


All data values store in the databases are strings.

All product names are integers to make searching/referenceing easier

All prices and quantities are integers so that std::stoi() and std::to_string() can be used to easily
convert between string and integers for calculations. 



Each row in orders:

<order ID, product name, quantity, weight (for product weight * quantity), total price (for product price * quantity), email, address, status>

notes on orders:
	
	A single row in orders is for only one product.
	
	An 'entire order' is every row with the same order ID. 
		
		This means...
		
		1. total price for an order is found by summing the prices found in orders and adding 
			shipping and handling costs. (I still need to add another element to hold the weight 
			of the order).
		
		2. email, address, status are all the same for every row in the 'entire order'

Each row in Leg_data:

<part number, description, weight, pic link, price>
