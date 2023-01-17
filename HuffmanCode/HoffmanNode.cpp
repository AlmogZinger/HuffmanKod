#include "HoffmanNode.h"
#include <iostream>
#include <queue>

const int ALEFHBETHSIZE = 26;

HoffmanNode* HoffmanNode::buildTreeFromStr(string str)
{

    priority_queue<HoffmanNode*, vector<HoffmanNode*>, compaireNodes> pQueue;
    int* freqTab;
	buildFreqTable(str, freqTab);
    for (int i = 0; i < ALEFHBETHSIZE; i++)
    {
	    if(freqTab[i] > 0)
	    { 
            HoffmanNode* temp = new HoffmanNode(freqTab[i], (char) i+ 'a');
            pQueue.push(temp);
	    }
    }
    
    HoffmanNode* first;
    do
    {
        first = pQueue.top();
        pQueue.pop();
        if (!pQueue.empty())
        {
            HoffmanNode* second = pQueue.top();
            pQueue.pop();
            HoffmanNode* temp = new HoffmanNode(first->frequency + second->frequency,' ', first, second);
            pQueue.push(temp);
        }
    }
    while (!pQueue.empty());

    return first;
}

void HoffmanNode::treeFromCode(HoffmanNode*& node, string& str)
{
    if (str.front() == '1' || str.empty()) return;
    node->leftSon = new HoffmanNode();
    node->rightSon = new HoffmanNode();
    str = str.substr(1);
    treeFromCode(node->leftSon, str);
    str = str.substr(1);
    treeFromCode(node->rightSon, str);
}

HoffmanNode* HoffmanNode::buildTreeFromCode(string code)
{
    HoffmanNode* source = new HoffmanNode();
    treeFromCode(source, code);
    return source;
}

void HoffmanNode::buildFreqTable(string str, int*& freq)
{
    freq = new int [ALEFHBETHSIZE]{ 0 };
    do
    {
        freq[(int)(str.front() - 'a')]++;
        str = str.substr(1);
    } while (!str.empty());
}

string HoffmanNode::lettersByFreq(HoffmanNode* source)
{
    string theStr;
    inOrderTree(source, theStr);
    return theStr;
}

void HoffmanNode::inOrderTree(HoffmanNode* node, string& str)
{
    if(node->leftSon == nullptr)
    {
        str += node->nodeValue;
        return;
    }
    inOrderTree(node->leftSon, str);
    inOrderTree(node->rightSon, str);
}

void HoffmanNode::insertValues(HoffmanNode* source, string& str)
{
    if (source->leftSon == nullptr)
    {
        source->nodeValue = str.front();
        str = str.substr(1);
        return;
    }
    insertValues(source->leftSon, str);
    insertValues(source->rightSon, str);
}

void HoffmanNode::buildCodeTable(HoffmanNode* source, string code, string*& codeTab)
{
    if(source->leftSon == nullptr)
    {
        codeTab[(source->nodeValue - 'a')] = code;
        return;
    }
    buildCodeTable(source->leftSon, code + "0", codeTab);
    buildCodeTable(source->rightSon, code + "1", codeTab);
}

string HoffmanNode::codeToText(string str, HoffmanNode* source)
{
    string theText;
    while (!str.empty())
    {
        encode(str, theText, source);
    }
    return theText;
}

void HoffmanNode::encode(string& code, string& text, HoffmanNode* node)
{
    if(node->leftSon == nullptr)
    {
        text += node->nodeValue;
        return;
    }
    if(code.front() == '0')
    {
        code = code.substr(1);
        encode(code, text, node->leftSon);
    }
    else if(code.front() == '1')
    {
        code = code.substr(1);
        encode(code, text, node->rightSon);
    }
}

void HoffmanNode::treeStructure(HoffmanNode* node, string& strct)
{
    if(node->rightSon == nullptr)
    {
        strct += '1';
        return;
    }
    strct += '0';
    treeStructure(node->leftSon, strct);
    treeStructure(node->rightSon, strct);
}
void HoffmanNode::printTree(HoffmanNode* tree)
{
    if (tree == nullptr)
        return;
    if (tree->leftSon == nullptr)
    {
        cout << tree->nodeValue;
        return;
    }
    printTree(tree->leftSon);
    printTree(tree->rightSon);
}
void HoffmanNode::textToCode(string str)
{
    int* freqTab;
    buildFreqTable(str, freqTab);
    int num = 0;
    for (int i = 0; i < ALEFHBETHSIZE; i++)
    {
        if (freqTab[i] > 0) num++;
    }
    cout << num << endl;

    priority_queue<HoffmanNode*, vector<HoffmanNode*>, compaireNodes> pQueue;
    for (int i = 0; i < ALEFHBETHSIZE; i++)
    {
        if (freqTab[i] > 0)
        {
             
            HoffmanNode* temp = new HoffmanNode(freqTab[i], (char)('a' + i));
            pQueue.push(temp);
        }
    }
  /*  while (!pQueue.empty())
    {
        cout << pQueue.top()->nodeValue;
        pQueue.pop();
    }
    cout << endl;*/

    HoffmanNode* tree = buildTreeFromStr(str);
    cout << tree->nodeValue << endl;
    printTree(tree);
    cout << endl;
    string strct = "";
    treeStructure(tree, strct);
    cout << strct << endl;

    string code = "";
    string* codeTable = new string[ALEFHBETHSIZE];
    buildCodeTable(tree, code, codeTable);

    for (auto letter : str)
    {
        cout << codeTable[letter - 'a'];
    }
    cout << endl;
}

void HoffmanNode::codeToText(int num, string letters, string strct, string code)
{
    HoffmanNode* tree = buildTreeFromCode(strct);
    insertValues(tree, letters);
    string theText = codeToText(code, tree);
    cout << theText;
}


