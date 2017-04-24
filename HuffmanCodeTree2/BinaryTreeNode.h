////////////////////////////////////////////////////////////////////////////////////////////////////////
// BinaryTreeNode.h - Header file containing struct declaration for instances of BinaryTreeNode.
//
// Author - Jesse Batt (15004481)
// Last Modified - 05/02/2017
////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "stdafx.h"
#include <iostream>
using namespace std;

struct BinaryTreeNode //Struct declaration for nodes to be reused
{
	char symbol; //Symbol
	int freq; // Frequency of symbol in text
	BinaryTreeNode *left; // Pointer for left branch
	BinaryTreeNode *right; 	// Pointer for right branch
};