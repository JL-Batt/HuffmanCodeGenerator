////////////////////////////////////////////////////////////////////////////////////////////////////////
// PriorityQueue.h - Header file containing PriorityQueue class, variables and function declarations.
//					 This header file also contains the struct declaration for a Comparator, which is
//                   used to compare the frequency values of any 2 instances of BinaryTreeNode and is
//                   implemented within the PriorityQueue for sorting purposes.
// Author - Jesse Batt (15004481)
// Last Modified - 28/02/2017
////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once
#include "stdafx.h"
#include <iostream>
#include <queue>

#include "BinaryTreeNode.h"

using namespace std;

//Comparator: This is used to compare the frequency of two nodes.
//			  The comparator is implemented within the Priority Queue
struct comparator
{
public:
	bool operator()(BinaryTreeNode* nodeA, BinaryTreeNode* nodeB)
	{
		return (nodeA->freq) > (nodeB->freq); //Returns 1 if A>B, returns 0 if A<B
	}
};

class PriorityQueue
{
private:

public:
	PriorityQueue(); //Default constructor
	~PriorityQueue(); //Deconstructor
	
	priority_queue <BinaryTreeNode, vector<BinaryTreeNode*>, comparator> *nodeQ;
};
