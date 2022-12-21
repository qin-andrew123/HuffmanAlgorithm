#include "HuffmanBinTree.h"

HuffmanNode* HuffmanBinTree::constructTree(unordered_map<char, int> freqTable)
{
	int counter = 0;
	if (freqTable.empty() == true) {
		return nullptr;
	}
	for (auto element : freqTable) {
		HuffmanNode* newEntry = new HuffmanNode();
		newEntry->setValues(element.first, element.second, nullptr, nullptr);
		pqueue.push(newEntry);
	}

	while (pqueue.size() != 1) {
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
	HuffmanNode* root = pqueue.top();
	pqueue.pop();

	if (pqueue.empty() == false) {
		return nullptr;
	}
	return root;
}

void HuffmanBinTree::printTree(HuffmanNode* root)
{
	if (root->getLChild() == nullptr && root->getRChild() == nullptr) {
		return;
	}

	cout << *root << endl;
	printTree(root->getLChild());
	printTree(root->getRChild());
}
