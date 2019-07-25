#include "pch.h"
#include <iostream>
using namespace std;

int main() {
	int testNum, idx = 0;
	cin >> testNum;

	while (testNum > 0) {
		int caseNum;
		int arr[7][7] = { 0 };

		cin >> caseNum;

		for (int i = 0; i < caseNum; i++) {
			for (int j = 0; j < caseNum; j++) {
				cin >> arr[i][j];
			}
		}

		idx++;
		cout << "#" << idx << endl;

		int tmp = 0;
		for (int i = 0; i < caseNum; i++) {
			for (int j = caseNum - 1; j >= 0; j--) {
				cout << arr[j][0 + tmp];
			}
			cout << " ";
			for (int j = caseNum - 1; j >= 0; j--) {
				cout << arr[caseNum - 1 - tmp][j];
			}
			cout << " ";
			for (int j = 0; j < caseNum; j++) {
				cout << arr[j][caseNum - 1 - tmp];
			}
			cout << endl;

			tmp++;
		}

		testNum--;
	}


	return 0;
}