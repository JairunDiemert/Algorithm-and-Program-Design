
#include <iostream>
using namespace std;

int main() {
	const int NUM_ELEMENTS = 3;  // Number of elements
	int userVals[NUM_ELEMENTS];  // Array of user numbers
	int i;                       // Loop index
	int maxVal;                  // Computed max
	int minVal;					//Computed min
	int avgVal;					//Computed Avg
	int sumVal;					//Computed Sum

	// Prompt user to populate array
	cout << "Enter " << NUM_ELEMENTS << " integer values..." << endl;

	for (i = 0; i < NUM_ELEMENTS; ++i) {
		cout << "Value: ";
		cin >> userVals[i];
	}

	// Determine largest (max) number
	maxVal = userVals[0];        // Largest so far

	for (i = 0; i < NUM_ELEMENTS; ++i) {
		if (userVals[i] > maxVal) {
			maxVal = userVals[i];
		}
	}
	cout << "Max: " << maxVal << endl;

	// Determine smallest (min) number
	minVal = userVals[0];        // Smallest so far

	for (i = 0; i < NUM_ELEMENTS; ++i) {
		if (userVals[i] < minVal) {
			minVal = userVals[i];
		}
	}
	cout << "Min: " << minVal << endl;

	sumVal = 0;

	for (i = 0; i < NUM_ELEMENTS; ++i) {
		sumVal = sumVal + userVals[i];
	}
	cout << "Avg: " << sumVal / NUM_ELEMENTS << endl;

	for (i = 0; i < NUM_ELEMENTS; ++i) {

	}

	for (int i = 0; i < NUM_ELEMENTS; ++i) {
		cout << userVals[i] << ' ';
	}

	cout << endl;

	int temp;
	for (int i = 0; i < NUM_ELEMENTS / 2; ++i) {
		temp = userVals[i];
		userVals[i] = userVals[NUM_ELEMENTS - i - 1];
		userVals[NUM_ELEMENTS - i - 1] = temp;		
	}

	for (int i = 0; i < NUM_ELEMENTS; ++i) {
		cout << userVals[i] << ' ';
	}

	cout << "This is the array reversed." << endl;

	system("pause");
	return 0;
}
