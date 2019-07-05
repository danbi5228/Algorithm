#include <iostream>
using namespace std;


int Array[12] = { 0, };

int main() {

	int caseNum = 0;
	int input = 0;

	int rArray[100] = { 0, };

	cin >> caseNum;

	Array[1] = 1;
	Array[2] = 2;
	Array[3] = 4;

	for (int i = 0; i < caseNum; i++) {
		cin >> input;

		for (int j = 1; j <= input; j++) {
			if (Array[j] > 0) continue;
			else Array[j] = Array[j - 1] + Array[j - 2] + Array[j - 3];
		}

		rArray[i] = Array[input];

	}

	for (int i = 0; i < caseNum; i++) {
		cout << rArray[i] << endl;
	}
	

	return 0;
}