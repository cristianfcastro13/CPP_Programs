//Cristian Castro
//Winning Number Analysis Implementation.cpp : This file contains the 'main' function. Program execution begins and ends there.

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

/*This implementation gathers the most frequent numbers of the 'normal' numbers and the most frequent powerball numbers. out of a .csv file
* During the creation of this program, the data base was limited to all the extractions fron the 7th of October 2015 and on.
* This is because at that date there was a change in the range of the extractions, making all of the extractions up to that point unvalid towards research.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <numeric>
#include <algorithm>

using namespace std;

//This method is for debugging purposes, it outputs the frequency of each number.
//The number itself is the index of the array at which the correspondent frequency is stored at.

void tempOutput(int freq[70], int pbfreq[27])
{
	cout << "Numbers: " << "\n";
	for (int i = 0; i < 70; i++) {
		cout << freq[i] << "\n";
	}

	cout << "PowerBall: " << "\n";
	for (int i = 0; i < 27; i++) {
		cout << pbfreq[i] << "\n";
	}
}

/*Sums all of the elements in an array of size 6
* 
* @param array of size 6
* @return sum
*/
int sumArray(int tempNumRow[6]) {
	int sum = 0;
	for (int i = 0; i <= 6; i++) {
		sum = sum + tempNumRow[i];
	}
	return sum;
}

/*Prints to console the top 5 numbers not including the powerball number.
*
* @param array of number frequencies, size of array.
*/
void printTop5(int arr[], int arr_size) {
	int first, second, third, fourth, fifth;
	first = second = third = fourth = fifth = 0;

	for (int i = 0; i < arr_size; i++) {

		if (arr[i] > first)
		{
			fifth = fourth;
			fourth = third;
			third = second;
			second = first;
			first = arr[i];
		}

		else if (arr[i] > second && arr[i] != first)
		{
			fifth = fourth;
			fourth = third;
			third = second;
			second = arr[i];
		}

		else if (arr[i] > third && arr[i] != second) {
			
			fifth = fourth;
			fourth = third;
			third = arr[i];
		}

		else if (arr[i] > fourth && arr[i] != third && arr[i] != second) {

			fifth = fourth;
			fourth = arr[i];
		}

		else if (arr[i] > fifth && arr[i] != fourth && arr[i] != third && arr[i] != second) {
			fifth = arr[i];
		}
			
	}

	cout << "The five most frequent numbers are: ";
	for (int i = 0; i < 70; i++) {

		if (arr[i] == first) {
			cout << i << " ";
		}
		
		if (arr[i] == second) {
			cout << i << " ";
		}

		if (arr[i] == third) {
			cout << i << " ";
		}

		if (arr[i] == fourth) {
			cout << i << " ";
		}

		if (arr[i] == 4) {
			cout << i;
		}

	}
	cout << "\n";
}

/*Prints to console the top 5 powerball numbers.
*
* @param array of number frequencies, size of array.
*/
void printTop5PWBLL(int arr[], int arr_size) {
	int first, second, third, fourth, fifth;
	first = second = third = fourth = fifth = 0;

	for (int i = 0; i < arr_size; i++) {

		if (arr[i] > first)
		{
			fifth = fourth;
			fourth = third;
			third = second;
			second = first;
			first = arr[i];
		}

		else if (arr[i] > second && arr[i] != first)
		{
			fifth = fourth;
			fourth = third;
			third = second;
			second = arr[i];
		}

		else if (arr[i] > third && arr[i] != second) {

			fifth = fourth;
			fourth = third;
			third = arr[i];
		}

		else if (arr[i] > fourth && arr[i] != third && arr[i] != second) {

			fifth = fourth;
			fourth = arr[i];
		}

		else if (arr[i] > fifth && arr[i] != fourth && arr[i] != third && arr[i] != second) {
			fifth = arr[i];
		}

	}

	cout << "The five most frequent powerball numbers are: ";
	for (int i = 0; i < 70; i++) {

		if (arr[i] == first) {
			cout << i << " ";
		}

		if (arr[i] == second) {
			cout << i << " ";
		}

		if (arr[i] == third) {
			cout << i << " ";
		}

		if (arr[i] == fourth) {
			cout << i << " ";
		}

		if (arr[i] == 4) {
			cout << i;
		}

	}
	cout << "\n";
}

int main()
{
	//File in
	fstream in("powerball.csv");

	int freq[70] = { };
	int pbfreq[27] = { };
	vector<string> temp;
	string number;
	string line;
	int counter = 0;

	// If file is not there, "File not found" message .
	if (in.fail()) return (cout << "File not found" << endl) && 0;

	if (in.good()) {
		while (getline(in, line))
		{
			temp.clear(); //Clears the temporary array for new line insertion
			stringstream str(line); //Creates stream from the line

			//Inserts every item of the line in the temporary array
			while (getline(str, number, ','))
				temp.push_back(number);

			int tempNumRow[6] = { };

			//The for loop starts at 4 to ignore "Powerball" and the date numbers; and it ends 6 values later to ignore the random number each row has at the end
			for (int i = 4, j = 0; i < 10; i++, j++) {

				tempNumRow[j] = stoi(temp[i]);

				if (i == 9)
					pbfreq[tempNumRow[j]]++; //Adds 1 to the powerball frequency array in the correspondent place
				else
					freq[tempNumRow[j]]++; //Adds 1 to the number frequency array in the correspondent place

				counter++;
			}
		} //END while getline
	} //END if(in.good())

	//tempOutput(freq, pbfreq);
	
	printTop5(freq, 70);
	printTop5PWBLL(pbfreq, 27);

  return 0;
}//END main
