// Zephaniah Connell, Michael Schwindt, and Marcus Rieker
// COSC 3020 Project 4
// Skip List: Search, Insert, Delete
// SkipList.h
// 04-29-17

using namespace std;

#include <vector>;
#include <random>;

class SkipList
{
private:

	// Node provides access to element and a vector of pointers to Nodes
	class Node
	{
	public:

		int element;
		vector<Node*> next;

		Node::Node(int e, vector<Node*> a)
		{
			element = e;
			next = a;
		}
	};

	// Obtain the Node that this element will come after
	bool SkipList::search(int numberToFind,Node & n)
	{
		bool found = false;
		// look for top level of nodes
		// determin whether to look left or right // from current spot
		// look for next top level
		// go back to top
		return found;
	}

	// choose whether or not the element will be added to a level
	bool addToLevel()
	{
		int addit = rand() % 2;
		if (addit == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	vector<Node*> structure;
	double size;
	
public:

	SkipList::SkipList()
	{
		size = 0;
	}

	bool SkipList::search(int numberToFind)
	{
		bool found = false;
		
		Node *currentNode = structure[structure.size() -1];
		for (int i = structure.size() - 1; i >= 0; i--)
		{
			while (currentNode->next[i] != NULL && currentNode->next[i]->element < numberToFind)
			{
				currentNode = currentNode->next[i];
			}
		}
		currentNode = currentNode->next[0];
		if(currentNode != NULL && currentNode->element == numberToFind)
		{
			found = true;
			return found;
		}
		return found;
	}

	void SkipList::insert(int numberToInsert)
	{
		vector<Node*> nodePointers;
		int highestLevel;

		// Skiplist is empty. Create the first level
		if (structure.empty())
		{
			nodePointers.push_back(nullptr);
			Node nodeToInsert(numberToInsert, nodePointers);
			structure.push_back(&nodeToInsert);
			return;
		}

		// skiplist contains enough elements for another level, add another level
		if (size == 2 ^ structure.size())
		{
			structure.push_back(nullptr);
			highestLevel = structure.size() - 1;
		}

		// insert the element somewhere in the existing skiplist
		

		size++;
	}

	void SkipList::remove(int numberToRemove)
	{

	}

	double size()
	{
		return size;
	}
};
