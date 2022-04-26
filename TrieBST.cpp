//
// Created by Tyler on 4/10/2022.
//

#include <iostream>
#include "TrieBST.hpp"

TrieBST::TrieBST() {
	_myroot = nullptr;
}

void TrieBST::insert_bst(std::string newword) {
	_myroot = insert_bst_local(newword,0,_myroot);
}

TreeNode* TrieBST::insert_bst_local(std::string newword, int index, TreeNode* root) {
	if(root == nullptr){
		root = new TreeNode(newword[index]);
	}
	char v = root->_mychar;
	if(newword[index] < v){
		root->leftSubtree(insert_bst_local(newword,index,root->leftSubtree()));
	}
	else if(newword[index] > v){
		root->rightSubtree(insert_bst_local(newword,index,root->rightSubtree()));
	}
	else{
		if(index == newword.length()-1){
			root->setWord(true);
		}
		else{
			root->depthSubtree(insert_bst_local(newword,index+1,root->depthSubtree()));
		}
	}
	return root;
}



bool TrieBST::search_bst(std::string searchword) {
	return search_bst_local(searchword,0,_myroot);
}

bool TrieBST::search_bst_local(std::string searchword, int index, TreeNode *root) {
	if(root == nullptr){
		return false;
	}
	char v = root->_mychar;
	if(searchword[index] < v){
		return search_bst_local(searchword,index,root->leftSubtree());
	}
	else if(searchword[index] > v){
		return search_bst_local(searchword,index,root->rightSubtree());
	}
	else{
		if(index == searchword.length()-1){
			return root->getWord();
		}
			return search_bst_local(searchword,index+1,root->depthSubtree());
	}
}

int TrieBST::size_bst() {
	return size_bst_local(_myroot);
}

int TrieBST::size_bst_local(TreeNode *root) {
	if(root == nullptr){
		return 0;
	}
	return 1 + size_bst_local(root->leftSubtree()) + size_bst_local(root->rightSubtree()) + size_bst_local(root->depthSubtree());
}

std::vector<std::string> TrieBST::inorderdump() {
	std::string prefix;
	std::vector<std::string> words;
	inorderdump_local(_myroot,prefix,words);
	return words;
}

std::vector<std::string> TrieBST::inorderdump_local(TreeNode *root, std::string prefix, std::vector<std::string>& words) {
	if(root == nullptr){
		return words;
	}
	inorderdump_local(root->rightSubtree(),prefix,words);
	inorderdump_local(root->leftSubtree(),prefix,words);
	prefix += root->_mychar;
	if(root->getWord()){
		words.push_back(prefix);
	}
	inorderdump_local(root->depthSubtree(),prefix,words);
	return words;
}

std::vector<std::string> TrieBST::autocomp_bst(std::string prefix){
	std::vector<std::string> words;
	return autocomp_local(_myroot, prefix, words);
}

std::vector<std::string> TrieBST::autocomp_local(TreeNode *root, std::string prefix, std::vector<std::string>& words) {
	if(prefix.empty() || root == nullptr){
		return words;
	}
	int index = 0;
	int length = prefix.length();
	while(index < length){
		if(root == nullptr){
			return words;
		}
		char v = root->_mychar;
		if(prefix[index] < v){
			root = root->leftSubtree();
		}
		else if(prefix[index]>v){
			root = root->rightSubtree();
		}
		else if(prefix[index] == v){
			root = root->depthSubtree();
			index++;
		}
		else{
			return words;
		}
	}
	inorderdump_local(root, prefix, words);
	return words;
}

