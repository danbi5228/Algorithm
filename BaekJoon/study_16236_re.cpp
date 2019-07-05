#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;

int map[21][21] = { 0, };
int cmp_map[21][21] = { 0, };
int bfs_cmp_map[21][21] = { 0, };

int N = 0;

int babyShark = 2; // 처음 아기상어 크기 2
int cnt_shark = 0; // 크기만큼 먹으면 상어 크기 1 증가 시킴

bool isFlag = 1;

int min_x = 30000, min_y = 30000;
int min_distance = 30000;
int tmp_min = 0;


int erase_food = 0; // 먹은 것 food_position에서 제거

int bfs_min = 10000;
int tmp_bfs_min = 0, b_x = 0, b_y = 0;
int final_result = 0;

pair<int, int> shark_p;
vector<pair<int, int>> food_position;
queue<pair<int, int>> Queue;

bool isMap(int x, int y) {
	if (x < 0 || x > N || y < 0 || y > N) return false;
	else return true;
}

void bfs_map() {
	while (Queue.size() > 0)
	{
		b_x = Queue.front().first;
		b_y = Queue.front().second;
		Queue.pop();

		if (cmp_map[b_x][b_y] != 0 && bfs_cmp_map !=0) continue;
		

		tmp_bfs_min = bfs_cmp_map[b_x][b_y];
		
		cmp_map[b_x][b_y] = 1;

		if (isMap(b_x-1, b_y) && cmp_map[b_x-1][b_y] == 0 && map[b_x-1][b_y] <= babyShark) {
			bfs_cmp_map[b_x - 1][b_y] = tmp_bfs_min + 1;
			Queue.push(make_pair(b_x-1, b_y));
			
		}
		if (isMap(b_x, b_y+1) && cmp_map[b_x][b_y + 1] == 0 && map[b_x ][b_y + 1] <= babyShark) {
			bfs_cmp_map[b_x][b_y + 1] = tmp_bfs_min + 1;
			Queue.push(make_pair(b_x, b_y + 1));
			
		}
		if (isMap(b_x + 1, b_y) && cmp_map[b_x + 1][b_y] == 0 && map[b_x + 1][b_y] <= babyShark) {
			bfs_cmp_map[b_x + 1][b_y] = tmp_bfs_min + 1;
			Queue.push(make_pair(b_x + 1, b_y));
			
		}
		if (isMap(b_x, b_y - 1) && cmp_map[b_x ][b_y - 1] == 0 && map[b_x][b_y - 1] <= babyShark) {
			bfs_cmp_map[b_x][b_y - 1] = tmp_bfs_min + 1;
			Queue.push(make_pair(b_x, b_y - 1));
			
		}


		//for (int i = 0; i < N; i++) {
		//	for (int j = 0; j < N; j++) {
		//		cout << bfs_cmp_map[i][j];
		//	}
		//	cout << endl;
		//}
		//cout << "----------------------------------------" << endl;

	}
}

void find_map() {
	for (int k = 0; k < N; k++) {
		for (int l = 0; l < N; l++) {
			if (map[k][l] < babyShark && map[k][l] > 0) {
				food_position.push_back(make_pair(k, l));
				isFlag = 1;
			}
		}
	}

	while (food_position.size() > 0)
	{
		for (int k = 0; k < food_position.size(); k++) {
			tmp_min = abs(food_position[k].first - shark_p.first) + abs(food_position[k].second - shark_p.second);
			if (min_distance == tmp_min) {
				if (min_x > food_position[k].first) {
					min_x = food_position[k].first;
					min_y = food_position[k].second;
					erase_food = k;
				}
				else if (min_x == food_position[k].first && min_y > food_position[k].second) {
					min_x = food_position[k].first;
					min_y = food_position[k].second;
					erase_food = k;
				}
			}
			else if (min_distance > tmp_min) {
				min_x = food_position[k].first;
				min_y = food_position[k].second;
				erase_food = k;
				min_distance = tmp_min;
			}
		}

		
		Queue.push(make_pair(shark_p.first, shark_p.second));
		bfs_map();
		bfs_min = bfs_cmp_map[min_x][min_y];
		final_result += bfs_min;

		map[shark_p.first][shark_p.second] = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cmp_map[i][j] = 0;
				bfs_cmp_map[i][j] = 0;
			}
		}
		
		

		cout << "----------------------" << endl;
		

		cout << bfs_min << "***" << endl;
		shark_p.first = min_x;
		shark_p.second = min_y;
		food_position.erase(food_position.begin() + erase_food);
		map[shark_p.first][shark_p.second] = 0;
		min_distance = 30000;

		cout << shark_p.first << " " << shark_p.second << " ------" << endl;

		cnt_shark++;
		if (cnt_shark == babyShark) {
			babyShark++;
			cnt_shark = 0;
			food_position.clear();
		}

		bfs_min = 0;


		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << map[i][j];
			}
			cout << endl;
		}
		cout << "----------------------------------------" << endl;

		//if (babyShark_position.first == d_x && babyShark_position.second == d_y) {
		//	map[d_x][d_y] = 0;
		//	cnt_shark++;

	}
}
int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				make_pair(shark_p.first, shark_p.second);
				shark_p.first = i;
				shark_p.second = j;

			}
		}
	}

	while (isFlag == 1) {
		isFlag = 0;
		find_map();
	}

	cout << final_result << endl;

}
