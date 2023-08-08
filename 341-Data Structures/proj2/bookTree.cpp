/*
	Author: Denish Pasupuleti
	Date: 10/20/2020
	Description: BookTree component for proj2 and is a splay tree
*/
#include "bookTree.h"
BookTree::BookTree()
{
	_root = nullptr;
}

// destructs book tree object
BookTree::~BookTree() {
	// calls clear() to recursively delete tree
	clear(_root);
}

// splays the node accessed
BNode* BookTree::makeSplay(BNode* root, string key) {

	// if root is already the root of tree
	// if child nood is the splay node(left or right tree)
	// if root is within left subtree and is alligned
	// if root is within right subtree and is alligned
	// if root is left of parent and root's parent is right of roots grandparent
	// if root is right of parent and root's parent is left of roots grandparent
	// if root is already the root of tree

	if (key == _root->_key) {
		return root;
	}
	// if child nood is the splay node(left or right tree)
	else if (root->_parent != nullptr and root->_parent == _root)
	{
		if (_root->_left == root)
		{
			return rightRotate(root->_parent);
		}
		else if (_root->_right == root)
		{
			return leftRotate(root->_parent);
		}
	}
	// if root is within left subtree and is alligned
	else if (root->_parent and root->_parent->_parent)
	{
		if (root->_parent->_left == root and root->_parent->_parent->_left == root->_parent)
		{
			root = rightRotate(root->_parent);
			//root = rightRotate(root);
			root = makeSplay(root, key);
			return root;
		}
		// if root is within right subtree and is alligned
		else if (root->_parent->_right == root and root->_parent->_parent->_right == root->_parent)
		{
			root = leftRotate(root->_parent);
			//root = leftRotate(root);
			root = makeSplay(root, key);
			return root;
		}
		// inner case
		// if root is left of parent and root's parent is right of roots grandparent
		else if (root->_parent->_left == root and root->_parent->_parent->_right == root->_parent)
		{
			root = leftRotate(root->_parent);
			//root = rightRotate(root);
			root = makeSplay(root, key);
			return root;
		}
		// inner case
		// if root is right of parent and root's parent is left of roots grandparent
		else if (root->_parent->_right == root and root->_parent->_parent->_left == root->_parent)
		{
			root = rightRotate(root->_parent);
			//root = leftRotate(root);
			root = makeSplay(root, key);
			return root;
		}
	}
	return root;

}

// used to rotate node right
BNode* BookTree::rightRotate(BNode* x) {

	// checks for if x->_left exists and then rotates
	if (x and x->_left)
	{
		BNode* y;
		if (x->_left == nullptr)
		{
			y = nullptr;
			x->_left = nullptr;
		}
		else
		{
			// moving nodes so that they allign 
			y = x->_left;
			x->_left = y->_right;
			y->_right = x;
			// updating parents
			y->_parent = x->_parent;
			x->_parent = y;

			return y;
		}
		return x;
	}
	cout << "no rotation was done" << endl;
	return x;

}

// used to rotate node left
BNode* BookTree::leftRotate(BNode* x) {

	// checks if x right exists
	if (x and x->_right)
	{
		BNode* y;

		if (x->_right == nullptr)
		{
			y = nullptr;
			x->_right = nullptr;
		}
		else
		{
			// moving nodes so they allign
			y = x->_right;
			x->_right = y->_left;
			y->_left = x;

			// updating parents
			y->_parent = x->_parent;
			x->_parent = y;
			return y;
		}
		// else just return unchanged pointer
		return x;
	}
	return x;

}

// calls insertHelper to recurse insert
bool BookTree::insert(string key, string author, string text) {

	// checks for if key is valid
	if (key != "")
	{
		if (_root == nullptr) {
			// make root if not already there
			_root = new BNode(key, author, text);
			// make splay does not work properly
			//_root = makeSplay(_root, key);
			return true;
		}
		else {
			// if root exists then insert nodes and splay
			BNode* newNode = insertHelper(_root, key, author, text);

			if (newNode != nullptr)
			{
				// make splay does not work properly
				_root = newNode;
			}
			// checks for if dupe key in tree
			if (newNode->_flag)
				return false;
			else
				return true;
		}
	}
	else
		return false;
}

// recursively inserts new node
BNode* BookTree::insertHelper(BNode* aNode, string key, string author, string text) {

	// recursively moves through the tree to get desired node to add to
	if (aNode == nullptr) {
		// makes node
		aNode = new BNode(key, author, text);
		return aNode;
	}
	else if (key == aNode->_key) {
		aNode->_flag = true;
		return nullptr;
	}
	else if (key < aNode->_key) {
		BNode* lChild = insertHelper(aNode->_left, key, author, text);
		aNode->_left = lChild;
		// setting parents
		lChild->_parent = aNode;
	}
	else if (key > aNode->_key) {
		BNode* rChild = insertHelper(aNode->_right, key, author, text);
		aNode->_right = rChild;
		// settin parents
		rChild->_parent = aNode;
	}
	return aNode;
}

// recursively deletes each node
void BookTree::clear(BNode* root) {
	// recursively deletes tree
	if (root) {
		clear(root->_left);
		clear(root->_right);
		delete root;
	}
}

// dumping the tree
void BookTree::inorderHelp(BNode* root, bool verbose) const {
	if (root != nullptr) {
		if (verbose) {
			cout << "(";
			inorderHelp(root->_left, verbose);
			cout << root->_key << ":" << root->_author;
			root->_tree.dump();
			inorderHelp(root->_right, verbose);
			cout << ")";
		}
		else {
			inorderHelp(root->_left, verbose);
			cout << root->_key;
			inorderHelp(root->_right, verbose);
		}
	}
}

void BookTree::dump(bool verbose) const {
	inorderHelp(_root, verbose);
}

// used for finding frequency of word
int BookTree::findFrequency(string title, string word) {
	// finds node and gets frequency
	BNode* temp = find(_root, title);
	if (temp != nullptr)
	{
		int frequency = temp->findFrequency(word);
		// make splay does not work properly
		//_root = makeSplay(temp, title);
		return frequency;
	}
	return -1;
}

// used to dump specific title
void BookTree::dumpTitle(string title) {

	BNode* temp = find(_root, title);
	if (temp != nullptr)
	{
		temp->_tree.dump();
		// makeSplay does not work
		//_root = makeSplay(temp, title);
	}
	else
		cout << "Incorrect Title; No title was found" << endl;
}

// used to count visited nodes 
int BookTree::searchCount(string title, string word) {
	// finds node and returns searchCount
	BNode* temp = find(_root, title);
	if (temp != nullptr)
	{
		int count = temp->_tree.searchCount(word);
		// make splay does not work properly
		//_root = makeSplay(temp, title);
		return count;
	}
	return 0;
}

// used to find a certain node
BNode* BookTree::find(BNode* aNode, const string& key) {

	// recursively moves through the tree to find desired node
	if (aNode == nullptr)
	{
		cout << "Key not found" << endl;
		return nullptr;
	}
	if (aNode->_key == key)
		return aNode;
	if (key < aNode->_key and aNode->_left)
		return find(aNode->_left, key);
	else if (key > aNode->_key and aNode->_right)
		return find(aNode->_right, key);
}

// used to get certain BNode wordtree height
int BookTree::getTextTreeHeight(string title) {
	// finds node and returns height
	// if not found then returns -1
	int height = -1;
	BNode* temp = find(_root, title);
	if (temp != nullptr)
	{
		height = temp->_tree.getRootHeight();
		if (height == -1)
		{
			// make splay does not work properly
			//_root = makeSplay(temp, title);
			return -1;
		}
		// make splay does not work properly
		//_root = makeSplay(temp, title);
	}
	return height;
}

// used to get certain word height in wordtree's
int BookTree::getWordHeight(string title, string word) {
	// finds that certain node in wordtree and returns word height
	// if not then return -1
	BNode* temp = find(_root, title);
	Node* aNode = temp->_tree.find(word);
	if (aNode == nullptr)
	{
		// make splay does not work properly
		//_root = makeSplay(temp, title);
		return -1;
	}
	// make splay does not work properly
	//_root = makeSplay(temp, title);
	return aNode->getHeight();
}

// used to get root key
string BookTree::getRootKey() {
	return _root->_key;
}

// used to loadData and pass to insert
void BookTree::loadData(string dataFile) {
	//read the entire file at once
	std::ifstream t(dataFile);
	std::stringstream buffer;
	buffer << t.rdbuf();

	//time to parse the information
	string titleDelimiter = "<==>";
	string itemsDeleimiter = "<=>";
	string s = buffer.str();
	size_t pos = 0;
	string token;
	while ((pos = s.find(titleDelimiter)) != string::npos) {
		token = s.substr(0, pos);//token is complete data for one title
		//get the title
		int tempPos = token.find(itemsDeleimiter);
		string title = token.substr(0, tempPos);
		//convert title to lower case
		std::transform(title.begin(), title.end(), title.begin(), ::tolower);
		token.erase(0, tempPos + itemsDeleimiter.length() + 1);
		//get the author
		tempPos = token.find(itemsDeleimiter);
		string author = token.substr(0, tempPos);
		//convert author to lower case
		std::transform(author.begin(), author.end(), author.begin(), ::tolower);
		token.erase(0, tempPos + itemsDeleimiter.length() + 1);
		//get the text
		string text = token.substr(0, token.length() - 1);//remove last newline
		//clean up the text, remove all non-alphanumeric characters
		for (std::string::iterator iter = text.begin(); iter != text.end(); ) {
			if (!std::isalnum(*iter) && *iter != ' ')
				iter = text.erase(iter);
			else
				++iter; // not erased, increment iterator
		}
		//convert text to lower case
		std::transform(text.begin(), text.end(), text.begin(), ::tolower);

		insert(title, author, text);

		//move to info for the next title
		s.erase(0, pos + titleDelimiter.length() + 1);
	}
}