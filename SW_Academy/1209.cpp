#include "pch.h"
#include <iostream>
using namespace std;

int main(void) {
	int testNum = 10;

	while (testNum > 0) {
		int idx, max = 0;
		int arr[100][100] = { 0 };
		cin >> idx;

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> arr[i][j];
			}
		}

		//행
		for (int i = 0; i < 100; i++) {
			int sum = 0;
			for (int j = 0; j < 100; j++) {
				sum += arr[i][j];
			}
			if (sum > max) max = sum;
		}

		//열
		for (int i = 0; i < 100; i++) {
			int sum = 0;
			for (int j = 0; j < 100; j++) {
				sum += arr[j][i];
			}
			if (sum > max) max = sum;
		}

		//오른쪽아래 방향 대각선
		int sum = 0;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				if(i==j){ 
					sum += arr[i][j];
					break;
				}
			}
		}
		if (sum > max) max = sum;

		for (int j = 0; j < 100; j++) {
			sum += arr[j][j];
		}

		//왼쪽아래 방향 대각선
		sum = 0;
		for (int i = 0; i < 100; i++) {
			for (int j = 99; j >= 0; j--) {
				if (i+j == 99) { 
					sum += arr[i][j];
					break;
				}
			}
		}
		if (sum > max) max = sum;

		cout << "#" << idx << " " << max << endl;
		testNum--;
	}
}