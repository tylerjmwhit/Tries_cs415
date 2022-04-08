#include <iostream>
#include <sstream>
#include "Reader.hpp"
#include "Trie.hpp"

int main(int argc, const char *argv[]) {
	Trie *_myTrie = new Trie(); // creating the trie
	std::string mytext, myword; // mytext will read in text fill to just lowercase words seperated by spaces, myword is used to pull words from this
	Reader myread = Reader(argv[1]); //reading in the text file
	mytext += myread.gettext(); //reading in the text file
	std::stringstream ss(mytext);
	while (getline(ss,myword, ' ')){ //insert the text file into the trie one word at a time
			_myTrie->insert(myword);
	}
	bool mybool = _myTrie->search("hello");
	if(mybool == true){
		std::cout << "hello is in the trie";
	}
	else{
		std::cout << "hello is not in the trie";
	}
	return 0;
}
