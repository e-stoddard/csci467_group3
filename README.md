# csci467_group3

General Notes:

All data values store in the databases are strings.

All product names are integers to make searching/referenceing easier

All prices and quantities are integers so that std::stoi() and std::to_string() can be used to easily
convert between string and integers for calculations. 



Each row in orders: (need to add weight)

orders<order ID, product name, quantity, total price (for that product), email, address, status>

notes on orders:
	
	A single row in orders is for only one product.
	
	An 'entire order' is every row with the same order ID. 
		
		This means...
		
		1. total price for an order is found by summing the prices found in orders and adding 
			shipping and handling costs. (I still need to add another element to hold the weight 
			of the order).
		
		2. email, address, status are all the same for every row in the 'entire order'
