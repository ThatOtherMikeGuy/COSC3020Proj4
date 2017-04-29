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
		Node *currentNode = structure[structure.size() - 1];
		for (int i = structure.size() - 1; i >= 0; i--)
		{
			while (currentNode->next[i] != NULL && currentNode->next[i]->element < numberToFind)
			{
				currentNode = currentNode->next[i];
			}
		}
		currentNode = currentNode->next[0];
		if (currentNode != NULL && currentNode->element == numberToFind)
		{
			found = true;
			n = *currentNode;
			return found;
		
		}
		//else
		n = *currentNode;
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
		
		Node *currentPointer = structure[structure.size() -1];
		//currentPointer->element;
		for (int i = structure.size() - 1; i >= 0; i--)
		{
			while (currentPointer->next[i] != NULL && currentPointer->next[i]->element < numberToFind)
			{
				currentPointer = currentPointer->next[i];
			}
		}
		currentPointer = currentPointer->next[0];
		if(currentPointer != NULL && currentPointer->element == numberToFind)
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

		if (size == 2 ^ structure.size()) // skiplist contains enough elements for another level
		{
			// add another level and include numberToInsert in that level
			structure.push_back(nullptr);
			highestLevel = structure.size() - 1;
		}
		else
		{
			// determine pseudo-randomly the highest level numberToInsert exists in
			for (int i = 1; i < structure.size(); i++)
			{
				if (addToLevel() && highestLevel == i-1)
				{
					highestLevel = i;
				}
			}
		}

		// insert numberToInsert in the proper location within skiplist
		

		// increment the total number of elements in the skiplist
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
