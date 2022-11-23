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

using namespace std;

static void usage()
{
	cerr << "Usage: prog [-u] [-w] [-a]" << endl;
	cerr << "   -u access user interface" << endl;
	cerr << "   -u access user interface" << endl;
	cerr << "   -u access user interface" << endl;
	exit(1);
}

int main(int argc, char **argv)
{
	int opt;
	bool uflag = false;	// for user interface
	bool wflag = false;	// for warehouse interface
	bool aflag = false;	// for admin interface

	while ((opt = getopt(argc, argv, "uwa")) != -1)
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
			break;
		default:
			usage();
		}
	}

	if (uflag == true)
	{
		cout << "User Interface" << endl;
		// This if statement will contain all the input and output for the 
		// user interface. It will also make calls to class member functions 
		// to handle the processing of any input
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

	return 0;
}

