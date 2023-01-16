#pragma once
#include <string>

using namespace std;

class compaireNodes;

class HoffmanNode
{
private:
	int frequency;
	char nodeValue;
	HoffmanNode* leftSon;
	HoffmanNode* rightSon;
public:
	HoffmanNode(int freq = 0, char value = ' ', HoffmanNode* left = nullptr, HoffmanNode* right = nullptr)
	{
		frequency = freq; nodeValue = value; leftSon = left; rightSon = right;
	}

	friend compaireNodes;

	HoffmanNode* buildTreeFromStr(string str);
	HoffmanNode* buildTreeFromCode(string code);
	void treeFromCode(HoffmanNode*& node, string& str);
	void buildFreqTable(string str, int*& freq);
	string lettersByFreq(HoffmanNode* source);
	void inOrderTree(HoffmanNode* node, string& str);
	void insertValues(HoffmanNode* source, string& str);
	void buildCodeTable(HoffmanNode* source,string code, string*& codeTab);
	string codeToText(string str, HoffmanNode* source);
	void encode(string& code, string& text, HoffmanNode* node);
	void treeStructure(HoffmanNode* node, string& strct);
	void textToCode(string str);
	void codeToText(int num, string letters, string strct, string code);
};

class compaireNodes
{

public:
	bool operator()(HoffmanNode* const& n1, HoffmanNode* const& n2)
	{
		return n1->frequency > n2->frequency;
	}

};

