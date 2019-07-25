#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int testNum, idx = 0;
	cin >> testNum;
	while (testNum > 0) {
		int result= -100000, arr1, arr2, move;
		cin >> arr1 >> arr2;
		vector<int> arr_1;
		vector<int> arr_2;

		int tmp = 0;
		for (int i = 0; i < arr1; i++) {
			cin >> tmp;
			arr_1.push_back(tmp);
		}
		for (int i = 0; i < arr2; i++) {
			cin >> tmp;
			arr_2.push_back(tmp);
		}

		if (arr_2.size() > arr_1.size()) {
			move = arr_2.size() - arr_1.size();

			for (int i = 0; i < move+1; i++) {
				tmp = 0;
				for (int j = 0; j < arr1; j++) {
					tmp = tmp + (arr_1[j] * arr_2[j+i]);
				}
				if (tmp > result) result = tmp;
			}
		}
		else {
			move = arr_1.size() - arr_2.size();

			for (int i = 0; i < move + 1; i++) {
				tmp = 0;
				for (int j = 0; j < arr2; j++) {
					tmp = tmp + (arr_2[j] * arr_1[j + i]);
				}
				if (tmp > result) result = tmp;
			}
		}
		

		idx++;
		cout << "#" << idx << " " << result << endl;
		testNum--;
	}
}