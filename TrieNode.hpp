//
// Created by Tyler on 4/7/2022.
//

#ifndef CS415PROJECT3_TRIENODE_HPP
#define CS415PROJECT3_TRIENODE_HPP

#include <vector>
#include <map>

class TrieNode {
public:
	TrieNode();
	void setWord(bool word) {_isword = word;}
	bool getWord() { return _isword;}
	std::vector<TrieNode *> *listofchars() {return _listofcharacters;}
	void addnewchar(int index);

private:
	std::vector<TrieNode *> *_listofcharacters;
	bool _isword;
};


#endif //CS415PROJECT3_TRIENODE_HPP
