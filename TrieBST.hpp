//
// Created by Tyler on 4/10/2022.
//

#ifndef CS415PROJECT3_TRIEBST_HPP
#define CS415PROJECT3_TRIEBST_HPP
#include "TreeNode.hpp"
#include<string>
#include <vector>

class TrieBST {
public:
	TrieBST();
	void insert_bst(std::string newword);
	bool search_bst(std::string searchword);
	int size_bst();
	std::vector<std::string> inorderdump();
	std::vector<std::string> autocomp_bst(std::string words);
private:
	TreeNode* insert_bst_local(std::string newword, int index, TreeNode* root);
	bool search_bst_local(std::string searchword,int index, TreeNode* root);
	int size_bst_local(TreeNode* root);
	std::vector<std::string> inorderdump_local(TreeNode* root, std::string prefix, std::vector<std::string> &words);
	std::vector<std::string> autocomp_local(TreeNode* root, std::string prefix, std::vector<std::string> &words);
	TreeNode* _myroot;
};

#endif //CS415PROJECT3_TRIEBST_HPP
