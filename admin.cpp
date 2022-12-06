#include <iostream>
#include <fstream>
#include <string>

constexpr size_t limitEntry {500};

struct AddProdu {
	float UnitCost {};
	int quantity {};
	std::string title;
};

struct DocList {
	size_t DocList {};
	AddProdu ie;
};

std::istream& operator>>(std::istream& is, DocList& rec) {
	if (is >> rec.DocList) {
		std::string title;

		while (!(is >> rec.ie.quantity)) {
			std::string temp;

			is.clear();
			is >> temp;
			title += temp + ' ';
		}

		title.pop_back();
		rec.ie.title = title;

		is >> rec.ie.UnitCost;
	}
	return is;
}

class Catlog {
public:
	AddProdu database[limitEntry];

	void Addproduct(const std::string& title, int c, float p);
	void Addproduct(const DocList& rec);
	void Removeproduct(const std::string& title);
	AddProdu* searchi(const std::string& title);
	void Update(const std::string& title, int total, float cost);
	void SHOW() const;
};

void Catlog::SHOW() const {
	for (size_t i = 0; i < limitEntry; ++i)
		if (!database[i].title.empty())
			std::cout << i << "  " << database[i].title << "  " << database[i].quantity << "  " << database[i].UnitCost << '\n';

	std::cout << '\n';
}

void Catlog::Addproduct(const DocList& rec) {
	database[rec.DocList] = rec.ie;
}

void Catlog::Addproduct(const std::string& title, int c, float p) {
	size_t QofProduct {};

	for (; !database[QofProduct].title.empty(); ++QofProduct);

	if (QofProduct < limitEntry) {
		database[QofProduct].title = title;
		database[QofProduct].quantity = c;
		database[QofProduct].UnitCost = p;
		std::cout << "\n\t\t PRODUCT INCLUDED!\n";
	} else
		std::cout << "Database Overload\n";
}

void Catlog::Removeproduct(const std::string& title) {
	auto* product {searchi(title)};

	if (product != nullptr) {
		product->title.clear();
		std::cout << "\n\t\t PRODUCT REMOVED.\n";
	} else
		std::cout << "\n\t\t PRODUCT NOT FOUND\n";
}

AddProdu* Catlog::searchi(const std::string& title) {
	for (size_t i = 0; i < limitEntry; ++i) {
		if (title == database[i].title)
			return &database[i];
	}

	return nullptr;
}

void Catlog::Update(const std::string& title, int total, float cost) {
	auto* product {searchi(title)};

	if (product == nullptr) {
		std::cout << "\n\t\t PRODUCT NOT FOUND\n";
		return;
	}

	product->quantity = total;
	product->UnitCost = cost;
}

int main() {
        std::ifstream ad("database.h");
	Catlog sto;
	int option {};

	if (ad) {
		std::string header;

		std::getline(ad, header);
		for (DocList rec; ad >> rec; sto.Addproduct(rec));
		std::cout << "File read\n\n";
	} else
		std::cout << "Couldn't read the file\n\n";

	do {
		std::string title;
		float unit_cost {};
		int quantity {};

		std::cout << "\n\t\t             ////////////"
			<< "\n\t\t\t    1 FOR INSERT"
			<< "\n\t\t\t    2 FOR REMOVE"
			<< "\n\t\t\t    3 FOR SEARCH"
			<< "\n\t\t\t    4 FOR UPDATE"
			<< "\n\t\t\t    5 FOR SHOW"
			<< "\n\t\t\t    6 FOR EXIT"
			<< "\n\t\t  ENTER YOUR CHOICE : ";

		std::cin >> option;
		std::cin.ignore();

		switch (option) {
			 case 1:
				std::cout << "\n\t\t\t ENTER TILTE OF PRODUCT : ";
				std::getline(std::cin, title);

				std::cout << "\n\t\t\t QUANTITY : ";
				std::cin >> quantity;

				std::cout << "\n\t\t\t UNIT COST PER PRODUCT : ";
				std::cin >> unit_cost;

				sto.Addproduct(title, quantity, unit_cost);
				break;

			 case 2:
				std::cout << "\n\t\t\t ENTER TILTE OF PRODUCT : ";
				std::getline(std::cin, title);
				sto.Removeproduct(title);
				break;

			 case 3:
				{
					std::cout << "\n\t\t\t ENTER TILTE OF PRODUCT : ";
					std::getline(std::cin, title);

					auto* test {sto.searchi(title)};

					if (test != nullptr) {
						std::cout << "\n\t FINDING....";
						std::cout << "\n\t\t\t   PRODUCT FOUND" << "\n\t\t\t TILTE OF PRODUCT:" << test->title
							<< "\n\t\t\t NUMBER OF QUANTITY AVAILABLE:" << test->quantity
							<< "\n\t\t\t UNIT COST PER PRODUCT:" << test->UnitCost;
					} else
						std::cout << "\n\t\t\t PRODUCT NOT FOUND";
				}
				break;

			 case 4:
				std::cout << "\n\t\t\t ENTER DETAILS FOR UPDATE : ";
				std::cout << "\n\t\t\t ENTER TITLE OF PRODUCT : ";
				std::getline(std::cin, title);

				std::cout << "\n\t\t\t ENTER TOTAL NEW ENTRY : ";
				std::cin >> quantity;

				std::cout << "\n\t\t\t ENTER NEW COST : ";
				std::cin >> unit_cost;

				sto.Update(title, quantity, unit_cost);
				break;

			 case 5:
				sto.SHOW();
				break;

			 case 6:
				break;

			OTHER:
				std::cout << "!!Choose an option from the above list!!\n";
		}
	} while (option != 6);
}
