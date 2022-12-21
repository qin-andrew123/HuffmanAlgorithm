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
	void compressFile(string fileName);
	void run(string fileName);
};