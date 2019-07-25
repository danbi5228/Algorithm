#include "pch.h"
#include <iostream>
using namespace std;

int main(void) {
	int testNum, idx = 0;
	cin >> testNum;

	while (testNum > 0) {
		
		int caseNum, result_num = 1000000, result_p = 1; // case 수, 점수, 사람
		cin >> caseNum;

		int tmp = 1000000;
		for (int i = 0; i < caseNum; i++) {
			cin >> tmp;
			if (result_num > abs(tmp)) {
				result_num = abs(tmp);
				result_p = 1;
			}
			else if (result_num == abs(tmp)) result_p++;
		}

		idx++;
		cout << "#" << idx << " " << result_num <<" "<< result_p<<endl;
		
		testNum--;

	}
}