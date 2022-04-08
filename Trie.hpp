//
// Created by Tyler on 4/7/2022.
//

#ifndef CS415PROJECT3_TRIE_HPP
#define CS415PROJECT3_TRIE_HPP


#include "TrieNode.hpp"
#include "Reader.hpp"
#include<string>
#include <fstream>

class Trie {
public:
	Trie();
	void insert(std::string newword);
	bool search(std::string searchword);
	void remove(std::string deleteword); // not sure if needs to be implemented
private:
	TrieNode *_myroot;
};


#endif //CS415PROJECT3_TRIE_HPP
