#include <iostream>
#include <sstream>
#include "Reader.hpp"
#include "Trie.hpp"
#include "TrieBST.hpp"
#include <chrono>

int main(int argc, const char *argv[]) {
	const char *flag = argv[2];
	std::string mytext, myword;
	Reader myread = Reader(argv[1]); //reading in the text file
	mytext += myread.gettext(); //reading in the text file

	//building standard trie
	std::stringstream ss(mytext);
	auto begin = std::chrono::high_resolution_clock::now();
	//timing starts for build standard trie
	Trie *_myTrie = new Trie();// creating the trie
	while (getline(ss,myword, ' ')){ //insert the text file into the trie one word at a time
		_myTrie->insert(myword);
	}
	//timing ends for building standard trie
	auto end = std::chrono::high_resolution_clock::now();
	auto total = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
	std::cout<< "Time taken to build the standard Trie is " << total.count();
	std::cout<< " and space occupied by it is " << _myTrie->size() << std::endl;

	//Building bst trie
	std::stringstream xx(mytext);
	begin = std::chrono::high_resolution_clock::now();
	//timing bst start now
	TrieBST *_myTrieBST = new TrieBST();
	while (getline(xx,myword, ' ')){ //insert the text file into the trie one word at a time
		_myTrieBST->insert_bst(myword);
	}
	//timing ends for bst trie
	end = std::chrono::high_resolution_clock::now();
	total = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
	std::cout<< "Time taken to build the BST based Trie is " << total.count();
	std::cout<< " and space occupied by it is " << _myTrieBST->size_bst() << std::endl;

	if (*flag == '1'){
		//std::cout << "flag is 1" << std::endl;

		std::string input;
		std::cout << std::endl << "Enter search string:";

		while(std::cin >> input){
			//time start search
			begin = std::chrono::high_resolution_clock::now();
			_myTrie->search(input);
			//search timing ends
			end = std::chrono::high_resolution_clock::now();
			total = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
			std::cout<< "Time taken to search in the standard Trie is " << total.count() << std::endl;

			begin = std::chrono::high_resolution_clock::now();
			_myTrie->search_map(input);
			//search timing ends
			end = std::chrono::high_resolution_clock::now();
			total = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
			std::cout<< "Time taken to search with map in the standard Trie is " << total.count() << std::endl;

			begin = std::chrono::high_resolution_clock::now();
			std::vector<std::string> completes = _myTrie->autocomplete(input);
			end = std::chrono::high_resolution_clock::now();
			total = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

			std::cout<< "Auto-complete results using standard Trie are: ";
			for(int i = 0; i < completes.size();i++){
				std::cout << completes.at(i) << ",";
			}
			std::cout<< std::endl<< "Time taken to find auto-complete results in the standard Trie is " << total.count() << std::endl <<std::endl;

			//time start search
			begin = std::chrono::high_resolution_clock::now();
			_myTrieBST->search_bst(input);
			//search timing ends
			end = std::chrono::high_resolution_clock::now();
			total = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
			std::cout<< "Time taken to search in the BST based Trie is " << total.count() << std::endl;

			begin = std::chrono::high_resolution_clock::now();
			completes = _myTrieBST->autocomp_bst(input);
			end = std::chrono::high_resolution_clock::now();
			total = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

			std::cout<< "Auto-complete results using BST based Trie are: ";
			for(int i = 0; i < completes.size();i++){
				std::cout << completes.at(i) << ",";
			}
			std::cout<< std::endl<< "Time taken to find auto-complete results in the BST Based Trie is " << total.count() << std::endl;
			std::cout << std::endl << "Enter search string:";
		}
	}
	else if(*flag == '2'){
		//std::cout <<"flag is 2" <<std::endl;
		std::stringstream bb(mytext);
		std::stringstream aa(mytext);

		begin = std::chrono::high_resolution_clock::now();
		while (getline(bb,myword, ' ')){ //insert the text file into the trie one word at a time
			_myTrie->search(myword);
		}
		end = std::chrono::high_resolution_clock::now();
		total = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
		std::cout<< "Time taken to search all the strings in the standard Trie is " << total.count() << std::endl;


		begin = std::chrono::high_resolution_clock::now();
		while (getline(aa,myword, ' ')){ //insert the text file into the trie one word at a time
			_myTrieBST->search_bst(myword);
		}
		end = std::chrono::high_resolution_clock::now();
		total = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
		std::cout<< "Time taken to search all the strings in the BST based Trie is " << total.count() << std::endl;
	}

	return 0;
}
