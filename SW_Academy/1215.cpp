#include "pch.h"
#include <iostream>
using namespace std;

int main(void) {
	int testNum, idx = 0;
	testNum = 10;

	while (testNum > 0) {
		int result = 0; // 회문 개수
		int wordSize;
		char arr[8][8];
		cin >> wordSize;

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> arr[i][j];
			}
		}

		//가로
		bool flag = true;
		for (int i = 0; i < 8; i++) {
			for (int k = 0; k <= 8 - wordSize; k++) {
				for (int j = 0; j < wordSize; j++) {
					if (arr[i][k + j] != arr[i][wordSize + k - j - 1]) {
						flag = false;
					}
				}
				if (flag == true) result++;
				else flag = true;
			}
		}

		//세로
		flag = true;
		for (int i = 0; i < 8; i++) {
			for (int k = 0; k <= 8 - wordSize; k++) {
				for (int j = 0; j < wordSize; j++) {
					if (arr[k + j][i] != arr[wordSize + k - j - 1][i]) {
						flag = false;
					}
				}
				if (flag == true) result++;
				else flag = true;
			}
		}
		idx++;
		cout << "#" << idx << " " << result;
		testNum--;
	}
}