#pragma once
#include <iostream>
#include <queue>
#include <list>
#include <string>
#include <cmath>
using namespace std;

// Alphabet size (# of symbols) 
#define ALPHABET_SIZE (26) 

// Converts key current character into index 
// use only 'a' through 'z' and lower case 
#define CHAR_TO_INDEX(c) ((int)c - (int)'a') 


class compareNode;
class HuffmanNode
{
public:
	string str;
	int frequency;
	HuffmanNode* left;
	HuffmanNode* right;

	HuffmanNode()
	{
		str = "";
		frequency = 0;
		left = nullptr;
		right = nullptr;
	}
	HuffmanNode(string str, int f) {
		this->str = str;
		this->frequency = f;
		right = nullptr;
		left = nullptr;
	}

	HuffmanNode(string str, int f, HuffmanNode* const& r, HuffmanNode* const& l) {
		this->str = str;
		this->frequency = f;
		right = r;
		left = l;
	}

	friend compareNode;
};

class compareNode
{
public:
	bool operator()(HuffmanNode* const& n1, HuffmanNode* const& n2)
	{
		return n1->frequency > n2->frequency;
	}
};

class HuffmanTree
{


	HuffmanNode* root;
	priority_queue<HuffmanNode*, vector<HuffmanNode*>, compareNode> pQueue;
	int numOfCherInText;
	string treeCode;
public:
	HuffmanTree(string word);
	string encodeTree(HuffmanNode* root);
	string encodeTree(HuffmanNode* root,string);
	void encodeLetters(HuffmanNode* root) { encodeLetters(root,""); }
	void encodeLetters(HuffmanNode* root, string);
	void decode(string sourceFileName, string destFileName);
	int buildFrequencyTable(string text);
	/*void buildTree(int* frequencyTable);
	void buildTree(int n, string letters, string tree);
	void buildCodedTabe();
	void encode(char letter, string* codedTable);*/
	~HuffmanTree()
	{
		delete root;
	}
};

