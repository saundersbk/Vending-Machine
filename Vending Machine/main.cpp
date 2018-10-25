// File Name: main.cpp
// Functionality: Create a vending machine
// Brandon K. Saunders 
// Virginia Commonwealth University
 
 #include <stdio.h>
 #include "VendingMachine.h"
 
 enum state {
	getMoney, displayPrice, vend, e_state
 };
 
 void showInfo(VendingMachine, coins);	//Display relevant info for getMoney state
 
 
 int main() {
	VendingMachine VM;
	coins wallet;
	state current = getMoney;	//Initialize current state to getMoney
	int choice;
	
	wallet.dollars = 2;
	wallet.quarters = 5;
	wallet.dimes = 2;
	wallet.nickels = 1;
	
	while (current != e_state) { //Begin state machine.  Loop until current state is the exit state
		switch(current) {
			case getMoney:
				showInfo(VM, wallet);
			
				do {
					fflush(stdin);
					cin.clear();
					cout << "choice: ";
					cin  >> choice;
					if (!cin.good() || choice < 0 || choice > 10)
						cout << "Bad Choice" << endl;
				} while(!cin.good());
				
				if (choice == 0) {
					current = e_state;
				}
				else if (choice >= 1 && choice <= 6) {
					if (VM.getUserCoin() < VM.getItemPrice(choice) || VM.getItemStock(choice) == 0) {
						current = displayPrice;
					}
					else {
						current = vend;
					}
				}
				else {
					switch(choice) {
						case 7:
							if (wallet.dollars == 0) {
								cout << "No more dollars left" << endl;
							}
							else {
								VM.receiveDollar();
								wallet.dollars--;
							}
							current = getMoney;
						break;
						
						case 8:
							if (wallet.quarters == 0) {
								cout << "No more quarters left" << endl;
							}
							else {
								VM.receiveQuarter();
								wallet.quarters--;
							}
							current = getMoney;
						break;
						
						case 9:
							if (wallet.dimes == 0) {
								cout << "No more dimes left" << endl;
							}
							else {
								VM.receiveDime();
								wallet.dimes--;
							}
							current = getMoney;
						break;
						
						case 10:
							if (wallet.nickels == 0) {
								cout << "No more nickels left" << endl;
							}
							else {
								VM.receiveNickel();
								wallet.nickels--;
							}
							current = getMoney;
						break;
						
						default:
							cout << "Broken" << endl;
						break;
					}
				}
			break;
			
			case displayPrice:
				if (VM.getUserCoin() < VM.getItemPrice(choice) && VM.getItemStock(choice) != 0) {
					cout << VM.getItemName(choice) << ": " << VM.getItemPrice(choice) << endl;
				}
				else {
					cout << "SOLD OUT" << endl;
				}
				current = getMoney;
			break;
			
			case vend:
				coins temp;
				temp.dollars = wallet.dollars;
				temp.quarters = wallet.quarters;
				temp.dimes = wallet.dimes;
				temp.nickels = wallet.nickels;
				cout << "Vending...." << endl;
				VM.change(temp, VM.getItemPrice(choice));
				VM.vendItem(choice);
				wallet.dollars = temp.dollars;
				wallet.quarters = temp.quarters;
				wallet.dimes = temp.dimes;
				wallet.nickels = temp.nickels;
				current = getMoney;
			break;
			
			
			default:
				cout << "Broken" << endl;
			break;
			
	 
		 }
	 }
	 
	 if (wallet.dollars == 2 && wallet.quarters == 5 && wallet.dimes == 2 && wallet.nickels == 1) {
		 cout << "Have a nice day!" << endl;
	 }
	 else {
			cout << "Refunding... Have a nice day!" << endl;
			VM.refund(wallet);
	 }
	 return 0;
 }
 
  void showInfo(VendingMachine options, coins remaining) {
	cout << endl;
	cout << "You have: " << endl;
	cout << "Dollars : " << remaining.dollars << endl;
	cout << "Quarters: " << remaining.quarters << endl;
	cout << "Dimes   : " << remaining.dimes << endl;
	cout << "Nickels : " << remaining.nickels << endl;
	
	cout << options;
	cout << "Input - $" << options.getUserCoin() << endl;
  }