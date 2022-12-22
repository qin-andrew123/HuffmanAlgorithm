#include "HuffmanCompression.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <bitset>

HuffmanCompression::HuffmanCompression(HuffmanBinTree* tree) : binTree(tree), encodeMap() {}

unordered_map<char, int> HuffmanCompression::buildFreqTable(string fileName)
{
	unordered_map<char, int> freqMap;
	char character;

	ifstream ifs(fileName, ios::binary);

	while (ifs.get(character)) {
		++freqMap[character];
	}

	char eof = EOF_VAL;
	++freqMap[eof];

	ifs.close();
	return freqMap;
}

void HuffmanCompression::constructEncodeMap(HuffmanNode* root, string code, unordered_map<char, string>& encodeMap)
{
	if (root == nullptr) {
		return;
	}

	if (root->getLChild() == nullptr && root->getRChild() == nullptr) {
		encodeMap[root->getCharacter()] = code;
		return;
	}

	constructEncodeMap(root->getLChild(), code + '0', encodeMap);
	constructEncodeMap(root->getRChild(), code + '1', encodeMap);
}

void HuffmanCompression::compressFile(string fileName, ofstream& ofs)
{
	ifstream ifs(fileName, ios::binary);
	char data;
	unsigned char buffer = 0;
	int counter = COUNTER_MAXVAL;

	while (ifs.get(data)) {
		string code = encodeMap.find(data)->second;
		for (int i = 0; i < code.size(); ++i) {
			if (counter == 0) {
				if (code[i] == '1') {
					buffer |= BIT_OP_VAL;
				}
				counter = COUNTER_MAXVAL;
				ofs << buffer;
				buffer = 0;
			}
			else {
				if (code[i] == '1') {
					buffer |= BIT_OP_VAL << counter;
					--counter;
				}
				else {
					--counter;
				}
			}
		}
	}

	char eof = EOF_VAL;

	string eofCode = encodeMap.find(eof)->second;

	for (int i = 0; i < eofCode.size(); ++i) {
		if (counter == 0) {
			if (eofCode[i] == '1') {
				buffer |= BIT_OP_VAL;
			}
			counter = COUNTER_MAXVAL;
			ofs << buffer;
			buffer = 0;
		}
		else {
			if (eofCode[i] == '1') {
				buffer |= BIT_OP_VAL << counter;
				--counter;
			}
			else {
				--counter;
			}
		}
	}
	ofs << buffer;
	ifs.close();
}

void HuffmanCompression::printTree(HuffmanNode* root, ofstream& ofs)
{
	if (root == nullptr) {
		return;
	}	
	printTree(root->getLChild(), ofs);
	printTree(root->getRChild(), ofs);

	ofs << (int)root->getCharacter() << " " << root->getFreq() << endl;
}

void HuffmanCompression::run(string fileName)
{
	string outputfile;
	cout << "Name of output file:" << endl;
	cin >> outputfile;

	string treeFileName = "tree" + outputfile;
	ofstream ofs(outputfile, ios::binary);
	ofstream treeOfs(treeFileName, ios::binary);

	auto freqMap = buildFreqTable(fileName);
	HuffmanNode* root = binTree->constructTree(freqMap);

	constructEncodeMap(root, "", encodeMap);

	printTree(root, treeOfs);
	
	compressFile(fileName, ofs);
	
	ofs.close();
}
