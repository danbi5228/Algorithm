#include "pch.h"
#include <iostream>
using namespace std;

int main(void) {
	int num10 = 10;
	while (num10--) {
		int idx;
		cin >> idx;

		int arr[8] = { 0 };
		for(int i = 0; i < 8; i++) {
			cin >> arr[i];
		}

		int num5 = 1;
		while (arr[7] != 0) {
			if (num5 == 6) num5 = 1;
			int a;

			a = arr[0] - num5;
			if (a <= 0) a = 0;
			
			for (int i = 0; i < 7; i++) {
				arr[i] = arr[i + 1];
			}
			arr[7] = a;

				//for (int i = 0; i < 8; i++) {
				//	cout << arr[i] << " ";
				//}
				//cout << endl;

			num5++;
		}

		cout << "#" << idx << " ";
		for (int i = 0; i < 8; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
}