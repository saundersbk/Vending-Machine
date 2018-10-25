// File Name: VendingMachine.h
// Functionality: Declare the VendingMachine class, coins structure
// Brandon K. Saunders 
// Virginia Commonwealth University
// Credits: Ryan Green, Virginia Commmonwealth University

#include <iostream>
#include <string>
#include <iomanip>
#include <ios>

#define MAX_STOCK 10 // How many slots (maximum) of each item the vending machine can hold

using namespace std;

// Structure for Money taken by Vending Machines
struct coins{
	int dollars;  						// Number of dollars
	int quarters; 						// Number of quarters
	int dimes;    						// Number of dimes
	int nickels;  						// Number of nickels
};

//Vending Machine Class
class VendingMachine{
	private:
		// Structure for items in Vending Machine
		struct item{
			string name;  				// Name of the item sold
			double price; 				// Price of the item sold
			int stock;    				// Number of items in stock
		};
		
		// Six types of items the vending machine can hold
		item Item1;
		item Item2;
		item Item3;
		item Item4;
		item Item5;
		item Item6;
		
		
		coins TemporaryBox; 			// The vending machine holds Money here before an item is vended for Refunding
		coins CoinBox;      			// Money Storage for Vending Machines
		
		bool ExactChange;				// Exact Change flag
		bool NeedExact();				// Utility Method to determine if the machine needs exact change
		void display(ostream&);			// Utility Method to help << operator function
		
	public:
		//Constructor
		VendingMachine();				
		
		//Accessor Methods
		string getItemName(int);       	// Returns an item name.  Input should be integers 1-6 corresponding to Item1-Item6
		double getItemPrice(int);		// Returns an item price. Input should be integers 1-6 corresponding to Item1-Item6
		int getItemStock(int);			// Returns an item stock. Input should be integers 1-6 corresponding to Item1-Item6
				
		double getTotal();			   	// Returns the total amount of money stored in the Machine
		double getUserCoin();			// Returns the amount of money from the user stored in the Machine
		
		// Mutator Methods
		void receiveDollar();			// Receives Dollar from user - Puts dollar into TemporaryBox
		void receiveQuarter(); 		   	// Receives Quarter from user - Puts quarter into TemporaryBox
		void receiveDime();			   	// Receives Dime from user - Puts dime into TemporaryBox
		void receiveNickel();          	// Receives Nickel from user - Puts nickel into TemporaryBox
		
				
		void vendItem(int);				// Removes an Item corresponding to integer input.
		
		
		void refund(coins&);			// Refunds the money put in by user - Accepts coin "pouch" as argument
		void change(coins&, double); 	// Returns the change - Accepts 2 Arguments 1) coin "pouch" from user 2) price of item;
		
		friend ostream& operator<<(ostream&, VendingMachine&); // Overloaded << operator to use with cout.
		
};