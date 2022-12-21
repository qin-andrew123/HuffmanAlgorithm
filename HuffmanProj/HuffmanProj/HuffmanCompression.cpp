#include "HuffmanCompression.h"
#include <iostream>
#include <fstream>

HuffmanCompression::HuffmanCompression(HuffmanBinTree* tree) : binTree(tree), encodeMap(){}

unordered_map<char, int> HuffmanCompression::buildFreqTable(string fileName)
{
	unordered_map<char, int> freqMap;
	char character;

	ifstream ifs(fileName, ios::binary);

	while (ifs.get(character)) {
		++freqMap[character];
	}

	for (auto i = freqMap.begin(); i != freqMap.end(); ++i) {
		cout << "character: " << i->first << " Freq: " << i->second << endl;
	}

	if (freqMap.empty() == true) {
		return unordered_map<char,int>();
	}
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
	}
	
	
	constructEncodeMap(root->getLChild(), code + '0', encodeMap);
	constructEncodeMap(root->getRChild(), code + '1', encodeMap);
}

void HuffmanCompression::compressFile(string fileName)
{
    
}

void HuffmanCompression::run(string fileName)
{
	auto freqMap = buildFreqTable(fileName);
	HuffmanNode* root = binTree->constructTree(freqMap);
	constructEncodeMap(root, "", encodeMap);
	compressFile(fileName);
}
