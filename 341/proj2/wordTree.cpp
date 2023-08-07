/*
	Author: Denish Pasupuleti
	Date: 10/20/2020
	Description: WordTree component of proj2 and is an AVL tree
*/

#include "wordTree.h"

// object destructor
WordTree::~WordTree() {
	clearTree(_root);
}

// used for updating height of a node
void WordTree::updateHeight(Node* aNode) {
	int lHeight = -1, rHeight = -1;

	// checks for if left/right is valid
	if (aNode->_left)
		lHeight = aNode->_left->_height;
	if (aNode->_right)
		rHeight = aNode->_right->_height;
	// compares height returns max
	if (lHeight >= rHeight)
		aNode->_height = lHeight + 1;
	else
		aNode->_height = rHeight + 1;
}

// used to destruct tree
void WordTree::clearTree(Node* aNode) {

	// traverses left subtree and right subtree and deletes node
	if (aNode) {
		clearTree(aNode->_left);
		clearTree(aNode->_right);
		delete aNode;
	}
}

// for printing
void WordTree::inOrder(Node* aNode, std::ostream& ostr) {
	if (aNode != nullptr) {
		ostr << "[";
		inOrder(aNode->_left, ostr);
		ostr << aNode->_value << ":" << aNode->_count << ":" << aNode->_height;
		inOrder(aNode->_right, ostr);
		ostr << "]";
	}
}

// used for finding a particular node
Node* WordTree::find(Node* aNode, const string& element) {
	if (aNode == nullptr)
	{
		//cout << "Key not found" << endl;
		return nullptr;
	}
	if (aNode->_value == element)
		return aNode;
	if (element < aNode->_value)
		return find(aNode->_left, element);
	return find(aNode->_right, element);
}

// calls findHelper
Node* WordTree::find(const string& element) {
	return find(_root, element);
}

// used for rotating a node left
Node* WordTree::leftRotation(Node* aNode) {
	if (aNode and aNode->_right)
	{
		// new node to pointer
		// child will get assigned aNode's pointers
		Node* child = aNode->_right;
		aNode->_right = child->_left;
		child->_left = aNode;

		// reassigning parents
		child->_parent = aNode->_parent;
		aNode->_parent = child;

		//updating height
		updateHeight(aNode);
		updateHeight(child);

		// return new root
		return child;
	}
	//return unchanged pointer
	return aNode;
}

// used for rotating a node right
Node* WordTree::rightRotation(Node* aNode) {
	if (aNode and aNode->_left)
	{
		// new node to pointer
		// child will get assigned aNode's pointers
		Node* child = aNode->_left;
		aNode->_left = child->_right;
		child->_right = aNode;

		// reassigning parents
		child->_parent = aNode->_parent;
		aNode->_parent = child;

		//updating height
		updateHeight(aNode);
		updateHeight(child);

		// return new root
		return child;
	}
	// return unchanged pointer
	return aNode;
}

// used to checkBalance of node passed in
int WordTree::checkBalance(Node* aNode) {
	int lHeight = -1, rHeight = -1;

	if (aNode->_left)
		lHeight = aNode->_left->_height;
	if (aNode->_right)
		rHeight = aNode->_right->_height;

	return lHeight - rHeight;
}

// used to reBalance newly added nodes
Node* WordTree::reBalance(Node* aNode) {

	// balance factor variables
	int balance = 0, leftBalance = 0, rightBalance = 0;
	// checks for left/right validity
	// gets balance factors that determine rotation
	if (aNode->_left)
		leftBalance = checkBalance(aNode->_left);
	if (aNode->_right)
		rightBalance = checkBalance(aNode->_right);

	// check validity for aNode
	if (aNode)
	{
		// gets balance for aNode
		balance = checkBalance(aNode);
		// checks validity of aNode left/right
		if (aNode->_left)
			leftBalance = checkBalance(aNode->_left);
		if (aNode->_right)
			rightBalance = checkBalance(aNode->_right);

		// if balance factor in favor of left subtree
		if (balance > 1)
		{
			// performs right rotation when left subtree is unbalanced
			if (leftBalance >= 0)
			{
				return aNode = rightRotation(aNode);
			}
			else
			{
				// performs left right rotation when balance > 1 but left balance < 0
				aNode->_left = leftRotation(aNode->_left);
				return aNode = rightRotation(aNode);
			}
		}
		// if balance in favor of right subtree
		else if (balance < -1)
		{
			// performs left rotation when right subtree is unbalanced
			if (rightBalance <= 0)
			{
				return aNode = leftRotation(aNode);
			}
			else
			{
				// performs right left rotation when balance < -1 but right balance > 0
				aNode->_right = rightRotation(aNode->_right);
				return aNode = leftRotation(aNode);
			}
		}
	}
	// return the unchanged node pointer
	return aNode;
}

// calls insertHelper
void WordTree::insert(const string& element) {
	// just calls insert and insert helper returns rebalanced node
	_root = insert(element, _root);
}

// used to recursively insert
Node* WordTree::insert(const string& element, Node*& aNode) {

	// if node is nullptr
	if (aNode == nullptr)
	{
		// make a new node and count++
		aNode = new Node(element);
		aNode->_count++;
		return aNode;
	}
	// if element is less than aNode then it traverses left subtree
	else if (element < aNode->_value)
	{
		// makes left child and assign parents
		Node* lChild = insert(element, aNode->_left);
		aNode->_left = lChild;
		lChild->_parent = aNode;
	}
	// if element is greater than aNode then it traverses right subtree
	else if (element > aNode->_value)
	{
		// makes right child and assigns parents
		Node* rChild = insert(element, aNode->_right);
		aNode->_right = rChild;
		rChild->_parent = aNode;
	}
	else
	{
		// node already exists so count++
		aNode->_count++;
		return aNode;
	}

	//updates height because that is needs for rebalancing
	updateHeight(aNode);
	aNode = reBalance(aNode);

	// returns rebalanced node
	return aNode;
}

// dump the tree
void WordTree::dump(std::ostream& ostr) {
	inOrder(_root, ostr);
}

// calls searchCountHelp
int WordTree::searchCount(string word) {

	// calls searchCountHelp which does most of the work
	return searchCountHelp(_root, word, 0);
}

// used to find count of nodes visited
int WordTree::searchCountHelp(Node* aNode, string word, int counter) {

	// traverses and increases count
	if (word == aNode->_value)
	{
		return counter;
	}
	else if (word < aNode->_value and aNode->_left)
		counter = 1 + searchCountHelp(aNode->_left, word, counter);
	else if (word > aNode->_value and aNode->_right)
		counter = 1 + searchCountHelp(aNode->_right, word, counter);
	else
		return counter;
	return counter;
}

// used to get roots height
int WordTree::getRootHeight() {

	//gets root height
	if (_root == nullptr)
		return -1;
	return _root->_height;
}

// calls getNodeHeightHelp
int WordTree::getNodeHeight(string word) {
	return getNodeHeightHelp(_root, word);
}

// used to get certain node height
int WordTree::getNodeHeightHelp(Node* aNode, string word) {

	// traverses and gets corresponding node height
	if (word == aNode->_value)
	{
		return aNode->_height;
	}
	else if (word < aNode->_value)
		getNodeHeightHelp(aNode->_left, word);
	else if (word > aNode->_value)
		getNodeHeightHelp(aNode->_right, word);
	return -1;
}