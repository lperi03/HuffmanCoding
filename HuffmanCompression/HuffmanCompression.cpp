// HuffmanCompression.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
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

    HuffmanTree(const string& fileName, long long fileSize)
        : base(nullptr), originalFileName(fileName), originalFileSize(fileSize), uniqueSymbols(0), totalSymbols(0), compressionRatio(0.0), entropy(0.0) {}
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

void generateHuffmanCodes(HuffmanNode* node, const string& code, unordered_map<char, string>& huffmanCodes) {
    if (node == nullptr) {
        return;
    }

    if (node->isLeaf) {
        huffmanCodes[node->symbol] = code;
        return;
    }

    generateHuffmanCodes(node->leftChild, code + "0", huffmanCodes);
    generateHuffmanCodes(node->rightChild, code + "1", huffmanCodes);
}


//function to build huffman tree from frequency table and huffman tree constructor
//contains struct that compares nodes
//creates a priority queue with nodes of the tree
void buildHuffmanTree(const unordered_map<char, int>& frequencyTable, HuffmanTree& huffmanTree) {
    struct nodeComparisons {
        bool operator() (const HuffmanNode* lC, const HuffmanNode* rC) {
            return lC->frequency > rC->frequency;
        }
    };

    priority_queue<HuffmanNode*, vector<HuffmanNode*>, nodeComparisons> pqueue;

    for (const auto& value : frequencyTable) { 
        pqueue.push(new HuffmanNode(value.first, value.second, true));
    }

    while (pqueue.size() > 1) {
        HuffmanNode* left = pqueue.top();
        pqueue.pop();
        HuffmanNode* right = pqueue.top();
        pqueue.pop();

        HuffmanNode* parent = new HuffmanNode('\0', left->frequency + right->frequency, false);
        parent->leftChild = left;
        parent->rightChild = right;

        pqueue.push(parent);
    }

     huffmanTree.base = pqueue.top();
}

void compressFile(const string& originalFile, const string& compressedFile, const unordered_map<char, string>& huffmanCodes, const HuffmanTree& huffmanTree) {
    ifstream input(originalFile, ios::binary);
    ofstream output(compressedFile, ios::binary);

    if (!input) {
        cerr << "Error opening original/input file!" << originalFile << endl;
        return;
    }
    //gets huffman codes
    char character;
    string hCode;
    while (input.get(character)) {
        hCode = huffmanCodes.at(character);

        for (char bit : hCode) {
            if (bit == '0') {
                output.put(0x00);
            }
            else {
                output.put(0x01);
            }

        }
    }

    input.close();
    output.close();

    //calculates compressionRatio and prints to console
    double compressionRatio = (static_cast<double>(output.tellp()) / huffmanTree.originalFileSize) * 100;
    cout << "Compression Ratio: " << compressionRatio << "%" << endl;
}



int main()
{
    //Defines all necessary things to run compression algorithm on a text file
    //this main method contains a sample run with a random_text.txt file as the input, the file is in the same working directory as this code

    string inputFile = "random_text.txt";
    //calculating input file size
    ifstream input(inputFile, ios::binary);
    input.seekg(0, ios::end);
    long long fileSize = input.tellg();
    input.close();
    //defining output file that contains compressed text
    string outputFile = "compressed.bin";

    //defining frequency table from input file
    unordered_map<char, int> frequencyTable = calcSymbolFrequency(inputFile);

    //constructing and building the huffman tree corresponding to input file
    HuffmanTree huffmanTree(inputFile, fileSize);
    buildHuffmanTree(frequencyTable, huffmanTree);

    //defining and generating huffman codes from tree
    unordered_map<char, string> huffmanCodes;

    generateHuffmanCodes(huffmanTree.base, "", huffmanCodes);

    //using generated huffman codes to compress file
    compressFile(inputFile, outputFile, huffmanCodes, huffmanTree);

    return 0;

    
}
