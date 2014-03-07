// Name: Walter Michelin
// Course: CSC 415
// Semester: Spring 2014
// Instructor: Dr. Pulimood
// Exercise : Assignment 3
// Description: This program is designed to keep track of sites, and predict statuses of sites based on nearby data
// Filename: siteList.h
// Last modified on: 4 March 2014
#include <iostream>
#include <cmath>
#include "siteWrapper.h"

using namespace std;
class siteList
{
	
	private:
		site siteArray[600];
		int index;

	public:
		//creates an empty array of 600 with an "index" or size of 0
		siteList();
		//populates the array with data from specified file name
		void populate(string);
		//checks if a new entered site is already in the array
		bool isUnique(site);
		//prompts the user for info of a site to enter into the array, if its not already there
		void inputSite();
		//checks the status of a site based on location, if it isnt found it calls predict with same coordinates
		string checkStatus(int, int);
		//sorts an array of sites based on distance attribute
		void sort(siteWrapper[], int);
		//outputs to a file
		void output();
		//determines probable status based on surrounding locations
		string predict(int, int);
		//"to string"
		friend ostream &operator<<(ostream&, siteList);

};