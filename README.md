Spell Checker!

This is a spell-checking program that allows users to check the spelling of words in a given text file against a provided dictionary.

Usage
To use the spell checker, compile the speller.c file along with dictionary.c:

make speller.c

You need to create a directory called "texts" and put the text file you want to spellcheck there. A sample text file is in the repository. Then, run the compiled executable with the text file you want to spell-check:

./speller text.txt

Create a directory called "dictionary" and put your dictionary file there or you can use the one provided here. If you have multiple dictinoaries, you can specify a different dictionary by passing it as a command-line argument:

./speller dictionary.txt text.txt

Experimenting with Hashing Function
You can experiment with the hashing function used in the spell checker to optimize its speed and memory usage. Here's how:

Open the dictionary.c file.
Locate the hash function, which is responsible for generating hash values for words.
Modify the hash function to test different prime numbers or collision resolution techniques.
Save your changes and compile speller.c to see the effect of your modifications on the program's performance.
Note: Make sure to test your changes thoroughly to ensure that they improve the spell checker's efficiency without compromising its accuracy.

Benchmarking
After experimenting with the hashing function, you can benchmark the spell checker to compare its performance before and after your modifications. The program reports various benchmarks, including the time taken to load the dictionary, check words, determine the dictionary's size, and unload the dictionary.

Contributing
Contributions to this spell checker are welcome! If you have ideas for improving the program or optimizing its performance further, feel free to submit a pull request.
