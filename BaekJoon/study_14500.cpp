#include<iostream>
using namespace std;

int max_num = 0;
int arr[500][500];
int N = 0, M = 0;

bool isBlock(int a, int b) {
	if (a < 0 || a >= N || b < 0 || b >= M) return 0;
	else return 1;
}

int main() {

	int tmp = 0;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			
			//case1
			if (isBlock(i, j + 1) && isBlock(i, j + 2) && isBlock(i, j + 3)) {
				tmp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i][j + 3];
				if (tmp > max_num) max_num = tmp;
			}

			if (isBlock(i + 1, j) && isBlock(i + 2, j) && isBlock(i + 3, j)) {
				tmp = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 3][j];
				if (tmp > max_num) max_num = tmp;
			}

			//case_2
			if (isBlock(i, j + 1) && isBlock(i + 1, j) && isBlock(i + 1, j + 1)) {
				tmp = arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1];
				if (tmp > max_num) max_num = tmp;
			}
			
			//case_3
			if (isBlock(i + 1, j) && isBlock(i + 2, j) && isBlock(i + 2, j + 1)) {
				tmp = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 2][j + 1];
				if (tmp > max_num) max_num = tmp;
			}
			if (isBlock(i - 1, j) && isBlock(i - 1, j + 1) && isBlock(i - 1, j + 2)) {
				tmp = arr[i][j] + arr[i - 1][j] + arr[i - 1][j + 1] + arr[i - 1][j + 2];
				if (tmp > max_num) max_num = tmp;
			}
			if (isBlock(i, j + 1) && isBlock(i + 1, j + 1) && isBlock(i + 2, j + 1)) {
				tmp = arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 2][j + 1];
				if (tmp > max_num) max_num = tmp;
			}
			if (isBlock(i + 1, j) && isBlock(i + 1, j - 1) && isBlock(i + 1, j - 2)) {
				tmp = arr[i][j] + arr[i + 1][j] + arr[i + 1][j - 1] + arr[i + 1][j - 2];
				if (tmp > max_num) max_num = tmp;
			}
			if (isBlock(i + 1, j) && isBlock(i + 2, j) && isBlock(i + 2, j - 1)) {
				tmp = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 2][j - 1];
				if (tmp > max_num) max_num = tmp;
			}
			if (isBlock(i, j + 1) && isBlock(i, j + 2) && isBlock(i + 1, j + 2)) {
				tmp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 2];
				if (tmp > max_num) max_num = tmp;
			}
			if (isBlock(i, j - 1) && isBlock(i + 1, j - 1) && isBlock(i + 2, j - 1)) {
				tmp = arr[i][j] + arr[i][j - 1] + arr[i + 1][j - 1] + arr[i + 2][j - 1];
				if (tmp > max_num) max_num = tmp;
			}
			if (isBlock(i + 1, j) && isBlock(i + 1, j + 1) && isBlock(i + 1, j + 2)) {
				tmp = arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 1][j + 2];
				if (tmp > max_num) max_num = tmp;
			}

			//case_4
			if (isBlock(i + 1, j) && isBlock(i + 1, j + 1) && isBlock(i + 2, j + 1)) {
				tmp = arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 2][j + 1];
				if (tmp > max_num) max_num = tmp;
			}
			if (isBlock(i, j + 1) && isBlock(i - 1, j + 1) && isBlock(i - 1, j + 2)) {
				tmp = arr[i][j] + arr[i][j + 1] + arr[i - 1][j + 1] + arr[i - 1][j + 2];
				if (tmp > max_num) max_num = tmp;
			}
			if (isBlock(i + 1, j) && isBlock(i + 1, j - 1) && isBlock(i + 2, j - 1)) {
				tmp = arr[i][j] + arr[i + 1][j] + arr[i + 1][j - 1] + arr[i + 2][j - 1];
				if (tmp > max_num) max_num = tmp;
			}
			if (isBlock(i, j + 1) && isBlock(i + 1, j + 1) && isBlock(i + 1, j + 2)) {
				tmp = arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 1][j + 2];
				if (tmp > max_num) max_num = tmp;
			}

			//case_5
			if (isBlock(i, j + 1) && isBlock(i, j + 2) && isBlock(i + 1, j + 1)) {
				tmp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1];
				if (tmp > max_num) max_num = tmp;
			}
			if (isBlock(i + 1, j) && isBlock(i + 2, j) && isBlock(i + 1, j + 1)) {
				tmp = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 1][j + 1];
				if (tmp > max_num) max_num = tmp;
			}
			if (isBlock(i + 1, j) && isBlock(i + 2, j) && isBlock(i + 1, j - 1)) {
				tmp = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 1][j - 1];
				if (tmp > max_num) max_num = tmp;
			}
			if (isBlock(i, j+1) && isBlock(i, j+2) && isBlock(i-1, j + 1)) {
				tmp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i - 1][j + 1];
				if (tmp > max_num) max_num = tmp;
			}
		}
	}

	cout << max_num;

	return 0;
}