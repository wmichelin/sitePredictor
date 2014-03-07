// Name: Walter Michelin
// Course: CSC 415
// Semester: Spring 2014
// Instructor: Dr. Pulimood
// Exercise : Assignment 3
// Description: This program is designed to keep track of 
// Filename: siteTester.cpp
// Last modified on: 4 March 2014

#include <iostream>
#include "siteList.h"

using namespace std;


int main()
{
	site mySite = site();
	siteList myList = siteList();
	cout << "PLEASE ENTER FILE NAME: " << endl;
	string word;
	getline(cin, word);
	myList.populate(word);

	string check;
	cout << "Would you like to input a new site(y/n)? ";
	getline(cin, check);
	while(check == "y")
	{
		myList.inputSite();
		cout << "Would you like to input a new site(y/n)? ";
		getline(cin, check);

	}

	cout << "Would you like to check a location's status based on coordinates(y/n)? ";
	getline(cin, check);

	int x, y;
	string xstring, ystring;

	while(check == "y")
	{
		cout << "Enter X Coordinate: ";
		getline(cin, xstring);
		cout << "Enter Y Coordinate: ";
		getline(cin, ystring);

		x = atoi(xstring.c_str());
		y = atoi(ystring.c_str());


		cout << myList.checkStatus(x, y);

		cout << "Would you like to check a location's status based on coordinates(y/n)? ";
		getline(cin, check);
	}

	cout << "Program terminating..." << endl;
	cout << "Thank you! " << endl;
	myList.output();

	return 0;
}
