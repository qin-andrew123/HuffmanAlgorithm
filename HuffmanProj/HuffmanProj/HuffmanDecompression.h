#pragma once
#include "HuffmanNode.h"
#include <string>

using namespace std;

class HuffmanDecompression {
public:
	HuffmanNode* rebuildTree(ifstream& ifs);
	void decompress(HuffmanNode* root, ifstream& ifs);
	void run(string fileName);

	enum DecompressionVals {
		INCREMENT = 1,
		BYTE_SIZE = 8,
		EOF_VAL = -1,
	};
};