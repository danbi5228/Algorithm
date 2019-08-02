#include "pch.h"
#include <iostream>
using namespace std;

int main(void) {
	int testNum, idx=0;
	cin >> testNum;

	while (testNum > 0) {
		int caseNum, result = 0;
		cin >> caseNum;

		for (int i = 0; i <= caseNum; i++) {
			if (i % 2 == 0) {
				result -= i;
			}
			else result += i;
		}

		idx++;
		cout << "#" << idx << " " << result << endl;
		testNum--;
	}
}