//
// Created by Tyler on 4/7/2022.
//

#include "Trie.hpp"
#include <iostream>

Trie::Trie() {
	_myroot = new TrieNode();
}

int Trie::size(){
	return local_size(_myroot)-1;
}

int Trie::local_size(TrieNode *root) {
	if(root == nullptr){
		return 1;
	}
	int count = 0;
	for(int i = 0; i < root->listofchars()->size();i++){
		count += local_size(root->listofchars()->at(i));
	}
	return count + 1;
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

std::vector<std::string> Trie::autocomplete(std::string prefix) {
	TrieNode* temp = _myroot;
	std::vector<std::string> completed;
	std::string currString = prefix;
	for ( int i = 0; i < prefix.size(); i++ ){
		int letter = prefix.at(i) - 'a';
		if( temp->listofchars()->at(letter) == nullptr ){ //if next char is not found
			std::cout << "The string does not exist in this trie." << std::endl;
			return completed; //returning empty vector
		}
		temp = temp->listofchars()->at(letter);
	}
	return helperAuto( currString, temp, completed );
}

std::vector<std::string> Trie::helperAuto(std::string prefix, TrieNode* currNode, std::vector<std::string> &words) {
	if( currNode == nullptr ){
		return words;
	}
	if( currNode->getWord() ){
		words.push_back(prefix);
	}
	for( int i = 0; i < 26; i++ ){
		if( currNode->listofchars() != nullptr ){
			char letter = i + 'a';
			std::string temp = prefix + letter;
			helperAuto(temp, currNode->listofchars()->at(i), words);
		}
	}
	return words;
}

void Trie::insert_map(std::string newword) {
	TrieNode *tempnode = _myroot;
	for(int i = 0; i <newword.length();i++){
		int index = chartoarray[newword.at(i)];
		if(!tempnode->listofchars()->at(index)){ //checking to see if a node already exists at that character
			tempnode->addnewchar(index); //if not add new char
		}
		tempnode = tempnode->listofchars()->at(index); //moving onto next character
	}
	tempnode->setWord(true); //end of word so set word to true
}

bool Trie::search_map(std::string searchword) {
	TrieNode *tempnode = _myroot;
	for(int i = 0; i <searchword.length();i++){
		int index = chartoarray[searchword.at(i)]; //getting index that character should be stored at
		if(!tempnode->listofchars()->at(index)){ //checking to see if a node already exists at that character
			return false;
		}
		tempnode = tempnode->listofchars()->at(index); //moving onto next character
	}
	return tempnode->getWord(); //we are at where the word should be so return if word is true or not
}




