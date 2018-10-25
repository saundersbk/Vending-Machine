// File Name: VendingMachine.cpp
// Functionality: Implement functionality of VendingMachine class methods
// Brandon K. Saunders 
// Virginia Commonwealth University
// Credits: Ryan Green, Virginia Commonwealth University

#include "VendingMachine.h"

VendingMachine::VendingMachine(){
	// Defaulted Items stored in Vending Machine
	// Item names:
	Item1.name = "Cola";
	Item2.name = "Root Beer";
	Item3.name = "Sports Drink";
	Item4.name = "Bottled Water";
	Item5.name = "Sweet Tea";
	Item6.name = "Green Tea";
	
	//Item prices:
	Item1.price = 1.50;
	Item2.price = 1.50;
	Item3.price = 1.50;
	Item4.price = 1.00;
	Item5.price = 1.50;
	Item6.price = 1.50;
	
	// Item numbers (stock):
	Item1.stock  = MAX_STOCK;
	Item2.stock = MAX_STOCK;
	Item3.stock= MAX_STOCK;
	Item4.stock = MAX_STOCK;
	Item5.stock  = MAX_STOCK;
	Item6.stock  = MAX_STOCK;
	
	// Amount of currency to make change
	CoinBox.dollars = 100;
	CoinBox.quarters = 100;
	CoinBox.dimes = 100;
	CoinBox.nickels = 100;	
	
	// Temporary Box of user input currency is initialized to 0
	TemporaryBox.dollars = 0;
	TemporaryBox.quarters = 0;
	TemporaryBox.dimes = 0;
	TemporaryBox.nickels = 0;
	
	// Vending Machine determines if it needs exact change
	ExactChange = NeedExact();
}

// Accessor Methods

string VendingMachine::getItemName(int i)
{
	string itemName = "";
	
	switch(i)
	{
		case 1: //If Item1
			itemName = Item1.name;
			break;
		case 2: //If Item2
			itemName = Item2.name;
			break;
		case 3: //If Item3
			itemName = Item3.name;
			break;
		case 4: //If Item4
			itemName = Item4.name;
			break;
		case 5: //If Item5
			itemName = Item5.name;
			break;
		case 6: //If Item6
			itemName = Item6.name;
			break;
		default: //If Item requested isn't offered
			itemName = "NA";
			break;
	}
	
	return itemName;
}

double VendingMachine::getItemPrice(int i)
{
	double itemPrice = 0;
	switch(i)
	{
		case 1://If Item1
			itemPrice = Item1.price;
			break;
		case 2://If Item2
			itemPrice = Item2.price;
			break;
		case 3://If Item3
			itemPrice = Item3.price;
			break;
		case 4://If Item4
			itemPrice = Item4.price;
			break;
		case 5://If Item5
			itemPrice = Item5.price;
			break;
		case 6://If Item6
			itemPrice = Item6.price;
			break;
		default: //If Item requested isn't offered
			itemPrice = 0;
			break;
	}
	
	return itemPrice;
}

int VendingMachine::getItemStock(int i)
{
	int itemStock = 0;
	switch(i)
	{
		case 1://If Item1
			itemStock = Item1.stock;
			break;
		case 2://If Item2
			itemStock = Item2.stock;
			break;
		case 3://If Item3
			itemStock = Item3.stock;
			break;
		case 4://If Item4
			itemStock = Item4.stock;
			break;
		case 5://If Item5
			itemStock = Item5.stock;
			break;
		case 6://If Item6
			itemStock = Item6.stock;
			break;
		default: //If Item requested isn't offered
			itemStock = 0;
			break;
	}
	
	return itemStock;
}

double VendingMachine::getTotal(){ // Returns the total amount of money stored in the Machine 
	double total = 0.0;
	
	total += static_cast<double>(CoinBox.dollars); 			// Number of dollars * 1.00
	total += static_cast<double>(CoinBox.quarters) * 0.25; 	// Number of quarters * 0.25
	total += static_cast<double>(CoinBox.dimes) * 0.10;		// Number of dimes * 0.10
	total += static_cast<double>(CoinBox.nickels) * 0.05;	// Number of nickels * 0.05
	
	return total;
}

double VendingMachine::getUserCoin(){
	double total = 0.0;
	
	total += static_cast<double>(TemporaryBox.dollars);				// Number of dollars * 1.00
	total += static_cast<double>(TemporaryBox.quarters) * 0.25;		// Number of quarters * 0.25
	total += static_cast<double>(TemporaryBox.dimes) * 0.10;		// Number of dimes * 0.10
	total += static_cast<double>(TemporaryBox.nickels) * 0.05;		// Number of nickels * 0.05
	
	return total;
}


// Mutators
void VendingMachine::receiveDollar(){
	TemporaryBox.dollars ++;		// TemporaryBox receives a dollar
}

void VendingMachine::receiveQuarter(){
	TemporaryBox.quarters ++;		// TemporaryBox receives a quarter
}

void VendingMachine::receiveDime(){
	TemporaryBox.dimes++;			// TemporaryBox receives a dime
}

void VendingMachine::receiveNickel(){
	TemporaryBox.nickels ++;		// TemporaryBox receives a nickel
}

void VendingMachine::refund(coins& user){
	// Returns money input from user 
	user.dollars += TemporaryBox.dollars;
	user.quarters += TemporaryBox.quarters;
	user.dimes += TemporaryBox.dimes;
	user.nickels += TemporaryBox.nickels;
	
	// Resets TemporaryBox
	TemporaryBox.dollars = 0;
	TemporaryBox.quarters = 0;
	TemporaryBox.dimes = 0;
	TemporaryBox.nickels = 0;
	
	// Determines if exact change is needed
	ExactChange = NeedExact();
	
}

void VendingMachine::vendItem(int i)
{
	// Reduces Item stock
	switch(i)
	{
		case 1:
			Item1.stock--;
			break;
		case 2:
			Item2.stock--;
			break;
		case 3:
			Item3.stock--;
			break;
		case 4:
			Item4.stock--;
			break;
		case 5:
			Item5.stock--;
			break;
		case 6:
			Item6.stock--;
			break;
		default:
			break;
	}
	
	// Collects user input currency
	CoinBox.dollars += TemporaryBox.dollars;
	CoinBox.quarters += TemporaryBox.quarters;
	CoinBox.dimes += TemporaryBox.dimes;
	CoinBox.nickels += TemporaryBox.nickels;
	
	// Resets TemporaryBox
	TemporaryBox.dollars = 0;
	TemporaryBox.quarters =0;
	TemporaryBox.dimes = 0;
	TemporaryBox.nickels = 0;
	
	// Determines if exact change is needed
	ExactChange = NeedExact();
}

void VendingMachine::change(coins& user, double price){
	// Determines how much money the user input into the machine
	double total = TemporaryBox.dollars + TemporaryBox.quarters*0.25 + TemporaryBox.dimes*0.1 + TemporaryBox.nickels*0.05;
	// Calculates the change
	double change = total - price;
	
	// Gives Dollars back from the CoinBox. 
	while(change - 1.00 >= 0 && CoinBox.dollars > 0){ // Determines if a dollar is needed and that the machine has a dollar
		change -= 1.00; 		// removes a dollar from the amount of change due
		user.dollars++; 		// gives a dollar to the user
		CoinBox.dollars--; 		// removes a dollar from the coinbox
	}
	//Gives Quarters back from the Coin Box.
	while(change - 0.25 >= 0 && CoinBox.quarters > 0){// Determines if a quarter is needed and that the machine has a quarter
		change -= 0.25; 		// removes a quarter from the amount of change due
		user.quarters ++; 		// gives a quarter to the user
		CoinBox.quarters --; 	// removes a quarter from the coinbox
	}
	while(change - 0.10 >= 0 && CoinBox.dimes > 0){// Determines if a dime is needed and that the machine has a dime
		change -= 0.10;			// removes a dime from the amount of change due
		user.dimes ++;			// gives a dime to the user
		CoinBox.dimes --;		// removes a dime from the coinbox
	}
	while(change - 0.05 >= 0 && CoinBox.nickels > 0){// Determines if a nickel is needed and that the machine has a nickel
		change -= 0.05;			// removes a nickel from the amount of change due
		user.nickels ++;		// gives a nickel to the user
		CoinBox.nickels --;		// removes a nickel from the coinbox
	}	
	
	// Determines if exact change is needed
	ExactChange = NeedExact();
}

bool VendingMachine::NeedExact()
{
	bool outcome = false; // Default value is false
	
	// if the number of dollars, quarters, dimes, or nickels fall below a certain item, the indicator needs to be turned on
	if(CoinBox.dollars < 1 || CoinBox.quarters < 2 || CoinBox.dimes < 2 || CoinBox.nickels < 10)
		outcome = true; // Changing the outcome value
	return outcome; 
}

void VendingMachine::display(ostream& os) // Utility method to use for <<
{
	
	os << fixed << setprecision(2)<<endl;
	os << setw(30) << setfill('-')<<left<<"VENDING MACHINE"<<endl;
	for(int i =1; i<=6; i++){
		os <<" "<<i<<". " << getItemName(i) << " - $" << getItemPrice(i) <<endl;
	}
	
	os << endl;
	if(ExactChange)
		cout << "EXACT CHANGE "<<endl;
	else
		cout << endl;
	
	os << " 7. Insert Dollar"<<endl<<" 8. Insert Quarter"<<endl<<" 9. Insert Dime"<<endl<<"10. Insert Nickel"<<endl<<endl<< " 0. REFUND"<<endl;
	
	
}

ostream& operator<<(ostream& os, VendingMachine& machine) // Overloaded operator <<
{
	machine.display(os);
	return os;
}

