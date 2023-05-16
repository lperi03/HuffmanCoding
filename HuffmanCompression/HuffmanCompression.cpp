// HuffmanCompression.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>

// Structure representing node in Huffman tree
struct HuffmanNode {
    // defining character/symbol and the frequency associated with the symbol
    char symbol;
    int frequency;
    
    // Pointers to left and right child Huffman nodes
    HuffmanNode* leftChild;
    HuffmanNode* rightChild;

    HuffmanNode(char symbol, int frequency)
        : symbol(symbol), frequency(frequency), leftChild(nullptr), rightChild(nullptr) {} 
};

// Structure representing Huffman tree, with pointer to base/root node

struct HuffmanTree {
    HuffmanNode* base;

    HuffmanTree()
        : base(nullptr) {}
};

int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
