#include <iostream>
using namespace std;

int main() {
	int inputN[10001] = { 0, };
	int DParray[10001] = { 0, };
	int max = 0; // 자기보다 작고, DP 값이 제일 큰 것.
	int result_max = 0;

		int caseN = 0;
		cin >> caseN;
		for (int i = 0; i < caseN; i++) {
			cin >> inputN[i];
		}

		DParray[0] = 1;
		for (int j = 1; j < caseN; j++) {
			max = 0;
			if (inputN[j - 1] < inputN[j]) {
				for (int k = j - 1; k >= 0; k--) {
					if (inputN[j] > inputN[k] && max < DParray[k]) { // 입력된 값이 자기보다 작은 것 중에서 
						max = DParray[k];
					}
				}
				DParray[j] = max + 1;
			}
			else {
				for (int k = j - 1; k >= 0; k--) {
					if (inputN[j] > inputN[k] && max < DParray[k]) { // 입력된 값이 자기보다 작은 것 중에서 
						max = DParray[k];
					}
				}
				DParray[j] = max + 1;
			}

			if (DParray[j] >= result_max) {
				result_max = DParray[j];
			}
		}

		//for (int j = 0; j < caseN; j++) {
		//	cout << DParray[j] << endl;
		//}
		//
		//cout << "----------" << endl;


		if (caseN == 1) result_max = 1;
		cout << result_max << endl;
	
	return 0;
}