//MAIN

/* 
 * This file is part of Cristian Castro's submissions.
 * Copyright 2022 (c) Cristian Castro.
 *
 * Developed for the ITI-3310 Programming in C++ course.
 * This code includes software developed by Cristian Castro.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * <https://www.gnu.org/licenses/>
 */

#include "Castro.h"
#include <iostream>
#include <cmath>

/// Prints the Menu to console.
void printMenu() {
	std::cout << "\nConversions Menu:\n";
	std::cout << "a. Feet to Meters\n";
	std::cout << "b. Meters to Feet\n";
	std::cout << "Select a conversion (a/b): ";
}

/**
* Checks the result and pairs it with the appropriate word.
* 
* @param result, measurement type
* @return Correspondent word [meter/meters, foot/feet]
*/
std::string checkSingular(int result, std::string resultType) {

	if (resultType == "m") {
		if (result == 1) {
			return " meter";
		}
		else {
			return " meters";
		}
	}
	
	if (resultType == "ft") {
		if (result == 1) {
			return " foot";
		}
		else {
			return " feet";
		}
	}
}

int main() {

	std::string yesNo;
	double userInput = 0;

	std::cout << "Feet and Meters Converter\n";

	do {

		double result = 0;
		printMenu();
		std::cin >> yesNo;

		if (yesNo == "a") {
			std::cout << "\nEnter feet: ";
			std::cin >> userInput;

			result = Castro::feetToMeter(userInput);
			result = floor(result * 100) / 100;	// Rounding to two decimals using floor() function and a combination of multiplication and division.

			std::cout << result << checkSingular(result, "m");
		}
		else {
			std::cout << "\nEnter meters: ";
			std::cin >> userInput;

			result = Castro::meterToFeet(userInput);
			result = floor(result * 100) / 100;	// Rounding to two decimals using floor() function and a combination of multiplication and division.

			std::cout << result << checkSingular(result, "ft");
		}

		std::cout << "\n\nContinue? (y/n): ";
		std::cin >> yesNo;

	} while (yesNo == "y");

	std::cout << "\nThanks, bye!\n\n";

} //END main



