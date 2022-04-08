//
// Created by Tyler on 4/7/2022.
//
#include "TrieNode.hpp"

TrieNode::TrieNode() {
	_isword = false;
	_listofcharacters = new std::vector<TrieNode *>();
	_listofcharacters->resize(26, nullptr);
}

void TrieNode::addnewchar(int index) {
	_listofcharacters->at(index) = new TrieNode;
}
