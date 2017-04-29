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

		Node::Node()
		{
			element = -99999999;
		}

		Node::Node(int e, vector<Node*> a)
		{
			element = e;
			next = a;
		}
	};

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

	Node structure;
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
		}
		return found;
	}

	void SkipList::insert(int numberToInsert)
	{
		vector<Node*> nodePointers;
		nodePointers.push_back(nullptr);
		Node nodeToInsert(numberToInsert, nodePointers);
		int highestLevel = 0;

		// Skiplist is empty. Create the first level
		if (structure.empty())
		{
			structure.push_back(&nodeToInsert);
			return;
		}

		if (size == 2 ^ structure.size()) // skiplist contains enough elements for another level
		{
			// add another level and include numberToInsert in that level
			structure.push_back(nullptr);
			highestLevel = structure.size() - 1;
			for (int i = 1; i < highestLevel; i++)
			{
				nodeToInsert.next.push_back(nullptr);
			}
		}
		else
		{
			// determine pseudo-randomly the highest level numberToInsert exists in
			for (int i = 1; i < structure.size(); i++)
			{
				if (addToLevel() && highestLevel == i-1)
				{
					nodeToInsert.next.push_back(nullptr);
					highestLevel = i;
				}
			}
		}

		// insert numberToInsert in the proper location within skiplist
		Node* currentPointer = structure[structure.size() - 1];
		vector<Node*> tmp;
		for (int i = structure.size() - 1; i >= 0; i--)
		{
			while (currentPointer->next[i] != NULL && currentPointer->element < numberToInsert)
			{
				currentPointer = currentPointer->next[i];
			}
			if (i <= highestLevel)
			{
				tmp.push_back(currentPointer);
			}
		}

		// increment the total number of elements in the skiplist
		size++;
	}

	void SkipList::remove(int numberToRemove)
	{

	}

	double SkipList::size()
	{
		return size;
	}

	void SkipList::display()
	{
		const Node *currentPointer = structure[0];
		while (currentPointer != NULL)
		{
			cout << currentPointer->element;
			currentPointer = currentPointer->next[0];
			if (currentPointer != NULL)
				cout << " - ";
		}
		cout << endl;
	}
};
