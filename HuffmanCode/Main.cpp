#include "HoffmanNode.h"
#include <iostream>
#include <string>


bool validTree(int num, string strct)
{
	int ones = 0;
	for (auto str : strct)
	{
		if (str == '1') ones++;
	}
	return ones == num;
}
int main()
{
	HoffmanNode tree;
	string text, code, strct, letters;
	int num, choice;
	cout << "enter 1 to encode a text\n" << "enter 2 to decode a text\n" << "enter 3 to exit\n";
	do
	{
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "enter the original text\n";
			cin >> text;
			cout << "The encoded string is\n";
			tree.textToCode(text);
			break;
		case 2:
			cout << "enter n ";
			cin >> num;
			cout << "\n enter the letters ";
			cin >> letters;
			cout << "\n enter the encoded structure ";
			cin >> strct;
			if (!validTree(num, strct)) 
			{
				cout << "ERROR\n";
				break;
			}
			cout << "\n enter the encoded text ";
			cin >> code;
			cout << "\n The decoded string is ";
			tree.codeToText(num, letters, strct, code);
			cout << endl;
			break;
		case 3:
			break;
		default:
			break;
		}
	}
	while (choice!= 3);
	return 0;
}