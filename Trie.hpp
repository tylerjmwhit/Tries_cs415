//
// Created by Tyler on 4/7/2022.
//

#ifndef CS415PROJECT3_TRIE_HPP
#define CS415PROJECT3_TRIE_HPP


#include "TrieNode.hpp"
#include<string>


class Trie {
public:
	Trie();
	int size();
	void insert(std::string newword);
	bool search(std::string searchword);
	std::vector<std::string> autocomplete(std::string prefix);
private:
	std::vector<std::string> helperAuto(std::string prefix, TrieNode* currNode, std::vector<std::string> &words);
	int local_size(TrieNode* root);
	TrieNode *_myroot;


};


#endif //CS415PROJECT3_TRIE_HPP
