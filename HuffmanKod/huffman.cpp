#include <iostream>
#include <queue>
#include <list>
#include <string>
#include <cmath>
#include "huffman.h"
#include <unordered_map>
using namespace std;

int frequencyTable[26] = { 0 };

string codedTable[26] = { "" };

void HuffmanTree::encodeLetters(HuffmanNode* root, string str)
{
	//if not a leaf 
	if (root->left != nullptr)
	{
		encodeLetters(root->left, str += '0');
		encodeLetters(root->right, str += '1');
	}
	//If a leaf
	else
	{
		codedTable[CHAR_TO_INDEX(root->str[0])] = str;
	}
}

string HuffmanTree::encodeTree(HuffmanNode* root)
{
	string codeTree = "";
	return encodeTree(root, codeTree);
}
string HuffmanTree::encodeTree(HuffmanNode * root, string code)
{
	if (root == nullptr)
		return "";
	//If there is spilt - 
	if (root->left != nullptr)
	{
		return encodeTree(root->right, encodeTree(root->left, code += '0'));
	}
	else //If got to leaf
		return "1";
}
	

/// <summary>
/// update the FrequencyTable
/// </summary>
/// <param name="text"></param>
/// <returns>The amount of chater in the text</returns>
int HuffmanTree::buildFrequencyTable(string text)
{
	int numOfCherInText = 0;
	for (int i = 0; i < text.size(); i++)
	{
		//add 1 to coounter if this is the first time
		if (frequencyTable[CHAR_TO_INDEX(text[i])] == 0) numOfCherInText++;
		frequencyTable[CHAR_TO_INDEX(text[i])]++;
	}
	return numOfCherInText; 
}
HuffmanTree::HuffmanTree(string word)
{
	HuffmanNode* first;
	string temp = "";
	numOfCherInText = buildFrequencyTable(word);
	for (int i = 0; i < 26; i++)
	{
		if (frequencyTable[i] > 0)
		{
			//Push to the queue 
			temp = ('a' + i);
			pQueue.push(new HuffmanNode(temp, frequencyTable[i]));
		}
	}
	

	//Build the tree
	while (!pQueue.empty()) {
		first = pQueue.top();
		pQueue.pop();
		if (!pQueue.empty())
		{
			HuffmanNode* secound = pQueue.top();
			pQueue.pop();
			pQueue.push(new HuffmanNode(first->str + secound->str, first->frequency + secound->frequency, first, secound));
			secound = nullptr;
		}
	}

	treeCode = encodeTree(first);
	//prepare the code table

	
}