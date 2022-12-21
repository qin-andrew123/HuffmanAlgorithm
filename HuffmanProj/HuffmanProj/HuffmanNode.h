#pragma once
#include <iostream>

using namespace std;

class HuffmanNode {
private:
	char _character;
	int freq;
	HuffmanNode* leftChild;
	HuffmanNode* rightChild;

public:
	~HuffmanNode() = default;
	bool operator() (HuffmanNode* nodeOne, HuffmanNode* nodeTwo);
	friend ostream& operator <<(ostream& os, const HuffmanNode& node);
	int getFreq();
	void setValues(char character, int frequency, HuffmanNode* lChild, HuffmanNode* rChild);
	HuffmanNode* getLChild();
	HuffmanNode* getRChild();
	char getCharacter();
};

ostream& operator <<(ostream& os, const HuffmanNode& node);