////////////////////////////////////////////////////////////////////////////////////////////////////////
// BinaryTree.cpp : This is a cpp source file that implements functions required for the second
//                  section of the assignment. The functions in this file are used to merge any 2 
//                  instances of BinaryTreeNode, print a visualisation of a Binary Tree to the console
//                  window, and to set a node as the Root Node. More details about each function can
//                  be found in their respective function banners.
// Author : Jesse Batt
// Last Modified : 28/02/2017
// To-do : Finish banners and comments
////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <map>

#include "BinaryTree.h"
#include "BinaryTreeNode.h"

using namespace std;

//BinaryTree Default Constructor
BinaryTree::BinaryTree()
{

}

//BinaryTree Destructor 
BinaryTree::~BinaryTree()
{
	rootNode = NULL; //Erase the contents of the Binary Tree by removing the root node = no pointers to other nodes (might not work)
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//Function: BinaryTreeNode Merge()
//Parameters: BinaryTreeNode *left, BinaryTreeNode *right (Two generic nodes to be merged)
//Description: This function uses two generic instances of BinaryTreeNode, creates a new BinaryTreeNode 
//             which contains the combined frequency of the 2 nodes, with left and right pointers that
//             point at the two geenric nodes respectively. This function then returns the new Node.
//             This is used in the program to merge any 2 instances of BinaryTreeNode by calling this
//             function and manually passing in 2 instances of BinaryTreeNode.
//
//Author: Jesse Batt (15004481)
//Last Modified: 12/02/2017
////////////////////////////////////////////////////////////////////////////////////////////////////////
BinaryTreeNode *BinaryTree::Merge(BinaryTreeNode *left, BinaryTreeNode *right)
{
	int combinedFreq = left->freq + right->freq; //Merge frequencies of left and right nodes
	BinaryTreeNode *newNode = new BinaryTreeNode{ ' ', combinedFreq, left, right }; //New Node properties
	return newNode;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//Function: void printTree()
//Parameters: BinaryTreeNode *printNode, int indent (Node to print and integer value for indentation).
//Description: This function is used to display a readable representation of the Binary Tree to the
//			   console window, representing each node as the Frequency of a symbol. The function's if 
//			   statements check whether a given node has a leaf node to its left and right, printing 
//             the frequency of the left/right node if so. The indent value is used to manage the 
//             whitespace between each node, so the Tree is more readable.
//			   
//Author: Jesse Batt (15004481) (Derived from a solution on Stack Overflow)
//Last Modified: 27/02/2017
////////////////////////////////////////////////////////////////////////////////////////////////////////
void BinaryTree::printTree(BinaryTreeNode *printNode, int indent = 0)
{
	if (printNode->left)						 //if node has a left leaf
	{
		printTree(printNode->left, indent + 4);  //Print left node, indent by 4 spaces
	}
	if (printNode->right)						 //if node has right leaf
	{
		printTree(printNode->right, indent + 4); //Print right node, indent by 4 spaces
	}
	if (indent)
	{
		cout << setw(indent) << ' ';		 //setw = set field width
	}										 //indent = empty char, makes Tree more readable
	cout << printNode->freq << "\n";			 //print freq of node to console	
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//Function: BinaryTreeNode setRootNode()
//Parameters: BinaryTreeNode *newRoot
//Description: This function is simply used to set and return the Root Node for use in code. 
//
//Author: Jesse Batt (15004481)
//Last Modified: 27/02/2017
////////////////////////////////////////////////////////////////////////////////////////////////////////
BinaryTreeNode *BinaryTree::setRootNode(BinaryTreeNode *newRoot)
{
	rootNode = newRoot;
	return newRoot;
}
