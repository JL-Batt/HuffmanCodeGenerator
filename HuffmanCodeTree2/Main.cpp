////////////////////////////////////////////////////////////////////////////////////////////////////////
// C++ Development - Small Programming Project: Task 5
// Main.cpp : This is a cpp source file that brings together the required
//			  functionality for this element of the project. In the main function,
//			  I have created an object of my HuffmanTreeCode class, which calls
//			  my fillPQ, plantTree and printTree functions. This is then extended with
//			  getHuffmanCode, which creates and displays the Huffman Codes for each
//            character/symbol within the text file.
// Authors : Jesse Batt (15004481)
// Last Modified : 01/03/2017
// To-do : 
////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include "HuffmanCodeTree.h"

int main()
{
	HuffmanCodeTree *HCT = new HuffmanCodeTree; //Object of HuffmanCodeTree
	HCT->fillPQ(); //Populate Priority Queue with Nodes
	HCT->plantTree(); // Arrange Nodes, create leaf nodes from base nodes

	cout << "Rough Visualisation of Binary Tree: " << endl << endl;
	cout << "Nodes are represented by their frequencies, with the highest frequency representing the Root Node." << endl << endl;
	HCT->printTree(HCT->getRootNode(), 0); // Print Binary Tree to console window

	cout << endl << "Huffman Codes for each character in the text file: " << endl << endl;
	HCT->getHuffmanCode(HCT->getRootNode(), ""); // Calculate and display Huffman Codes for each character in text file
	system("pause"); // Pause console window 
    return 0;
}

