//
// Created by Tyler on 4/7/2022.
//

#include "Trie.hpp"
#include <iostream>

Trie::Trie() {
	_myroot = new TrieNode();
}

void Trie::insert(std::string newword) {
	TrieNode *tempnode = _myroot;
	for(int i = 0; i <newword.length();i++){
		int index = newword.at(i) - 'a';
		if(!tempnode->listofchars()->at(index)){ //checking to see if a node already exists at that character
			tempnode->addnewchar(index); //if not add new char
		}
		tempnode = tempnode->listofchars()->at(index); //moving onto next character
	}
	tempnode->setWord(true); //end of word so set word to true
}

bool Trie::search(std::string searchword) {
	TrieNode *tempnode = _myroot;
	for(int i = 0; i <searchword.length();i++){
		int index = searchword.at(i) - 'a'; //getting index that character should be stored at
		if(!tempnode->listofchars()->at(index)){ //checking to see if a node already exists at that character
			return false;
		}
		tempnode = tempnode->listofchars()->at(index); //moving onto next character
	}
	return tempnode->getWord(); //we are at where the word should be so return if word is true or not
}

void Trie::remove(std::string deleteword) {
	//not sure if this needs to be implemented
}

