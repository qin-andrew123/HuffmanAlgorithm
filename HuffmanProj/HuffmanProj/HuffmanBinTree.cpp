#include "HuffmanBinTree.h"

HuffmanNode* HuffmanBinTree::constructTree(unordered_map<char, int> freqTable)
{
	int counter = 0;

	for (auto element : freqTable) {
		HuffmanNode* newEntry = new HuffmanNode();
		newEntry->setValues(element.first, element.second, nullptr, nullptr);
		pqueue.push(newEntry);
	}

	while (pqueue.size() != STACK_MIN_VAL) {
		//Make first left child 
		HuffmanNode* lChild = pqueue.top();
		pqueue.pop();

		//Make second right child
		HuffmanNode* rChild = pqueue.top();
		pqueue.pop();

		int childSum = lChild->getFreq() + rChild->getFreq();
		HuffmanNode* parent = new HuffmanNode();
		parent->setValues('\0', childSum, lChild, rChild);
		pqueue.push(parent);
	}
	
	return pqueue.top();
}
