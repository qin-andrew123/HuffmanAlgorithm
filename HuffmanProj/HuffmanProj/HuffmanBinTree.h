#pragma once
#include "HuffmanNode.h"
#include <queue>
#include <unordered_map>

using namespace std; 

class HuffmanBinTree {
private:
	priority_queue<HuffmanNode*, vector<HuffmanNode*>, HuffmanNode> pqueue;
public:
	~HuffmanBinTree() = default;
	HuffmanNode* constructTree(unordered_map<char,int> freqTable);

	enum binTreeVals {
		STACK_MIN_VAL = 1,
	};
};