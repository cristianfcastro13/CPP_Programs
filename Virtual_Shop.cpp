#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstring>

using namespace std;

//Method that returns the price of an item give its product code
float getPrice(int userInput) {

	float tempPrice = 0;
	int objects[7] = { 1, 2, 3, 4, 5, 6, 7 };
	float objPrices[7] = { 13.99, 43.99, 30.00, 9.99, 4.99, 19.99, 45.99 };

	for (int i = 0; i < 7; i++) {
		if (userInput == objects[i]) {
			tempPrice = objPrices[i];
		}
	}
	return tempPrice;
}

//Method that checks that the number inserted by the user it within the product codes range
bool valInput(int userInput) {

	bool temp = false;
	int objects[7] = { 1, 2, 3, 4, 5, 6, 7 };

	for (int i = 0; i <= 6; i++) {
		if (userInput == objects[i]) {
			temp = true;
			break;
		}
	}
	return temp;
}

//Method that returns rounded input to two decimal places 
float hatsuRound(float temp) {
	int x = 0;
	x = temp * 100;
	temp = x / 100;
	return temp;
}

//Method that processes the change after the totalDue and ouputs it to console
void processChange(float change) {

	int billCalculation = 0;
	billCalculation = hatsuRound(change);

	// Bill change calculation and output
	cout << "\n\n Your change is: $" << change;

	cout << "\n\n Number of $100 bills: " << billCalculation / 100;
	billCalculation = billCalculation - (100 * (billCalculation / 100));
	cout << "\n Number of $50 bills: " << billCalculation / 50;
	billCalculation = billCalculation - (50 * (billCalculation / 50));
	cout << "\n Number of $20 bills: " << billCalculation / 20;
	billCalculation = billCalculation - (20 * (billCalculation / 20));
	cout << "\n Number of $10 bills: " << billCalculation / 50;
	billCalculation = billCalculation - (10 * (billCalculation / 10));
	cout << "\n Number of $5 bills: " << billCalculation / 5;
	billCalculation = billCalculation - (5 * (billCalculation / 5));
	cout << "\n Number of $1 bills: " << billCalculation;

	int tempCoin = (change * 100);
	int coinCalculation = tempCoin % 100;

	// Coin change calculation and output
	cout << "\n Number of quarters: " << coinCalculation / 25;
	coinCalculation = coinCalculation - (25 * (coinCalculation / 25));
	cout << "\n Number of dimes: " << coinCalculation / 10;
	coinCalculation = coinCalculation - (10 * (coinCalculation / 10));
	cout << "\n Number of nickels : " << coinCalculation / 5;
	coinCalculation = coinCalculation - (5 * (coinCalculation / 5));
	cout << "\n Number of pennies : " << coinCalculation;

}

int main()
{
	int userInput = 0;
	float priceDue = 0;
	bool breaker = false;
	float totalDue = 0;

	//Interface for the shop itself
	cout << " Greetings Customer, and welcome to the Multiobject Shop! \n The items at sale at our shop are listed below. \n \n To select an item please type its corresponding code below.";
	cout << "\n\n Code	Product					Price";
	cout << "\n \n 1	Ski Mask				$13.99";
	cout << "\n 2	Axe					$43.99";
	cout << "\n 3	Cloroform (100ml)			$30.00";
	cout << "\n 4	General Gasoline (3L)			$9.99";
	cout << "\n 5	Ducktape				$4.99";
	cout << "\n 6	Lab Coat				$19.99";
	cout << "\n 7	Sodium Hydroxide			$45.99";

	cout << "\n\n In order to end the shopping, type '420'. \n If you want to reset your shopping spree, type '69'.\n";


	// While loop for total Calculation.
	while (breaker == false) {

		cout << "\n Type Code Item Here: ";
		cin >> userInput;

		//If for cart reset
		if (userInput == 69) {
			priceDue = 0;
			cout << "\n The your shopping cart was reset.";
		}

		//If for shopping end
		if (userInput == 420) {
			breaker = true;
			totalDue = priceDue + (priceDue - hatsuRound(priceDue * 0.925));
			cout << "\n\n	Subtotal		" << priceDue;
			cout << "\n	Tax			" << priceDue - hatsuRound(priceDue * 0.925);
			cout << "\n	-------------------------------";
			cout << "\n	Total			" << totalDue;
		}
		else {
			if (userInput != 69) {
				if (valInput(userInput) == true) {
					priceDue = priceDue + getPrice(userInput);
					cout << "\n Your current total is: $" << priceDue;
				}
				else {
					cout << "\n The product code you gave wasn't a valid one, please try again.\n";
				}
			}
		}
	}// End while	

	cout << "\n\n";

	double totalGiven = 0;
	cout << " With how much money are you paying?\n Enter amount here: ";
	cin >> totalGiven;

	//Verification that the totalGiven is more than the expense
	if (totalGiven < totalDue) {
		bool enough = false;

		do {
			cout << "\n\n The amount you entered is not enough to cover the expense,\n please enter your given amount again: ";
			cin >> totalGiven;
			if (totalGiven >= totalDue) {
				enough = true;
			}
		} while (!enough);
	}

	// Call function that processes the change
	processChange(totalGiven - totalDue);

	return 0;
}
