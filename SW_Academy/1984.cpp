#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
	int caseN, idx = 0;
	cin >> caseN;

	while (caseN > 0) {
		int arr[10] = { 0 };
		double result = 0;
		int maxNum=0, minNum=10001;
		for (int i = 0; i < 10; i++) {
			cin >> arr[i];
			result += arr[i];
			if (arr[i] > maxNum) maxNum = arr[i];
			if (arr[i] < minNum) minNum = arr[i];
		}

		result = (result - maxNum - minNum)/8;

		idx++;
		cout << "#" << idx << " " << (int)round(result) << endl;
		
		caseN--;
	}
}