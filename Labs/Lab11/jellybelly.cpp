#include "jellybelly.h"

int main()
{
	Jellybean beans[NUM_FLAVORS] = {};
	ifstream inFile;
	ofstream outFile;
	string data;
	int currentNum = 0, choice; //keeps track of how many kinds of jellybeans are in inventory right now

	cout << "\n\nWelcome to JellyBelly Factory!\n\n";

	//Load the inventory
	inFile.open("jellybellyinventory.txt");
	if (inFile.good())
	{
		getline(inFile, data, '*');
		while (!inFile.eof() && currentNum != NUM_FLAVORS)
		{
			beans[currentNum].poundPrice = stringToFloat(data);
			getline(inFile, data, '*');
			beans[currentNum].quantity = stringToFloat(data);
			getline(inFile, data, '*');
			beans[currentNum].rating = stringToFloat(data);
			getline(inFile, beans[currentNum].flavor, '*');
			getline(inFile, beans[currentNum].color, '*');

			currentNum++;
			getline(inFile, data, '*');
		}
		cout << "\n\nThere are currently " << currentNum << " items in inventory.\n\n";
		inFile.close();
	}
	else
	{
		cout << "\n\nThere are currently no items in inventory.\n\n";
	}

	do
	{
		choice = DisplayMenuGetChoice();

		switch (choice)
		{

		case 1:
			PrintInventory(currentNum, beans);
			break;

		case 2:
			PrintColor(currentNum, beans);
			break;

		case 3:
			currentNum = AddBeans(currentNum, beans);
			break;

		case 4:
			currentNum = deleteBeans(beans, currentNum);
			break;

		case 5:
			break;
		}
	} while (choice != 5);

	cout << "\n\nSaving inventory....\n\n";

	outFile.open("jellybellyinventory.txt");
	if (outFile.is_open())
		for (size_t i = 0; i < currentNum; ++i)
		{
			outFile << beans[i].poundPrice << "*" << beans[i].quantity << "*" << beans[i].rating << "*"
							<< beans[i].flavor << "*" << beans[i].color << "*";
		}

	cout << "Goodbye!\n\n";

	return 0;
}
