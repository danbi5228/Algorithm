#include <iostream>
using namespace std;

long long arr[102][11] = { 0, };
int main() {

	int digit = 0;
	long long sum = 0;
	cin >> digit;

	arr[1][0] = 0;
	for (int i = 1; i < 10; i++) {
		arr[1][i] = 1;
	}


	for (int i = 2; i <= digit; i++) {
		arr[i][0] = arr[i - 1][1]%1000000000;
		for (int j = 1; j <= 8; j++) {
			arr[i][j] = (arr[i - 1][j - 1]%1000000000) + (arr[i - 1][j + 1]% 1000000000);
		}
		arr[i][9] = arr[i - 1][8]%1000000000; 
		// long long 이 충분히 길지만 결국 중간에 더하면 그 값을 또 넘을 수 있기 때문에 중간에 계속 자료형을 뛰어넘는게 있을 수 있음
	}

	//arr[digit][0] = arr[digit - 1][1];
	//for (int j = 1; j <= 8; j++) {
	//	arr[digit][j] = arr[digit - 1][j - 1] + arr[digit - 1][j + 1];
	//}
	//arr[digit][9] = arr[digit - 1][8];


	//for (int i = 1; i <= 3; i++) {
	//	for (int j = 0; j <= 9; j++) {
	//		cout << arr[i][j] << " ";
	//	}
	//	cout << endl;
	//}


	for (int i = 0; i < 10; i++) {
		sum += arr[digit][i];
		sum %= 1000000000;
	}

	cout << sum << endl;

	return 0;
}