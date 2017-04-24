////////////////////////////////////////////////////////////////////////////////////////////////////////
// CharFreqv2.h - Header file containing CharFrequency class, variables and function declarations.
//
// Author - Jesse Batt (15004481)
// Last Modified - 28/02/2017
////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class CharFrequency
{
public:
	CharFrequency();
	~CharFrequency();

	void openFile();
	void orderFreq();

	vector<pair<int, char>> *freqVec;

private:
};

