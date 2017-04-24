////////////////////////////////////////////////////////////////////////////////////////////////////////
// CharFreqv2.cpp : This is a cpp source file that implements functions required for the first
//                  section of the assignment. In summary, the functions here read a given text file,
//                  calculate the frequency of each character in that file, then outputs a table of
//                  each symbol and its frequency to the console window. 
//                  More details on each function can be found in their respective Function banners.
// Author : Jesse Batt
// Last Modified : 01/03/2017
// To-do : Finish banners and comments
////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <utility>

#include "CharFreqv2.h"

using namespace std;

CharFrequency::CharFrequency()
{
	//Dynamic Declaration for vector to store character frequencies
	freqVec = new vector<pair<int, char>>;
}

CharFrequency::~CharFrequency()
{
	/*if (freqVec != NULL)
	{
		freqVec->empty;
	}*/
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//Function: void openFile()
//Parameters: N/A
//Description: This function opens a text file, stores each character of the text file into a char 
//             variable, then reads this text file, building a vector of frequency / symbol pairs
//			   which is then sorted by another function in the code. The use of noskipws is essential
//			   because the frequency of spaces between words also needs to be counted here.
//Author: Jesse Batt (15004481)
//Last Modified: 27/02/2017
////////////////////////////////////////////////////////////////////////////////////////////////////////
void CharFrequency::openFile()
{
	ifstream infile;
	infile.open("ToCompress.txt"); //Open a text file

	char letter;						 //used to store each character of the file
										 //Use string for word frequency (for fun)

	while (infile >> noskipws >> letter) //Reads text file, stores in letter
	{									 //noskipws - do not skip whitespace
		int charsAttempted = 0;			 //Number of characters in vector attempted

		for (int i = 0; i < freqVec->size(); i++) //Go through the whole vector
		{
			if (freqVec->at(i).second != letter)  //If symbol is not already in the vector
			{
				charsAttempted++;				  //increment number of characters attempted
			}
			else
			{
				freqVec->at(i).first++; //The character at this position in the vector 
										//has already been found, so increment its frequency value
			}
		}

		if (charsAttempted == freqVec->size())		  //if the whole vector has been tested 
		{	                                          //(character has been found for the first time)
			freqVec->push_back(make_pair(1, letter)); //Push a new pair of frequency (default 1) and symbol onto the vector
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//Function: void orderFreq()
//Parameters: N/A
//Description: This function uses the vector of frequency/symbol pairs created in the openFile function
//             and orders them in decending order of frequency using the sort function, with the 
//             reverse iterators rbegin and rend to ensure that the vector is sorted in decending order.
//			   This function then simply iterates through the vector, and outputs each symbol with its
//			   frequency to the console window.
//Author: Jesse Batt (15004481)
//Last Modified: 27/02/2017
////////////////////////////////////////////////////////////////////////////////////////////////////////
void CharFrequency::orderFreq()
{
	cout << "Sorted Character Frequencies (Decending Order)" << endl << endl;

	sort(freqVec->rbegin(), freqVec->rend()); //sort in decending order

	for (int i = 0; i < freqVec->size(); i++) //for size of freqVec
	{
		cout << freqVec->at(i).first << ": " << freqVec->at(i).second << endl; //output "(freq):(symbol)"
	}
}
