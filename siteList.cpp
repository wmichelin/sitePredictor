// Name: Walter Michelin
// Course: CSC 415
// Semester: Spring 2014
// Instructor: Dr. Pulimood
// Exercise : Assignment 3
// Description: This program is designed to keep track of sites, and predict statuses of sites based on nearby data
// Filename: siteList.cpp
// Last modified on: 4 March 2014
#include <iostream>
#include <fstream>
#include "siteList.h"
#include <sstream>

using namespace std;


siteList::siteList()
{
	index = 0;
}


void siteList::populate(string filename)
{
	//opens file
	fstream myFile(filename);
	string line = "";
	string IDstring, siteName, status, remediationStatus, contaminants, xString, yString;
	int id, x, y;
	site mySite = site();
	if(myFile.is_open())
	{
		getline(myFile, line, '\r');

		while(getline(myFile, line, '\r'))
		{
			id = 0;
			x = 0;
			y = 0;

			stringstream lineStream(line);
			getline(lineStream, IDstring, ',');
			getline(lineStream, siteName, ',');
			getline(lineStream, status, ',');
			getline(lineStream, remediationStatus, ',');
			getline(lineStream, contaminants, ',');
			getline(lineStream, xString, ',');
			getline(lineStream, yString, ',');

			id = atoi(IDstring.c_str());
			x = atoi(xString.c_str());
			y = atoi(yString.c_str());

			mySite = site(id, siteName, status, remediationStatus, contaminants, x, y);
			siteArray[index] = mySite;
			index++;
		}
	}
	else
	{
		cout << "ERROR OPENING FILE" << endl;
	}

	myFile.close();
}

void siteList::inputSite()
{
	int id, x, y;
	string idstring, name, status, rem, cont, xstring, ystring;

	//prompts user for data to input
	cout << "Enter Site ID: ";
	getline(cin, idstring);
	cout << "Enter Site Name: ";
	getline(cin, name);
	cout << "Enter Site Status: ";
	getline(cin, status);
	cout << "Enter Site Remediation Status: ";
	getline(cin, rem);
	cout << "Enter Site Contaminants: ";
	getline(cin, cont);
	cout << "Enter X Coordinate: ";
	getline(cin, xstring);
	cout << "Enter Y Coordinate: ";
	getline(cin, ystring);

	id = atoi(idstring.c_str());
	x = atoi(xstring.c_str());
	y = atoi(ystring.c_str());


	site mySite = site(id, name, status, rem, cont, x, y);

	if(isUnique(mySite))
	{
		siteArray[index] = mySite;
		index++;
	}
	else
	{
		cout << "Site already exists... not adding " << endl;
	}

}

bool siteList::isUnique(site mySite)
{
	//checks uniqueness
	for(int i = 0; i < index; i++)
	{
		if(siteArray[i].getSiteName() == mySite.getSiteName())
		{
			return false;
		}
	}

	return true;
}

string siteList::checkStatus(int x, int y)
{
	//finds status if it exists, otherwise it predicts it
	for(int i = 0; i < index; i++)
	{
		if(siteArray[i].getX() == x)
		{
			if(siteArray[i].getY() == y)
			{
				return siteArray[i].getStatus();
			}
		}
	}

	return predict(x, y);
}

string siteList::predict(int x, int y)
{
	

	int size = 5;
	int num = 0;
	siteWrapper tempArray[5];
	siteWrapper temp;
	int dep = 0;
	int clear = 0; 
	int pending = 0;
	int redeveloped = 0;
	int available = 0;
	int pendingRed = 0;
	int nominated = 0;
	string status;
	
	//created array of site objects that also contain distance,
	//add shortest distances to this array, then sort so the largest
	// is at index 4 consistently.  
	if(index > size)
	{
		for(int i = 0; i < size; i++)
		{
			tempArray[i].siteObject = siteArray[i];
			tempArray[i].distance = siteArray[i].calculateDistance(x, y);
		}
		sort(tempArray, size);
		for(int i = 5; i < index; i++)
		{
			num = siteArray[i].calculateDistance(x, y);
			if(num <= tempArray[4].distance)
			{
				temp.siteObject = siteArray[i];
				temp.distance = num;
				tempArray[4] = temp;
			}
			sort(tempArray, size);
		}
	}

	//checking array of 5 for most common status, then returning this status
	for(int i = 0; i < size; i++)
	{
		if(tempArray[i].siteObject.getStatus() == "DEP case")
		{
			dep++;
		}
		if(tempArray[i].siteObject.getStatus() == "Clear")
		{
			clear++;
		}
		if(tempArray[i].siteObject.getStatus() == "Pending receipt of waiver")
		{
			pending++;
		}
		if(tempArray[i].siteObject.getStatus() == "Redeveloped")
		{
			redeveloped++;
		}
		if(tempArray[i].siteObject.getStatus() == "Available for redevelopment")
		{
			available++;
		}
		if(tempArray[i].siteObject.getStatus() == "Pending redevelopment")
		{
			pendingRed++;
		}

		if(tempArray[i].siteObject.getStatus() == "Nominated")
		{
			nominated++;
		}
		


	}

	status = "DEP case";
	
	if(clear > dep && clear > pending && clear > redeveloped && clear > available && clear > pendingRed && clear > nominated)
	{
		status = "Clear";
	}
	if(pending > dep && pending > clear && pending > redeveloped && pending > available && pending > pendingRed && pending > nominated)
	{
		status = "Pending reciept of waiver";
	}
	if(redeveloped > dep && redeveloped > clear && redeveloped > pending && redeveloped > available && redeveloped > pendingRed && redeveloped > nominated)
	{
		status = "Redeveloped";
	}
	if(available > dep && available > clear && available > pending && available > redeveloped && available > pendingRed && available > nominated)
	{
		status = "Available for redevelopment";
	}
	if(pendingRed > dep && pendingRed > clear && pendingRed > pending && pendingRed > redeveloped && pendingRed > available && pendingRed > nominated)
	{
		status = "Pending redevelopment";
	}

	if(nominated > dep && nominated > clear && nominated > pending && nominated > redeveloped && nominated > available && nominated > pendingRed)
	{
		status = "Nominated";
	}






	string tempString = status;
	cout << "Site not found in array" << endl;
	status = "Predicting Site Status Based on Coordinates...\n";
	status += tempString;
	status += "\n";	
	return status;
}

void siteList::sort(siteWrapper tempArray[], int size)
{
	siteWrapper temp;
	bool swapped = true;
	for(int i = 0; i < size && swapped; i++)
	{
		swapped = false;
		for(int i = 0; i < size - 1; i++)
		{
			if(tempArray[i].distance > tempArray[i+1].distance)
			{
				temp = tempArray[i];
				tempArray[i] = tempArray[i + 1];
				tempArray[i+1] = temp;
				swapped = true;
			}
		}
	}
}

void siteList::output()
{
	ofstream myFile;
	myFile.open("output.csv");

	myFile << "Site Id,Site Name,Status,Remediation Status,Type of Contamination,X Coord,Y Coord\r";

	for(int i = 0; i < index; i++)
	{
		myFile << siteArray[i].getSiteID() << ",";
		myFile << siteArray[i].getSiteName() << ",";
		myFile << siteArray[i].getStatus() << ",";
		myFile << siteArray[i].getRemediationStatus() << ",";
		myFile << siteArray[i].getContaminants() << ",";
		myFile << siteArray[i].getX() << ",";
		myFile << siteArray[i].getY();
		myFile << "\r";
	}

	cout << "Output written to output.csv" << endl;
	myFile.close();
}

ostream &operator<<(ostream &out, siteList s)
{
	for(int i = 0; i < s.index; i++)
	{
		out << s.siteArray[i] << endl;
	}

	return out;
}
