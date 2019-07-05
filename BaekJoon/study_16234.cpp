//dfs 버전
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

//vector<int> map[100][100];
//vector<pair<int,int>> position; //first,second

int map[100][100] = { 0, };
int visit[100][100] = { 0, };
int N = 0, L = 0, R = 0;
int move_count = 0; // 전체 이동 카운트
int move_sum = 0;
int move_sum_count = 0;

int if_flag = 1;

bool isMap(int map_x, int map_y) {
	if (map_x < 0 || map_x >= N || map_y < 0 || map_y >= N) return false;
	else return true;
}

//void map_change(int x, int y) {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			if (visit[i][j] == 1) {
//				if (map[i][j] != move_sum) {
//					map[i][j] = move_sum;
//					if_flag = 1;
//				}
//				visit[i][j] = 2;
//			}
//		}
//	}
//}

void dfs_move(int x, int y) {
	
	visit[x][y] = 1;
	move_sum_count++;
	move_sum += map[x][y];

	if (isMap(x, y + 1) && (R >= (abs(map[x][y] - map[x][y + 1]))) && (L <= abs(map[x][y] - map[x][y + 1])) && visit[x][y+1] == 0) {
		dfs_move(x, y + 1);
	}
	if (isMap(x+1, y) && (R >= (abs(map[x+1][y] - map[x][y]))) && (L <= abs(map[x][y] - map[x+1][y])) && visit[x+1][y] == 0) {
		dfs_move(x+1, y);
	}
	if (isMap(x, y - 1) && (R >= (abs(map[x][y] - map[x][y - 1]))) && (L <= abs(map[x][y] - map[x][y - 1])) && visit[x][y - 1] == 0) {
		dfs_move(x, y - 1);
	}
	if (isMap(x-1, y) && (R >= (abs(map[x][y] - map[x-1][y]))) && (L <= abs(map[x][y] - map[x-1][y])) && visit[x-1][y] == 0) {
		dfs_move(x-1, y);
	}

}

int main() {
	cin >> N >> L >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	
	while (if_flag == 1) {

		if_flag = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visit[i][j] == 0) {
					dfs_move(i, j);

					move_sum /= move_sum_count;
					
						for (int s = 0; s < N; s++) {
							for (int v = 0; v < N; v++) {
								if (visit[s][v] == 1) {
									if (map[s][v] != move_sum) {
										map[s][v] = move_sum;
										if_flag = 1;
									}
									visit[s][v] = 2;
								}
							}
						}


					move_sum = 0;
					move_sum_count = 0;

				}
			}
		}

		for (int k = 0; k < N; k++) {
			for (int z = 0; z < N; z++) {
				if (visit[k][z] != 0) {
					visit[k][z] = 0;
				}
			}
		}

		if (if_flag == 1) {
			move_count++;
		}
	}

	cout << move_count;

	return 0;
}