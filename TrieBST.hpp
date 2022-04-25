//
// Created by Tyler on 4/10/2022.
//

#ifndef CS415PROJECT3_TRIEBST_HPP
#define CS415PROJECT3_TRIEBST_HPP
#include "TreeNode.hpp"
#include<string>

class TrieBST {
public:
	TrieBST();
	void insert_bst(std::string newword);
	bool search_bst(std::string searchword);
private:
	TreeNode* insert_bst_local(std::string newword, int index, TreeNode* root);
	bool search_bst_local(std::string searchword,int index, TreeNode* root);
	TreeNode* _myroot;
};

#endif //CS415PROJECT3_TRIEBST_HPP
