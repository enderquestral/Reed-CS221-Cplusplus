Partners: Hannah Hellerstein and Casey Harris 
HTree/HForest source code came from: Eitan. We wanted to use code that was clean/had less bugs than our respective codes. However, Hannah's test_htree.cc and htree.cc files were included for the sake of the makefile.


Overview of code design:
In huffman, we made a function make_huffman_tree(); to use throughout the code. For both encode and decode in huffman, we simply remade a huffman tree after every call, and then used for loops to make a vector of booleans or travel through the huffman tree.
In bitio, we stored the input/output streams, and make sure that when a bitio was destroyed, any bits were to be pushed to the output stream regardless of their placement. 

As for encoder/decoder... we couldn't get them to function properly or compress anything properly. Sure it would read in the filess correctly and create a new file with the appropriate name, but we couldn't get it to compress the characters at all well.


Results of compression tests:


    File name   | Raw file size in bytes   | Compressed file size in bytes | Decompressed file matches raw file (yes/no)

FIGHTBUGSASCII.txt      901 bytes

HSQuote.txt             218 bytes

Ozymandias.txt          633 bytes

ASCIIARTVenasaur.txt   2 KB

DRQuote.txt         171 bytes