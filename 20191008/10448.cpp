/*
성공

재귀로 풀어보자~~
3중포문 너무 안예쁘당~~~
*/

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int a = 1;
	vector <int> triangle;
	triangle.push_back(0);
	for (int i = 1; i < 46; i++) {
		a = i;
		a = (a * (a + 1)) / 2;
		triangle.push_back(a);
	}

	//for (int i = 1; i < 45; i++) {
	//	cout << triangle[i] << endl;
	//}

	int caseNum;
	cin >> caseNum;
	while (caseNum != 0) {
		int input_num;
		cin >> input_num;
		bool isNum_3 = 0;

		for (int i = 1; triangle[i] < input_num; i++) {
			if (isNum_3 == 1) break;
			for (int j = 1; triangle[j] < input_num; j++) {
				if (isNum_3 == 1) break;
				for (int k = 1; triangle[k] < input_num; k++) {
					if (isNum_3 == 1) break;
					if (triangle[i] + triangle[j] + triangle[k] == input_num) {
						isNum_3 = 1;
						cout << 1 << endl;
					}
				}
			}
		}
		if (isNum_3 == 0)
			cout << 0 << endl;
		caseNum--;
	}
	return 0;
}