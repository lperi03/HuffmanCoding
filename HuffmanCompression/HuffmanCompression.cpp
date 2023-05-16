// HuffmanCompression.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// Structure representing node in Huffman tree
struct HuffmanNode {
    // defining character/symbol and the frequency associated with the symbol
    //also checking if given node is a leaf with boolean
    char symbol;
    int frequency;
    bool isLeaf;
    
    // Pointers to left and right child Huffman nodes
    HuffmanNode* leftChild;
    HuffmanNode* rightChild;

    HuffmanNode(char symbol, int frequency, bool isLeaf)
        : symbol(symbol), frequency(frequency), isLeaf(isLeaf), leftChild(nullptr), rightChild(nullptr) {} 
};

// Structure representing Huffman tree, with pointer to base/root node

struct HuffmanTree {
    HuffmanNode* base;
    
    string originalFileName;
    long long originalFileSize;
    int uniqueSymbols;
    int totalSymbols;
    double compressionRatio;
    double entropy;

    HuffmanTree()
        : base(nullptr), originalFileName(" "), originalFileSize(0), uniqueSymbols(0), totalSymbols(0), compressionRatio(0.0), entropy(0.0) {}
};

unordered_map<char, int> calcSymbolFrequency(const string& fileName) {
    unordered_map<char, int> frequencyTable;
    ifstream inputFile(fileName);

    //need to add some contingency to handle errors with input file
    if (!inputFile) {
        cerr << "Error opening input file! : " << fileName << endl;
        return frequencyTable;
    }

    char character;
    while (inputFile.get(character)) {
        frequencyTable[character]++;
    }

    inputFile.close();
    return frequencyTable;
}


HuffmanNode* buildHuffmanTree(const unordered_map<char, int>& frequencyTable) {
    struct nodeComparisons {

    };
}



//int main()
//{
    //cout << "Hello World!\n";
//}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
