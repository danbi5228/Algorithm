#include <iostream>
#include <vector>

using namespace std;

int sumNum(int sum_arr[10]) {
	return sum_arr[0] + sum_arr[1] + sum_arr[2] + sum_arr[3] + sum_arr[4] +
		sum_arr[5] + sum_arr[6] + sum_arr[7] + sum_arr[8] + sum_arr[9];
}

int main(void) {
	int testNum, idx = 0;
	cin >> testNum;

	while (testNum > 0) {
		testNum--;
		int caseNum, result = 0, tmp = 0, original, multiNum = 2;
		int arr[10] = { 0 };

		cin >> caseNum;
		original = caseNum;

		while (sumNum(arr) != 10) {
			while (1) {
				if (caseNum == 0) break;
				tmp = caseNum % 10;
				if (arr[tmp] == 0) arr[tmp] = 1;

				caseNum /= 10;
			}

			caseNum = original * multiNum;
			multiNum++;

		}

		idx++;
		cout << "#" << idx << " " << caseNum - original << endl;

	}
}