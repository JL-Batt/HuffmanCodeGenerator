////////////////////////////////////////////////////////////////////////////////////////////////////////
// BinaryTree.h - Header file containing BinaryTree class, variables and function declarations.
//
// Author - Jesse Batt (15004481)
// Last Modified - 28/02/2017
////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "stdafx.h"
#include "BinaryTreeNode.h"
using namespace std;

class BinaryTree
{
private:
	BinaryTreeNode *rootNode; // Member to represent Root Node


public:
	BinaryTree(); 
	~BinaryTree();

	//PrintTree - Print Binary Tree to console window. 
	void printTree(BinaryTreeNode * printNode, int indent);

	//SetRootNode - Set the root node to be a specific instance of BinaryTreeNode.	
	BinaryTreeNode * setRootNode(BinaryTreeNode *nodeX);

	//Merge - Takes 2 nodes, makes a new one pointing to the previous 2.
	BinaryTreeNode *Merge(BinaryTreeNode *left, BinaryTreeNode *right);	

};
