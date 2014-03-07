// Name: Walter Michelin
// Course: CSC 415
// Semester: Spring 2014
// Instructor: Dr. Pulimood
// Exercise : Assignment 3
// Description: This program is designed to keep track of sites, and predict statuses of sites based on nearby data
// Filename: site.h
// Last modified on: 4 March 2014
#include <iostream>
#include <cmath>

using namespace std;

class site
{
	private:
		int siteID;
		string siteName;
		string status;
		string remediationStatus;
		string contaminants;
		int xCoordinate;
		int yCoordinate;

	public:
		//default constructor
		site();
		//constructor with inputs
		site(int, string, string, string, string, int, int);
		//getters
		int getSiteID();
		string getSiteName();
		string getStatus();
		string getRemediationStatus();
		string getContaminants();
		int getX();
		int getY();
		//used to calculate distance based on location, or it can also take a site and pull that sites location
		double calculateDistance(int, int);
		double calculateDistance(site);
		
		//"to string"
		friend ostream &operator<<(ostream&, site);

};