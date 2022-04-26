//
// Created by Tyler on 4/7/2022.
//

#ifndef CS415PROJECT3_TRIE_HPP
#define CS415PROJECT3_TRIE_HPP
#include <map>
#include "TrieNode.hpp"
#include<string>


class Trie {
public:
	Trie();
	int size();
	void insert(std::string newword);
	void insert_map(std::string newword);
	bool search(std::string searchword);
	bool search_map(std::string searchword);
	std::vector<std::string> autocomplete(std::string prefix);
private:
	std::map<char, int> chartoarray{
		{'a',0},{'b',1},{'c',2},{'d',3},{'e',4},{'f',5},{'g',6},
		{'h',7},{'i',8},{'j',9},{'k',10},{'l',11},{'m',12},{'n',13},
		{'o',14},{'p',15},{'q',16},{'r',17},{'s',18},{'t',19},
		{'u',20},{'v',21},{'w',22},{'x',23},{'y',24},{'z',25}
	};
	std::vector<std::string> helperAuto(std::string prefix, TrieNode* currNode, std::vector<std::string> &words);
	int local_size(TrieNode* root);
	TrieNode *_myroot;


};


#endif //CS415PROJECT3_TRIE_HPP
