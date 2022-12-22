#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "HuffmanCompression.h"
#include "HuffmanBinTree.h"
#include "HuffmanDecompression.h"
using namespace std;

int main()
{
	string fileName, command;
	HuffmanBinTree* tree = new HuffmanBinTree();
	HuffmanCompression huffmanComp(tree);
	HuffmanDecompression huffmanDecomp;
	cout << "Enter <comp> or <decomp> to run compression or decompression algorithm" << endl;
	cin >> command;

	if (command.compare("comp") == 0) {
		cout << "Enter name of file:" << endl;
		cin >> fileName;

		huffmanComp.run(fileName);
	}
	else if (command.compare("decomp") == 0) {
		cout << "Enter name of file:" << endl;
		cin >> fileName;

		huffmanDecomp.run(fileName);
	}
	
	delete tree;
	return 0;
}