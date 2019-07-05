#include <iostream>
using namespace std;

int M, N, K; // 5 7 3
int x_1, x_2, y_1, y_2;
int **grid;
int cnt;
int result[100000] = { 0, };
int result_cnt = 0;

void chk(int x1, int y1, int x2, int y2) { // 직사각형 색칠
	for (int i = x1; i < x2; i++) {
		for (int j = y1; j < y2; j++) {
			grid[i][j] = 1;
		}
	}
}

bool inRange(int x, int y) {
	return (x >= 0 && x < N && y >= 0 && y < M);
}

void bfs_blank(int x, int y) {
	cnt++;
	grid[x][y] = 1;
	if (inRange(x,y + 1) && grid[x][y + 1] == 0) { // 오른쪽
		bfs_blank(x, y + 1);
	}
	if (inRange(x + 1, y) && grid[x + 1][y] == 0) { // 아래
		bfs_blank(x + 1, y);
	}
	if (inRange(x , y - 1) && grid[x][y - 1] == 0) { // 왼쪽
		bfs_blank(x, y - 1);
	}
	if (inRange(x - 1, y) && grid[x - 1][y] == 0) { // 위
		bfs_blank(x - 1, y);
	}
}

void quickSort(int arr[], int left, int right) {
	int i = left, j = right;
	int pivot = arr[(left + right) / 2];
	int temp;
	do {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);

	if (left < j)
		quickSort(arr, left, j);

	if (i < right)
		quickSort(arr, i, right);
}

int main() {
	cin >> M >> N >> K;

	grid = new int*[N];
	for (int i = 0; i < N; i++) {
		grid[i] = new int [M];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			grid[i][j] = 0;
		}
	}

	for (int i = 0; i < K; i++) {
		cin >> x_1 >> y_1 >> x_2 >> y_2;
		chk(x_1, y_1, x_2, y_2);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (grid[i][j] == 0) {
				bfs_blank(i, j);
				result[result_cnt] = cnt;
				cnt = 0;
				result_cnt++;
			}
		}
	}

	quickSort(result, 0, result_cnt-1);

	cout << result_cnt << endl;
	for (int i = 0; i < result_cnt; i++) {
		cout << result[i] << " ";
	}

	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < M; j++) {
	//		cout << grid[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	return 0;
}