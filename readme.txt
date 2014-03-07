// Name: Walter Michelin
// Course: CSC 415
// Semester: Spring 2014
// Instructor: Dr. Pulimood
// Exercise : Assignment 3
// Description: This program is designed to keep track of sites, and predict statuses of sites based on nearby data
// Filename: site.cpp
// Last modified on: 4 March 2014

Assignment 3 is intended to take in .csv data from a file, parse it, place it into "site objects", 
and then organize this data. It will prompt the user if they would like to enter a new site, 
if they do, the program will handle input and place the site into the created array of sites.

After they are done inputting new sites, the program will ask the user if they wish to search the 
status of a site based on its coordinates, if the exact coordinates do not exist within the array
the program will run an algorithm, and determine the probable status of the site at the entered coordinates,
based on the status of nearby sites. 