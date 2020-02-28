//File: Transaction.h
//Author: Jairun Diemert
//Class: COP3014
//Project: 3
//Description: This is the header file for the Transaction class.

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <string>

using namespace std;

class Transaction {
public:
	Transaction();
	Transaction(int h, int m, int s, string n, int c, int p);
	~Transaction();
	
	int GetH();
	void SetH(int h);
	
	int GetM();
	void SetM(int m);
	
	int GetS();
	void SetS(int s);
	
	int GetT();
	void SetT();
	
	string GetN();
	void SetN(string n);
	
	int GetC();
	void SetC(int c);
	
	int GetP();
	void SetP(int p);

	int GetE();
	void SetE();

private:
	int hour;
	int min;
	int sec;
	int trans;
	string name;
	int cost;
	int price;
	int earnings;
};


#endif 
