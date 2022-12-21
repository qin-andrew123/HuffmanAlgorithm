#include "HuffmanNode.h"

bool HuffmanNode::operator()(HuffmanNode* nodeOne, HuffmanNode* nodeTwo)
{
	return nodeOne->freq > nodeTwo->freq;
}

int HuffmanNode::getFreq()
{
	return freq;
}

void HuffmanNode::setValues(char character, int frequency, HuffmanNode* lChild, HuffmanNode* rChild)
{
	_character = character;
	freq = frequency;
	leftChild = lChild;
	rightChild = rChild;
}

HuffmanNode* HuffmanNode::getLChild()
{
	return leftChild;
}

HuffmanNode* HuffmanNode::getRChild()
{
	return rightChild;
}

char HuffmanNode::getCharacter()
{
	return _character;
}


ostream& operator<<(ostream& os, const HuffmanNode& node)
{
	cout << "Node: " << node._character  << "| Freq: " << node.freq << endl;
	if (node.leftChild != nullptr) {
		cout << "  Left Child: " << *node.leftChild << endl;
	}
	if (node.rightChild != nullptr) {
		cout << "  Right Child: " << *node.rightChild << endl;
	}
	return os;
}
