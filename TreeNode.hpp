//
// Created by Tyler on 4/24/2022.
//

#ifndef CS415PROJECT3_TREENODE_HPP
#define CS415PROJECT3_TREENODE_HPP
class TreeNode {
public:
	TreeNode(){
		left = nullptr;
		right = nullptr;
		depth = nullptr;
		_isword = false;
	}
	TreeNode(char v): left(nullptr), right(nullptr), depth(nullptr), _isword(false), _mychar(v) {}
	TreeNode *leftSubtree() { return left; }
	TreeNode *rightSubtree() { return right; }
	TreeNode *depthSubtree() {return depth;}

	void leftSubtree( TreeNode *left ) { this->left = left; }
	void rightSubtree(TreeNode *right) { this->right = right; }
	void depthSubtree(TreeNode *depth) { this->depth = depth; }

	void setWord(bool word) {_isword = word;}
	bool getWord() { return _isword;}

	void setchar(char input) {_mychar = input;}
	bool getchar() {return _mychar;}
	char _mychar;

private:
	TreeNode *left, *right, *depth;
	bool _isword;

};
#endif //CS415PROJECT3_TREENODE_HPP
