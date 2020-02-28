//File: Main.cpp
//Author: Jairun Diemert
//Class: COP3014
//Project: 3
//Description: This is the Main file.
#include <iostream>
using namespace std;

#include "Transaction.h"

int main() {
	
	Transaction *sale[10];
	for (int i = 0; i < 10; i++) {
		sale[i] = new Transaction;
	}
	//Test data if needed
	/*sale[0] = new Transaction(1, 1, 1, "one", 1, 2);
	sale[1] = new Transaction(2, 2, 2, "two", 2, 3);
	sale[2] = new Transaction(3, 3, 3, "three", 3, 5);
	sale[3] = new Transaction(20, 4, 4, "four", 4, 23);
	sale[5] = new Transaction(6, 6, 6, "six", 6, 63);
	sale[6] = new Transaction(12, 7, 7, "seven", 7, 25);
	sale[7] = new Transaction(8, 8, 8, "eight", 8, 78);
	sale[8] = new Transaction(9, 9, 9, "nine", 9, 2);
	sale[9] = new Transaction(12, 9, 9, "ten", 9, 0);*/ 

	int h;
	int m;
	int s;
	string n;
	int c;
	int p;
	int sumEarnings;
	int saleCounter;
	int transNum;
	Transaction temp;

	bool end = false;
	bool end2 = false;

	while (!end) {
		system("CLS");

		char option = '0';

		cout << endl;
		cout << "Please choose an option below" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "1. Enter a transaction." << endl;
		cout << "2. Print transaction summary." << endl;
		cout << "3. Void a transaction." << endl;
		cout << "4. End Program." << endl;
		cout << ": ";
		cin >> option;
		switch (option) {
		case '1':
			int i;
			system("CLS");
			for (i = 0; i < 10; i++) {
				if (sale[i]->GetH() == -1) {
					cout << endl;
					cout << "Enter the Hour using 0-23 integer notation: ";
					cin >> h;
					sale[i]->SetH(h);
					cout << endl << endl;

					cout << "Enter the Min using 0-59 integer notation: ";
					cin >> m;
					sale[i]->SetM(m);
					cout << endl << endl;

					cout << "Enter the second using 0-59 integer notation: ";
					cin >> s;
					sale[i]->SetS(s);
					cout << endl << endl;

					sale[i]->SetT();

					cout << "Enter the name using lower case letters with no spaces: ";
					cin >> n;
					sale[i]->SetN(n);
					cout << endl << endl;

					cout << "Enter the cost using rounded integer notation: ";
					cin >> c;
					sale[i]->SetC(c);
					cout << endl << endl;

					cout << "Enter the price using rounded integer notation: ";
					cin >> p;
					sale[i]->SetP(p);
					cout << endl << endl;

					sale[i]->SetE();
					cout << "\tTransaction added." << endl << endl;
					break;
				}
			}
			if (i > 9) {
				cout << endl << "\tThere is no more space for new transactions." << endl << endl;
			}
			system("pause");
			break;
		case '2':
			end2 = false;
			while (!end2) {
				system("CLS");

				char option2 = '0';

				cout << endl;
				cout << "Please choose an option below" << endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "1. Sort summary by trans#." << endl;
				cout << "2. Sort summary by earnings." << endl;
				cout << "3. Sort summary alphabetically." << endl;
				cout << ": ";
				cin >> option2;
				switch (option2) {
				case '1':
					system("CLS");
					cout << endl;
					for (int i = 0; i < 10; i++)
					{
						for (int j = i + 1; j < 10; j++) {
							if (sale[j]->GetT() < sale[i]->GetT()) {
								temp = *sale[i];
								*sale[i] = *sale[j];
								*sale[j] = temp;
							}
						}
					}
					cout << endl;
					end2 = true;
					break;
				case '2':
					system("CLS");
					cout << endl;
					for (int i = 0; i < 10; i++)
					{
						for (int j = i + 1; j < 10; j++) {
							if (sale[j]->GetE() < sale[i]->GetE()) {
								temp = *sale[i];
								*sale[i] = *sale[j];
								*sale[j] = temp;
							}
						}
					}
					cout << endl;
					end2 = true;
					break;
				case '3':
					system("CLS");
					cout << endl;
					for (int i = 0; i < 10; i++)
					{
						for (int j = i + 1; j < 10; j++) {
							if (sale[j]->GetN() < sale[i]->GetN()) {
								temp = *sale[i];
								*sale[i] = *sale[j];
								*sale[j] = temp;
							}
						}
					}
					cout << endl;
					end2 = true;
					break;
				default:
					cout << "\tYour entry was invalid please try again." << endl;
					break;
				}
			}

			system("CLS");
			saleCounter = 0;
			sumEarnings = 0;
			cout << endl;
			cout << "(TRANS#) HOUR:MIN:SEC NAME[ PRICE - COST = EARNINGS ]" << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			for (int i = 0; i < 10; i++) {
				if (sale[i]->GetH() != -1) {
					cout << "\t(" << sale[i]->GetT() << ") ";
					cout << sale[i]->GetH() << ":";
					cout << sale[i]->GetM() << ":";
					cout << sale[i]->GetS() << " ";
					cout << sale[i]->GetN() << " [ $";
					cout << sale[i]->GetP() << " - $";
					cout << sale[i]->GetC() << " = $";
					cout << sale[i]->GetE() << " ]" << endl;
					sumEarnings = sumEarnings + sale[i]->GetE();
					saleCounter++;
				}
			}
			if (saleCounter != 0) {
				cout << endl << endl << "\tThe total profit for the day is: $" << sumEarnings << endl << endl;
				cout << "\tThe average profit for each item is: $" << sumEarnings / (saleCounter) << endl << endl;
			}
			if (saleCounter == 0) {
				cout << "\tThere are no transactions to show." << endl << endl;
			}
			system("pause");
			break;
		case '3':
			system("CLS");
			int k;
			cout << endl;
			cout << "Enter the item# you wish to void: ";
			cin >> transNum;
			for (k = 0; k < 10; k++) {
				if (sale[k]->GetT() == transNum) {
					h = -1;
					sale[k]->SetH(h);
					cout << endl << "\tTransaction " << transNum << " voided." << endl << endl;
					break;
				}
			}
			if (k == 10) {
				cout << endl << "\tThe trans# you entered is invalid." << endl << endl;
			}
			system("pause");
			break;
		case '4':
			end = true;
			break;
		default:
			system("CLS");
			cout << endl<< "\tYour entry was invalid please try again." << endl << endl;
			system("pause");
			break;
		}
	}
	return 0;
}