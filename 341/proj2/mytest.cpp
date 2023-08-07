/*
	Author: Denish Pasupuleti
	Date: 10/20/2020
	Description: Test file for Proj2
*/
#include "bookTree.h"

using namespace std;

/*
	wordTreeTest()
	Pre condition: none
	Post condition: Tests every public function of WordTree
*/
void wordTreeTest()
{
	WordTree tree;
	tree.insert("cherry");
	tree.insert("apple");
	tree.insert("plum");
	tree.insert("banana");
	tree.insert("orange");
	tree.insert("tomato");
	tree.insert("apple");
	tree.insert("azzle");
	tree.insert("zebra");
	tree.insert("abs");

	// dumping tree
	cout << endl;
	cout << "Testing using sample tree provided in project website with some additions" << endl;
	tree.dump();
	// root height
	cout << endl << "Root height: ";
	cout << tree.getRootHeight() << endl;

	// testing find function
	cout << "******Testing find function******" << endl;
	cout << "Finding apple: " << tree.find("apple")->getValue() << endl;
	cout << "Finding apple height: " << tree.find("apple")->getHeight() << endl;
	cout << "Finding apple frequency: " << tree.find("apple")->getFrequency() << endl;

	// testing for word "cmsc341"(not in the tree)
	cout << "Finding cmsc341(not in the tree) should return nullptr" << endl;
	if (tree.find("cmsc341") == nullptr)
		cout << "cmsc341 is not in the tree and thus has returned a nullptr" << endl;
	cout << endl;

	//testing search count function
	cout << "******Testing searchCount function******" << endl;
	cout << "Search count for abs(should print 3): " << tree.searchCount("abs") << endl;
	cout << "Search count for apple(should print 2): " << tree.searchCount("apple") << endl;
	cout << "Search count for cherry(root): " << tree.searchCount("cherry") << endl;

	// testing for non existent word
	cout << "Search count for ab(not in the tree and should return 3): ";
	cout << tree.searchCount("ab") << endl;

	// testing getRootHeight function
	cout << "Root Height(cherry and should print 3): " << tree.getRootHeight() << endl;
	cout << endl;

	cout << "************TESTING WITH DOUBLE ROTATIONS************" << endl;

	WordTree aTree;
	aTree.insert("It");
	aTree.insert("was");
	aTree.insert("a"); // double rotate left
	aTree.insert("queer");
	aTree.insert("sort"); // double rotate right
	aTree.insert("of"); // double rotate left
	aTree.insert("place");
	aTree.insert("—"); // single rotate left(single left)
	aTree.insert("a");

	aTree.dump();
	// root height
	cout << endl << "Root height: ";
	cout << aTree.getRootHeight() << endl;
	cout << endl;

	cout << "************SECOND TEST WITH DOUBLE ROTATIONS************" << endl;

	WordTree bTree;
	bTree.insert("a");
	bTree.insert("c");
	bTree.insert("b");

	bTree.dump();
	// root height
	cout << endl << "Root height: ";
	cout << bTree.getRootHeight() << endl;
}

/*
	bookTreeTest()
	Pre condition: none
	Post condition: Tests every public function of BookTree
*/
void bookTreeTest()
{
	cout << endl;
	BookTree aTree;
	aTree.loadData("data.txt");

	cout << "Testing various functions of BookTree" << endl;
	// testing using sample test case from driver.cpp
	cout << "Frequency of tinsmith in The Wonderful Wizard of Oz: " << endl;
	cout << "\t" << aTree.findFrequency("the wonderful wizard of oz", "tinsmith") << endl << endl;
	cout << "Count of search operation for tinsmith in The Wonderful Wizard of Oz: " << endl;
	cout << "\t" << aTree.searchCount("the wonderful wizard of oz", "tinsmith") << endl << endl;
	cout << "Height of the node containing tinsmith in The Wonderful Wizard of Oz: " << endl;
	cout << "\t" << aTree.getWordHeight("the wonderful wizard of oz", "tinsmith") << endl << endl;
	cout << "Height of word tree for The Wonderful Wizard of Oz: " << endl;
	cout << "\t" << aTree.getTextTreeHeight("the wonderful wizard of oz") << endl << endl;
	cout << "Dumping the word tree for The Wonderful Wizard of Oz:" << endl << endl;
	aTree.dumpTitle("the wonderful wizard of oz");
	cout << endl;

	cout << endl << "******Testing with different test case******" << endl;
	BookTree bTree;
	bTree.loadData("dataT.txt");
	bTree.dumpTitle("juice");
	cout << endl;

	cout << endl << "******Testing with 1 book******" << endl;
	BookTree cTree;
	cTree.loadData("dataOneBook.txt");
	cTree.dumpTitle("nerd");
	cout << endl;

	cout << endl << "******Testing with no text******" << endl;
	BookTree dTree;
	dTree.loadData("dataNoTest.txt");
	dTree.dumpTitle("nerd");
	cout << endl;

	cout << "******Testing with no text******" << endl;
	BookTree eTree;
	eTree.loadData("dataNoTest.txt");
	eTree.dumpTitle("nerd");
	cout << endl;

	cout << "******Testing with no book******" << endl;
	BookTree fTree;
	fTree.loadData("dataEmpty.txt");
	fTree.dumpTitle("nerd");
	cout << endl;
}

int main() {
	wordTreeTest();
	bookTreeTest();
}