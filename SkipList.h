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

		Node::~Node()
		{
			for (int i = 0; i < next.size(); i++)
			{
				delete next[i];
			}
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
		
		Node *currentPointer = &structure;
		
		for (int i = structure.next.size() - 1; i >= 0; i--)
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
		Node* nodeToInsert = new Node(numberToInsert, nodePointers);
		int highestLevel = 0;

		// Skiplist is empty. Create the first level
		if (structure.next.empty())
		{
			structure.next.push_back(nodeToInsert);
			size++;
			return;
		}

		if (size == 2 ^ structure.next.size()) // skiplist contains enough elements for another level
		{
			// add another level and include numberToInsert in that level
			structure.next.push_back(nullptr);
			highestLevel = structure.next.size() - 1;
			for (int i = 0; i < highestLevel; i++)
			{
				nodeToInsert->next.push_back(nullptr);
			}
		}
		else
		{
			// determine pseudo-randomly the highest level numberToInsert exists in
			nodeToInsert->next.push_back(nullptr);
			for (int i = 1; i < structure.next.size(); i++)
			{
				if (addToLevel() && highestLevel == i-1)
				{
					nodeToInsert->next.push_back(nullptr);
					highestLevel = i;
				}
			}
		}

		// acquire all pointers that should be pointing to numberToInsert once it is inserted
		Node* currentPointer = &structure;
		vector<Node*> tmp;
		for (int i = 0; i <= highestLevel; i++)
		{
			tmp.push_back(nullptr);
		}
		for (int i = structure.next.size() - 1; i >= 0; i--)
		{
			while (currentPointer->next[i] != NULL && currentPointer->next[i]->element < numberToInsert)
			{
				currentPointer = currentPointer->next[i];
			}
			if (i <= highestLevel)
			{
				tmp[i] = currentPointer;
			}
		}

		// Rearrange pointers to effectively insert numberToInsert
		for (int i = 0; i <= highestLevel; i++)
		{
			nodeToInsert->next[i] = tmp[i]->next[i];
			tmp[i]->next[i] = nodeToInsert;
		}

		size++;
	}

	void SkipList::remove(int numberToRemove)
	{
		// Skiplist is empty. Create the first level
		if (structure.next.empty())
		{
			cout << endl << "Skiplist is empty." << endl;
			return;
		}

		// acquire all pointers that should be pointing to numberToInsert once it is inserted
		int highestLevel = 0;
		Node* currentPointer = &structure;
		vector<Node*> tmp;
		for (int i = 0; i < structure.next.size(); i++)
		{
			tmp.push_back(nullptr);
		}
		for (int i = structure.next.size() - 1; i >= 0; i--)
		{
			while (currentPointer->next[i] != NULL && currentPointer->next[i]->element < numberToRemove)
			{
				currentPointer = currentPointer->next[i];
			}
			if (currentPointer->next[i] != NULL && currentPointer->next[i]->element == numberToRemove)
			{
				tmp[i] = currentPointer;
				if (i < highestLevel)
				{
					highestLevel = i;
				}
			}
		}

		// Rearrange pointers to effectively insert numberToInsert
		Node* tmp;
		for (int i = 0; i <= highestLevel; i++)
		{
			//tmp = 
			//tmp[i]->next[i] = nodeToInsert;
		}
	}

	double SkipList::getSize()
	{
		return size;
	}

	void SkipList::display()
	{
		Node *currentPointer = structure.next[0];
		while (currentPointer != NULL)
		{
			cout << currentPointer->element;
			currentPointer = currentPointer->next[0];
			if (currentPointer != NULL)
				cout << "   ";
		}
		delete currentPointer;
		cout << endl;
	}
};
