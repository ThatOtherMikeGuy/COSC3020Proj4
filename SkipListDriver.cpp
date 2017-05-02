// Zephaniah Connell, Michael Schwindt, and Marcus Rieker
// COSC 3020 Project 4
// Skip List: Search, Insert, Delete
// SkipListDriver.cpp
// 04-29-17
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <random>

#include "SkipList.h"

using namespace std;

int randNumGen(int bottom, int top)
{
	random_device rand_dev;
	mt19937 generator(rand_dev());
	uniform_int_distribution<int> distr(bottom, top);
	int seed = distr(generator);
	return seed;
}

int main()
{
	SkipList ss;
	int choice, n, testNum, randomNum;
	vector<int> randomNumHolder;
	while (1)
	{
		cout << endl << "-----------------------" << endl;
		cout << endl << "Operations on Skip list" << endl;
		cout << endl << "-----------------------" << endl;
		cout << "1.Insert Element" << endl;
		cout << "2.Delete Element" << endl;
		cout << "3.Search Element" << endl;
		cout << "4.Display List " << endl;
		cout << "5.Testing " << endl;
		cout << "6.Clear Testing List (only works when used after 5 was chosen)" << endl;
		cout << "7.Exit " << endl;
		cout << "Enter your choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter the element to be inserted: ";
			cin >> n;
			ss.insert(n);
			if (ss.search(n))
				cout << "Element Inserted" << endl;
			break;
		case 2:
			cout << "Enter the element to be deleted: ";
			cin >> n;
			if (!ss.search(n))
			{
				cout << "Element not found" << endl;
				break;
			}
			ss.remove(n);
			if (!ss.search(n))
				cout << "Element Deleted" << endl;
			break;
		case 3:
			cout << "Enter the element to be searched: ";
			cin >> n;
			if (ss.search(n))
				cout << "Element " << n << " is in the list" << endl;
			else
				cout << "Element not found" << endl;
		case 4:
			cout << "The List is: ";
			ss.display();
			break;
		case 5:
			cout << "Enter how many elements you want to be inserted: " << endl;
			cin >> testNum;
			cout << "OK. Making a skip list with " << testNum << " numbers." << endl
				<< "Please wait." << endl;
			for (int i = 0; i < testNum; i++)
			{
				if (i == testNum / 2)
				{
					cout << "Half way done." << endl;
				}
				randomNum = randNumGen(1,1000);
				randomNumHolder.push_back(randomNum);
				ss.insert(randomNum);
			}
			break;
		case 6:
			cout << "Clearing the list. " << endl
				<< "Please wait." << endl;
			for (int i = 0; i < randomNumHolder.size(); i++)
			{
				if (i == randomNumHolder.size() / 2)
				{
					cout << "Half way done." << endl;
				}
				ss.remove(randomNumHolder[i]);
			}
			randomNumHolder.clear();
			cout << "OK. Cleared the skip list for you." << endl;
			break;
		case 7:
			exit(1);
			break;
		default:
			cout << "Wrong Choice" << endl;
		}
	}
	return 0;
}
