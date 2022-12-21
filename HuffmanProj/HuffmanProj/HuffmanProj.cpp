#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "HuffmanCompression.h"
#include "HuffmanBinTree.h"
using namespace std;

int main()
{
	string fileName;
	HuffmanBinTree* tree = new HuffmanBinTree();
	HuffmanCompression huffmanComp(tree);

	cout << "Enter name of file:" << endl;
	getline(cin, fileName);

	huffmanComp.run(fileName);

	delete tree;
	return 0;
}