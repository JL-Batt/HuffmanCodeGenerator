////////////////////////////////////////////////////////////////////////////////////////////////////////
// HuffmanCodeTree.h - Contains HuffmanCodeTree class, variable and function declarations
//
// Author - Jesse Batt (15004481)
// Last Modified - 01/03/2017
////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "stdafx.h"
#include <iostream>
#include <queue>

#include "BinaryTreeNode.h"
#include "PriorityQueue.h"
#include "BinaryTree.h"

class HuffmanCodeTree
{
private:
	//Nodes
	BinaryTreeNode *rootNode; 
	BinaryTreeNode *nodeA;
	BinaryTreeNode *nodeB;
	BinaryTreeNode *nodeX;


public: 
	HuffmanCodeTree();
	~HuffmanCodeTree();

	void fillPQ();
	void plantTree();
	void printTree(BinaryTreeNode *printNode, int indent);
	string getHuffmanCode(BinaryTreeNode *nodeX, string HuffmanCode);
	BinaryTreeNode* getRootNode();
	BinaryTree *Tree;

	priority_queue <BinaryTreeNode, vector<BinaryTreeNode*>, comparator> *nodeQ;
};