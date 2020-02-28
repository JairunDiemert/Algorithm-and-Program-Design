//File: Transaction.cpp
//Author: Jairun Diemert
//Class: COP3014
//Project: 3
//Description: This is the member function file for Transaction.

#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

#include "Transaction.h"

Transaction::Transaction() {
	srand(time(NULL));
	hour = -1;
	min = -1;
	sec = -1;
	trans = -1;
	name = "Empty";
	cost = 0;
	price = 0;
	earnings = 0;
};
Transaction::Transaction(int h, int m, int s, string n, int c, int p) {
	hour = h;
	min = m;
	sec = s;
	trans = rand() % 1000 + 1;
	name = n;
	cost = c;
	price = p;
	earnings = price - cost;
};
Transaction::~Transaction() {
};

int Transaction::GetH() {
	return hour;
};
void Transaction::SetH(int h) {
	hour = h;
};

int Transaction::GetM() {
	return min;
};
void Transaction::SetM(int m) {
	min = m;
};

int Transaction::GetS() {
	return sec;
};
void Transaction::SetS(int s) {
	sec = s;
};

int Transaction::GetT() {
	return trans;
};
void Transaction::SetT() {
	trans = rand() % 1000 + 1;
};

string Transaction::GetN() {
	return name;
};
void Transaction::SetN(string n) {
	name = n;
};

int Transaction::GetC() {
	return cost;
};
void Transaction::SetC(int c) {
	cost = c;
};

int Transaction::GetP() {
	return price;
};
void Transaction::SetP(int p) {
	price = p;
};

int Transaction::GetE() {
	return earnings;
};
void Transaction::SetE() {
	earnings = price - cost;
};
