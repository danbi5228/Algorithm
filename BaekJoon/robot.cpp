#include <iostream>
using namespace std;

int N = 0, M = 0;
int robot_x = 0, robot_y = 0;
int now_robot_dir = 0; // 0 : 북, 1 : 동, 2 : 남, 3 : 서
int cnt = 0;

int arr[50][50] = { 0, };

//int visit_arr[50][50] = { 0, };
//bool inRange(int a, int b) {
//	return (a >= 0 && a <= N && b >= 0 && b <= M);
//}
//bool isVisit(int a, int b) {
//	return visit_arr[a][b] != 1; // 안 했으면 0, 했으면 1
//}

int clean(int x, int y, int dir) {
	arr[x][y] = 7;
	cnt++;

	for (int i = 0; i < 4; i++) {
		
		// 전부 벽일 때
		if (arr[x][y - 1] == 1 && arr[x - 1][y] == 1 && arr[x][y + 1] == 1 && arr[x + 1][y] == 1) {
			switch (dir)
			{
			case 0:
				if (arr[x + 1][y] != 1) {
					cnt--;
					clean(x + 1, y, dir);
				}
				else return 0;
				break;
			case 1:
				if (arr[x][y - 1] != 1) {
					cnt--;
					clean(x, y - 1, dir);
				}
				else return 0;
				break;
			case 2:
				if (arr[x - 1][y] != 1) {
					cnt--;
					clean(x - 1, y, dir);
				}
				else return 0;
				break;
			case 3:
				if (arr[x][y + 1] != 1) {
					cnt--;
					clean(x, y + 1, dir);
				}
				else return 0;
				break;
			default:
				break;
			}
		}
		else {
			switch (dir)
			{
			case 0:
				if (arr[x][y - 1] == 0) {
					clean(x, y - 1, 3);
				}
				else {
					cnt--;
					clean(x, y, 3);
				}
				break;
			case 1:
				if (arr[x - 1][y] == 0) {
					clean(x - 1, y, 0);
				}
				else {
					cnt--;
					clean(x, y, 0);
				}
				break;
			case 2:
				if (arr[x][y + 1] == 0) {
					clean(x, y + 1, 1);
				}
				else {
					cnt--;
					clean(x, y, 1);
				}
				break;
			case 3:
				if (arr[x + 1][y] == 0) {
					clean(x + 1, y, 2);
				}
				else {
					cnt--;
					clean(x, y, 2);
				}
				break;
			default:
				break;
			}
		}
	}

}

int main() {
	cin >> N >> M;
	cin >> robot_x >> robot_y>>now_robot_dir;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	clean(robot_x, robot_y, now_robot_dir);

	//cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	cout << "cnt : " << cnt << endl;
	return 0;
}