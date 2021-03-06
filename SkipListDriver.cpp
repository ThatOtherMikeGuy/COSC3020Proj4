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
#include "winTImer.h"

using namespace std;

int main()
{
	SkipList ss;
	int choice, n, testNum, randomNum;
	vector<int> randomNumHolder;
	bool empty = true, found = false;
	random_device rand_dev;
	mt19937 generator(rand_dev());
	uniform_int_distribution<int> distr(1, 10000000);

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
		cout << "6.Clear List " << endl;
		cout << "7.Exit " << endl;
		cout << "Enter your choice : ";
		cin >> choice;
		Timer insertTimer;
		Timer deleteTimer;
		Timer searchTimer;
		switch (choice)
		{
		case 1:
			cout << "Enter the element to be inserted: ";
			cin >> n;
			insertTimer.start();
			ss.insert(n);
			insertTimer.stop();
			empty = false;
			randomNumHolder.push_back(n);
			cout << endl << "Element (" << n << ") was inserted into Skiplist." << endl;
			cout << "Time: " << insertTimer() << endl;
			break;
		case 2:
			cout << "Enter the element to be deleted: ";
			cin >> n;
			deleteTimer.start();
			ss.remove(n,found);
			deleteTimer.stop();
			if (found)
				cout << endl << "Element (" << n << ") was removed from Skiplist." << endl;
			else
				cout << endl << "Element (" << n << ") wasn't in the Skiplist." << endl;
			if (ss.getSize() == 0)
				cout << endl << "Skiplist is empty." << endl;
			cout << "Time: " << deleteTimer() << endl;
			break;
		case 3:
			cout << "Enter the element to be searched: ";
			cin >> n;
			searchTimer.start();
			found = ss.search(n);
			searchTimer.stop();
			if (found)
				cout << endl << "Element (" << n << ") is in the Skiplist." << endl;
			else if (ss.getSize() == 0)
				cout << endl << "Skiplist is empty." << endl;
			else
				cout << endl << "Element (" << n << ") isn't in the Skiplist." << endl;
			cout << "Time: " << searchTimer() << endl;
			break;
		case 4:
			if (ss.getSize() == 0)
				cout << endl << "Skiplist is empty." << endl;
			else
				cout << endl << "The Skiplist is:" << endl;
			ss.display();
			break;
		case 5:
			cout << endl << "Enter the number of elements you want to be in the Skiplist: ";
			cin >> testNum;
			cout << endl;
			while (testNum < 1)
			{
				cout << endl << "Enter the number of elements you want to be in the Skiplist: ";
				cin >> testNum;
				cout << endl;
			}
			for (int i = 0; i < randomNumHolder.size(); i++)
			{
				if (i == 0)
					cout << "OK. Clearing existing list for you." << endl << "Please wait." << endl << endl;
				if (i == testNum / 2)
					cout << "Half way done." << endl << endl;
				ss.remove(randomNumHolder[i], empty);
			}
			cout << "Making a skip list with " << testNum << " elements." << endl << endl
				<< "Please wait." << endl << endl;
			randomNumHolder.clear();
			for (int i = 0; i < testNum; i++)
			{
				if (i == testNum / 2)
					cout << "Half way done." << endl << endl;
				randomNum = distr(generator);
				randomNumHolder.push_back(randomNum);
				ss.insert(randomNum);
			}
			cout << "OK. Made a Skiplist with " << testNum << " elements for you." << endl;
			break;
		case 6:
			for (int i = 0; i < randomNumHolder.size(); i++)
			{
				if (i == 0)
					cout << "OK. Clearing existing list for you." << endl << "Please wait." << endl << endl;
				if (i == testNum / 2)
					cout << "Half way done." << endl << endl;
				ss.remove(randomNumHolder[i],empty);
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
