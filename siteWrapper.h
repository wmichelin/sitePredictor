// Name: Walter Michelin
// Course: CSC 415
// Semester: Spring 2014
// Instructor: Dr. Pulimood
// Exercise : Assignment 3
// Description: This program is designed to keep track of sites, and predict statuses of sites based on nearby data
// Filename: siteWrapper.h
// Last modified on: 4 March 2014
#include <iostream>
#include <cmath>
#include "site.h"

using namespace std;


//wrapper used to store distance value, so that calculation doesn't need to be made every time its accessed
class siteWrapper
{
	public:
		site siteObject;
		double distance;
};