/*
	Author: Denish Pasupuleti
	Date: 10/20/2020
	Description: BNode component of proj2 where BNodes are in BookTree
							 and consist of wordtree object
*/
#include "bNode.h"
BNode::BNode() {}
BNode::BNode(string key, string author, string text) {
	_key = key;
	_author = author;
	_left = nullptr;
	_right = nullptr;
	_flag = false;
	_parent = nullptr;
	createTextTree(text);
}
BNode::~BNode() { }

void BNode::createTextTree(string text) {
	istringstream iss(text);
	vector<string> tokens;
	copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(tokens));
	for (std::vector<string>::iterator it = tokens.begin(); it != tokens.end(); ++it) {
		_tree.insert(*it);
	}
}

int BNode::findFrequency(string word) {
	/***********************************
	 *      To be implemented
	 * Note: to avoid warnings, a
	 * fictional return value is added,
	 * your implementaion should return
	 * a correct value.
	 * ********************************/

	if (_tree.find(word) == nullptr)
		return 0;
	return _tree.find(word)->getFrequency();
}

int BNode::searchCount(string word) {
	/***********************************
	 *      To be implemented
	 * Note: to avoid warnings, a
	 * fictional return value is added,
	 * your implementaion should return
	 * a correct value.
	 * ********************************/
	return _tree.searchCount(word);
}

int BNode::getTextTreeHeight() {
	/***********************************
	 *      To be implemented
	 * Note: to avoid warnings, a
	 * fictional return value is added,
	 * your implementaion should return
	 * a correct value.
	 * ********************************/
	return _tree.getRootHeight();
}

int BNode::getNodeHeight(string word) {
	/***********************************
	 *      To be implemented
	 * Note: to avoid warnings, a
	 * fictional return value is added,
	 * your implementaion should return
	 * a correct value.
	 * ********************************/
	return _tree.getNodeHeight(word);
}