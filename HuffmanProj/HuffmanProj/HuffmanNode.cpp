#include "HuffmanNode.h"

bool HuffmanNode::operator()(HuffmanNode* nodeOne, HuffmanNode* nodeTwo)
{
	return nodeOne->freq > nodeTwo->freq;
}

int HuffmanNode::getFreq()
{
	return this->freq;
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
	return this->leftChild;
}

HuffmanNode* HuffmanNode::getRChild()
{
	return this->rightChild;
}

char HuffmanNode::getCharacter()
{
	return this->_character;
}


ostream& operator<<(ostream& os, const HuffmanNode& node)
{
	cout << (int) node._character << endl;
	
	return os;
}
