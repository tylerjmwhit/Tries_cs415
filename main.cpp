#include <iostream>
#include <sstream>
#include "Reader.hpp"
#include "Trie.hpp"
#include "TrieBST.hpp"
#include <time.h>
#include <chrono>

int main(int argc, const char *argv[]) {
	const char *flag = argv[2];
	if (*flag == '2'){
		std::cout << "flag is 2";
	}
	Trie *_myTrie = new Trie();// creating the trie
	TrieBST *_myTrieBST = new TrieBST();
	std::string mytext, myword; // mytext will read in text fill to just lowercase words seperated by spaces, myword is used to pull words from this
	Reader myread = Reader(argv[1]); //reading in the text file
	mytext += myread.gettext(); //reading in the text file

	std::stringstream ss(mytext);
	clock_t start = clock();
	auto begin = std::chrono::high_resolution_clock::now();
	while (getline(ss,myword, ' ')){ //insert the text file into the trie one word at a time
			_myTrie->insert(myword);
	}
	clock_t end= clock();
	auto endding = std::chrono::high_resolution_clock::now();
	auto elapseding = std::chrono::duration_cast<std::chrono::microseconds>(endding - begin);
	double elapsed = double(end-start)/CLOCKS_PER_SEC;
	std::cout<< "the time elapsed to build the standard trie was: " << elapsed << std::endl;
	std::cout<< "the time elapsed to build the standard trie was in chrono: " << elapseding.count() << std::endl;

	std::stringstream tt(mytext);
	start = clock();
	begin = std::chrono::high_resolution_clock::now();
	while (getline(tt,myword, ' ')){ //insert the text file into the trie one word at a time
		_myTrieBST->insert_bst(myword);
	}
	end = clock();
	endding = std::chrono::high_resolution_clock::now();
	elapseding = std::chrono::duration_cast<std::chrono::microseconds>(endding - begin);
	elapsed = double(end-start)/CLOCKS_PER_SEC;
	std::cout<< "the time elapsed to build the bst trie was: " << elapsed << std::endl;
	std::cout<< "the time elapsed to build the bst trie was in chrono: " << elapseding.count()<< std::endl;


////	bool mybool = _myTrie->search("a");
//	std::vector<std::string> completes = _myTrie->autocomplete("wa");
//	for(int i = 0; i < completes.size();i++){
//		std::cout << completes.at(i) << std::endl;
//	}
////	if(mybool){
////		std::cout << "hello is in the trie";
////	}
////	else{
////		std::cout << "hello is not in the trie";
////	}
	return 0;
}
