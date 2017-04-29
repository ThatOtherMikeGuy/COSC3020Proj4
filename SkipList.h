// Zephaniah Connell, Michael Schwindt, and Marcus Rieker
// COSC 3020 Project 4
// Skip List: Search, Insert, Delete
// SkipList.h
// 04-29-17

using namespace std;

#include <vector>;

class SkipList
{
private:
	// Nodes provide access to element and the previous and next nodes
	class Node
	{
		Node* before;
		int element;
		Node* after;

		Node::Node(Node* b, int e, Node* a)
		{
			before = b;
			element = e;
			after = a;
		}
	};

	vector<Node> structure;
	
public:

	SkipList::SkipList()
	{
		// test comment
		// You suck!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		//ok
	}

	void SkipList::search()
	{

	}

	void SkipList::insert()
	{

	}

	void SkipList::remove()
	{

	}
};