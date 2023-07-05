// Decompression algorithm for files compressed using Huffman coding
//The main method in this code will retrieve the original file (generated by generate_random_text.py) using the compressed.bin file

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

//Method to read in the compressed binary file
string readCompressedFile(const string& compressedFile) {
    ifstream inputFile(compressedFile, ios::binary);

    //error message if unable to read input file
    if (!inputFile) {
        cerr << "Error opening compressed file!:" << compressedFile << endl;
        //return empty string
        return " ";
    }

    string compressedData((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());

    inputFile.close();
    return compressedData;
}

HuffmanNode* rebuildHuffmanTree(ifstream& input) {
      
}