#include<iostream>
using namespace std;

int main(void) {
	int arr[10][10] = { 0 };
	int caseNum, idx = 1, N;

	arr[0][0] = 1;
	for (int i = 1; i < 10; i++) {
		arr[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}

	cin >> caseNum;
	while (caseNum > 0) {
		cin >> N;
		cout << "#" << idx << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] == 0) break;
				else cout << arr[i][j] << " ";
			}
			cout << endl;
		}
		caseNum--;
		idx++;
	}
}