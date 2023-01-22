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

#include <iostream>

 /**
  * Generates and returns a random number between 1 and 6.
  *
  * @return Random number between 1 and 6.
  */
int hatsuRollDice() {
    int diceRoll;
    diceRoll = rand() % 6 + 1;
    return diceRoll;
}

/**
 * Sums two integer values in input.
 *
 * @param Values to sum.
 * @return Sum of values.
 */
int hatsuAdd(int a, int b) {
    int sum = a + b;
    return sum;
}

/**
 * Checks for double 1's or double 6's
 * and prints correspondent special message.
 *
 * @param Variables whose values are compared.
 */
void hatsuCheck(int die1, int die2) {
    if (die1 == 6 && die2 == 6) {
        std::cout << "Boxcars!\n\n";
    }
    if (die1 == 1 && die2 == 1) {
        std::cout << "Snake eyes!\n\n";
    }
}

/**
 * Verifies if the user input is either 'y' or 'n'.
 * If neither, it asks for correct input until such is given.
 *
 * @param Input to verify.
 * @return Verification ['y' or 'n'].
 */
std::string hatsuInputVerification(std::string userInput) {
    std::string verification = "";

    if (userInput == "y" || userInput == "n") {
        return userInput;
    }
    else {
        do {
            std::cout << "\nInvalid input. Please enter either 'y' or 'n' (lowercase): ";
            std::cin >> verification;
            if (verification == "y" || verification == "n") {
                return verification;
            }
        } while (verification != "y" && verification != "n");
    }
}


int main() {
    srand((int)time(NULL));

    std::string response = "";
    int die1 = 0;
    int die2 = 0;

    std::cout << "Dice Roller\n\n";
    std::cout << "Roll the Dice?? (y/n):";

    std::cin >> response;
    response = hatsuInputVerification(response);

    if (response == "y") {
        do {
            die1 = hatsuRollDice();
            die2 = hatsuRollDice();
            std::cout << "\nDie 1: " << die1;
            std::cout << "\nDie 1: " << die2;

            std::cout << "\nTotal: " << hatsuAdd(die1, die2) << "\n";
            hatsuCheck(die1, die2);

            std::cout << "\nRoll again? (y/n): ";
            std::cin >> response;
            response = hatsuInputVerification(response);
        } while (response == "y");
    }

    if (response == "n") {
        std::cout << "\nNo dices rolled.\n\n\n\n";
    }

}   // END main
