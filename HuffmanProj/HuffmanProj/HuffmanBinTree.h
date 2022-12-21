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
	void printTree(HuffmanNode* root);
};