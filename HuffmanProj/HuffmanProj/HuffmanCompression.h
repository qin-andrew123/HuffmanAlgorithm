#pragma once
#include "HuffmanBinTree.h"
#include <unordered_map>
#include <string>

using namespace std;

class HuffmanCompression {
private:
	HuffmanBinTree* binTree;
	unordered_map<char, string> encodeMap;
public:
	HuffmanCompression(HuffmanBinTree* tree);
	~HuffmanCompression() = default;
	unordered_map<char, int> buildFreqTable(string fileName);
	void constructEncodeMap(HuffmanNode* root, string code, unordered_map<char, string>& encodeMap);
	void compressFile(string fileName, ofstream& ofs);
	void printTree(HuffmanNode* root,ofstream& ofs);
	void run(string fileName);
	
	enum CompressionVals {
		EOF_VAL = -1,
		COUNTER_MAXVAL = 7,
		BIT_OP_VAL = 1,
	};
};