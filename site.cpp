// Name: Walter Michelin
// Course: CSC 415
// Semester: Spring 2014
// Instructor: Dr. Pulimood
// Exercise : Assignment 3
// Description: This program is designed to keep track of sites, and predict statuses of sites based on nearby data
// Filename: site.cpp
// Last modified on: 4 March 2014
#include <iostream>
#include "site.h"
#include <cmath>

using namespace std;

site::site()
{
	siteID = 0;
	siteName = "";
	status = "";
	remediationStatus = "";
	contaminants = "";
	xCoordinate = 0;
	yCoordinate = 0; 
}

site::site(int id, string name, string stat, string rem, string con, int x, int y)
{
	siteID = id;
	siteName = name, 
	status = stat;
	remediationStatus = rem;
	contaminants = con;
	xCoordinate = x;
	yCoordinate = y;
}

int site::getSiteID()
{
	return siteID;
}

string site::getSiteName()
{
	return siteName;
}

string site::getStatus()
{
	return status;
}

string site::getRemediationStatus()
{
	return remediationStatus;
}

string site::getContaminants()
{
	return contaminants;
}

int site::getX()
{
	return xCoordinate;
}

int site::getY()
{
	return yCoordinate;
}

double site::calculateDistance(int x, int y)
{
	//given formula to calculate distance
	return(sqrt(pow((xCoordinate - x), 2) + pow((yCoordinate - y), 2)));
}

double site::calculateDistance(site mySite)
{
	//given formula to calculate distance
	return(sqrt(pow((xCoordinate - mySite.getX()), 2) + pow((yCoordinate - mySite.getY()), 2)));
}


ostream &operator<<(ostream &out, site s)
{
	out << "Site ID: " << s.siteID << endl;
	out << "Site Name: " << s.siteName << endl;
	out << "Site Status: " << s.status << endl;
	out << "Remediation Status: " << s.remediationStatus << endl;
	out << "Contaminants: " << s.contaminants << endl;
	out << "(X, Y) Coordinates: (" << s.xCoordinate << ", " << s.yCoordinate << ")" << endl;

	return out;
}


