////////////////////////////////////////////////////////////////////////////////////////////////////////
// HuffmanCodeTree.cpp : This is a cpp source file that implements functions required for this
//						 section of the assignment. More details on each function can be found
//						 in their respective Function banners.
// Author : Jesse Batt
// Last Modified : 01/03/2017
// To-do : Finish banners and comments
////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <queue>

#include "BinaryTreeNode.h"
#include "CharFreqv2.h"
#include "PriorityQueue.h"
#include "HuffmanCodeTree.h"

using namespace std;

//Default Constructor
HuffmanCodeTree::HuffmanCodeTree()
{
	//Dynamic declaration of nodeQ
	nodeQ = new priority_queue <BinaryTreeNode, vector<BinaryTreeNode*>, comparator>;
}

//Destructor - need to delete things here...
HuffmanCodeTree::~HuffmanCodeTree()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//Function: void fillPQ()
//Parameters: N/A
//Description: This function opens a text file and fills a vector with characters and their frequencies
//			   using the CharFrequency class. fillPQ then reads into this vector and for each location,
//             it creates a node, and populates the symbol and frequency, then pushes the node onto
//			   a Priority Queue. This means every character in the text file will have it's own node.
//Author: Jesse Batt (15004481)
//Last Modified: 01/03/2017
////////////////////////////////////////////////////////////////////////////////////////////////////////
void HuffmanCodeTree::fillPQ()
{
	CharFrequency CharFreq; //Object of CharFrequency class
	CharFreq.openFile();	//Open ToCompress.txt and store character frequencies in a vector of pairs
	

	for (int i = 0; i < CharFreq.freqVec->size(); i++) //for size of freqVec
	{
		//Make new node for each location in vector
		BinaryTreeNode *newNode = new BinaryTreeNode;
		newNode->symbol = CharFreq.freqVec->at(i).second;
		newNode->freq = CharFreq.freqVec->at(i).first;
		newNode->left = NULL;
		newNode->right = NULL;
		nodeQ->push(newNode); 		//Push this new node onto the PQ
	}

	//This loop is used to print the contents of the PQ for debugging purposes (checking nodes are on PQ)
	//cout << "Symbols and Frequencies (Descending Order): " << endl << endl;
	//While the PQ has contents, print S / F of node at top of PQ then pop it off the PQ (this will cycle through PQ)
	//while (!nodeQ->empty())
	//{
	//	cout << "Symbol: " << nodeQ->top()->symbol << ", " << "Frequency: " << nodeQ->top()->freq << endl;
	//	nodeQ->pop();
	//}
	//cout << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//Function: void plantTree()
//Parameters: N/A
//Description: This function is used to pop off the two nodes at the top of the Priority Queue 
//			   (nodeA and nodeB), then populates a new leaf node (nodeX) with the merged frequency of
//				the two nodes, and assigns the left and right pointer to point to nodeA and nodeB
//				respectively. plantTree utilises temporary instances of BinaryTreeNode to do this and 
//              only begins this process when there is more than 1 node in the Priority Queue. 
//
//Author: Jesse Batt (15004481)
//Last Modified: 01/03/2017
////////////////////////////////////////////////////////////////////////////////////////////////////////
void HuffmanCodeTree::plantTree()
{
	while (nodeQ->size() > 1) //While PQ contains more than 1 node
	{
		//Temporary Nodes
		nodeA = new BinaryTreeNode; 
		nodeB = new BinaryTreeNode;
		nodeX = new BinaryTreeNode;

		//Pop nodes A and B from top of PQ
		nodeA = nodeQ->top();
		nodeQ->pop();
		nodeB = nodeQ->top();
		nodeQ->pop();

		//nodeX properties
		nodeX->symbol = NULL;						 //Symbol doesn't need to be assigned
		nodeX->freq = (nodeA->freq) + (nodeB->freq); //Combined frequency of nodeA and nodeB
		nodeX->left = nodeA;						 //left branch points to nodeA
		nodeX->right = nodeB;						 //right branch points to nodeB

		//Push nodeX (leaf of A and B) onto PQ
		nodeQ->push(nodeX);	
	}

	//Pop Root Node from top of PQ
	rootNode = new BinaryTreeNode;
	rootNode = nodeQ->top();
	nodeQ->pop();
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
//Last Modified: 01/03/2017
////////////////////////////////////////////////////////////////////////////////////////////////////////
void HuffmanCodeTree::printTree(BinaryTreeNode *printNode, int indent = 0)
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
//Function: string getHuffmanCode()
//Parameters: BinaryTreeNode *nodeX, string HuffmanCode (Node to check and string to store Huffman Code).
//Description: This function is used to check a given node's left and right branches, and create the 
//	           Huffman Code for each node (symbol). When moving through a Huffman Code Tree, going from
//			   the Root Node to each initial leaf node, moving along the left branch is represented as a
//             '0' in the Huffman Code, with the right branch being a '1'. So in this function, if a Node 
//             has a left branch node, then add a 0 to the HuffmanCode string, same for right branch but
//             add a 1 to the string. If the node has no branches (ie. it's one of the initial nodes),
//             then the function prints the Symbol, Character Frequency and full Huffman Code for that
//             Node (symbol) to the console window.
//			   
//Author: Jesse Batt (15004481)
//Last Modified: 01/03/2017
////////////////////////////////////////////////////////////////////////////////////////////////////////
string HuffmanCodeTree::getHuffmanCode(BinaryTreeNode *nodeX, string HuffmanCode)
{
	if (nodeX->left != NULL)
	{
		getHuffmanCode(nodeX->left, (HuffmanCode + '0'));	//Add a 0 to the Huffman Code for this Node
	}
	if (nodeX->right != NULL)								//if Node has right branch
	{
		getHuffmanCode(nodeX->right, (HuffmanCode + '1'));	//Add a 1 to the Huffman Code for this Node
	}

	if (nodeX->left == NULL && nodeX->right == NULL)		//if node has no leaf nodes (ie - node is at the end of tree)
	{
		//Readable values. Output format - "Symbol: x || Frequency: xx || Huffman Code: xxxx".
		cout << "Symbol: " << nodeX->symbol << " || " << "Frequency: " << nodeX->freq << " || " << "Huffman Code: " << HuffmanCode << endl;
	}

	return HuffmanCode;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//Function: BinaryTreeNode getRootNode()
//Parameters: N/A
//Description: This function is simply used to return/get the Root Node for use in code. 
//
//Author: Jesse Batt (15004481)
//Last Modified: 01/03/2017
////////////////////////////////////////////////////////////////////////////////////////////////////////
BinaryTreeNode* HuffmanCodeTree::getRootNode()
{
	return rootNode;
}