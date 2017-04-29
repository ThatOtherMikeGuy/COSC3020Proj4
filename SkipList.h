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

	// Nodes provide access to element and the previous and next nodes
	class Node
	{
	public:

		int element;
		vector<Node>* next;

		Node::Node( int e, vector<Node>* a)
		{
			element = e;
			next = a;
		}
	};

	// obtain the vectors of nodes that this element will fall between
	bool SkipList::search(int numberToFind,vector<Node> & n)
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

	vector<vector<Node>*> structure;
	double size;
	
public:

	SkipList::SkipList()
	{
		size = 0;
	}

	bool SkipList::search(int numberToFind)
	{
		bool found = false;
		/*
		Node *currentNode = header; // <-- needs to be whatever node is in skiplist
		for (int i = structure.size() - 1; i >= 0; i--)
		{
			while (currentNode->after[i] != NULL && currentNode->after[i]->value < numberToFind)
			{
				currentNode = currentNode->after[i];
			}
		}
		currentNode = currentNode->forw[0];
		if(currentNode != NULL && currentNode->value == NumberToFind)
		{
			found = true;
			return found;
		}
		return ;
		*/
		return found;
	}

	void SkipList::insert(int numberToInsert)
	{
		// if skiplist is empty create the first level
		if (structure.empty())
		{
			vector<Node> structureToInsert;
			Node nodeToInsert(numberToInsert, nullptr);
			structureToInsert.push_back(nodeToInsert);
			structure;
		}
		// skiplist contains enough elements for another level, add another level
		else if (size == 2 ^ structure.size())
		{
			Node nodeToInsert(numberToInsert, nullptr);
			structure.push_back(nodeToInsert);
		}
		// insert the element somewhere in the existing skiplist
		else
		{
			vector<Node> nextNodeStructure, thisNodeStructure;
			int highestLevel = 0;
			Node nodeToInsert(numberToInsert, nullptr);

			// obtain vectors of Nodes for elements in the skiplist adjacent to numberToInsert
			search(numberToInsert, nextNodeStructure);
			
			// decide which levels the element will exist in
			for (int i = 0; i < structure.size(); i++)
			{
				if (highestLevel == i) // element is added to lower level
				{
					if(addToLevel()); // 50/50 chance to add to current level
						highestLevel++;
				}
			}

			for (int i = 0; i < highestLevel; i++)
			{
				nodeToInsert.nodeStructure.push_back(nodeToInsert);

				Node* tmp;
				tmp = nextNode[i].next;
				nextNode[i].next = &nodeToInsert.nodeStructure[i];
				nodeToInsert. = 
			}


		}

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
