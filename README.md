# HuffmanCoding
 Huffman Coding algorithm for file compression.

 # Python file instructions
 There is a Python file added to the repo called generate_random_text.py, which generates random text of the desired length and saves it as a file. The compression algorithm is currently configured to compress this file . You can play around with the length of the random text to see how the compression algorithm performs. 
 # Instructions for running huffmanCompression.cpp
If you change the name of the file being outputted by generate_random_text.py, make sure to update the "input file" in the main method of huffmanCompression.cpp. 

# Comments
Note: The Huffman encoding algorithm doesn't work when the input file size is small (i.e., around 1 kb or so). As both the Huffman tree and the encoded data need to be stored, at small input file sizes, the data required to build and store the tree will somewhat counter the algorithm's ability, thus making the compression inefficient for small file sizes. Therefore, it is important to use large files to see how the algorithm actually performs (making input length around 1e6 or higher should do the trick) 
