#include "HuffmanDecompression.h"
#include "HuffmanBinTree.h"
#include "HuffmanNode.h"
#include <fstream>
#include <stack>
#include <iostream>
#include <bitset>
#include <sstream>

HuffmanNode* HuffmanDecompression::rebuildTree(ifstream& ifs)
{
	stack<HuffmanNode*> stack;
	string line;
	while (getline(ifs, line)) {
		auto a = line.find(" ");
		int symbolToChar = stoi(line.substr(0, a));

		string newString = line.substr(a + INCREMENT);

		char symbol = symbolToChar;
		int freq = stoi(newString);

		if (symbol == 0) {
			HuffmanNode* rChild = stack.top();
			stack.pop();

			HuffmanNode* lChild = stack.top();
			stack.pop();

			HuffmanNode* node = new HuffmanNode();
			node->setValues(symbol, freq, lChild, rChild);
			stack.push(node);
		}
		else {
			HuffmanNode* node = new HuffmanNode();
			node->setValues(symbol, freq, nullptr, nullptr);
			stack.push(node);
		}
	}

	HuffmanNode* root = stack.top();
	stack.pop();
	return root;
}

void HuffmanDecompression::decompress(HuffmanNode* root, ifstream& ifs)
{
	HuffmanNode* startPos = root;
	cout << "What do you want to call your decompressed file?" << endl;
	string fileName;
	cin >> fileName;
	ofstream ofs(fileName);

	bitset<BYTE_SIZE> binary;
	char data;

	while (ifs.get(data)) {
		binary = data;
		string path = binary.to_string();
		for (int i = 0; i < path.size(); ++i) {
			if (path[i] == '0') {
				root = root->getLChild();
				if (root->getLChild() == nullptr && root->getRChild() == nullptr) {
					if ((int)root->getCharacter() == EOF_VAL) {
						ofs << endl;
						return;
					}
					ofs << root->getCharacter();
					root = startPos;
				}
			}
			else if (path[i] == '1') {
				root = root->getRChild();
				if (root->getLChild() == nullptr && root->getRChild() == nullptr) {
					if ((int)root->getCharacter() == EOF_VAL) {
						ofs << endl;
						return;
					}
					ofs << root->getCharacter();
					root = startPos;
				}
			}
		}
	}
}


void HuffmanDecompression::run(string fileName)
{
	string treeFileName = "tree" + fileName;
	ifstream treeifs(treeFileName, ios::binary);
	ifstream compressIfs(fileName, ios::binary);
	HuffmanNode* root = rebuildTree(treeifs);
	decompress(root, compressIfs);
	treeifs.close();
	compressIfs.close();
}