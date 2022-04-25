//
// Created by Tyler on 4/10/2022.
//

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
	if(index < newword.length()-1){
		char v = root->_mychar;
		if(newword[index] < v){
			root->leftSubtree(insert_bst_local(newword,index,root->leftSubtree()));
		}
		else if(newword[index] > v){
			root->rightSubtree(insert_bst_local(newword,index,root->rightSubtree()));
		}
		else{
			root->depthSubtree(insert_bst_local(newword,index+1,root->depthSubtree()));
		}
	}
	else root->setWord(true);
	return root;
}



bool TrieBST::search_bst(std::string searchword) {
	return search_bst_local(searchword,0,_myroot);
}

bool TrieBST::search_bst_local(std::string searchword, int index, TreeNode *root) {
	if(root == nullptr){
		return false;
	}
	if(index < searchword.length()-1){
		char v = root->_mychar;
		if(searchword[index] < v){
			return search_bst_local(searchword,index,root->leftSubtree());
		}
		else if(searchword[index] > v){
			return search_bst_local(searchword,index,root->rightSubtree());
		}
		else{
			return search_bst_local(searchword,index+1,root->depthSubtree());
		}
	}
	else return root->getWord();
}

