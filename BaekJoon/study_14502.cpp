#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

int map[9][9] = { 0, };
vector<pair<int, int>> virus_position; //<first,second>
int max_map_size = 0; // 비교하면서 max값 저장
int wall_counter = 0;
int N = 0, M = 0;

bool isMap(int map_x, int map_y) {
	if (map_x < 1 || map_x > N || map_y < 1 || map_y > M) return false;
	else return true;
}
void dfs_virus(int vir_x, int vir_y) {
	if (isMap(vir_x, vir_y + 1) && map[vir_x][vir_y + 1] == 0) {
		map[vir_x][vir_y + 1] = 2;
		dfs_virus(vir_x, vir_y + 1);
	}
	if (isMap(vir_x + 1, vir_y) && map[vir_x + 1][vir_y] == 0) {
		map[vir_x + 1][vir_y] = 2;
		dfs_virus(vir_x + 1, vir_y);
	}
	if (isMap(vir_x, vir_y - 1) && map[vir_x][vir_y - 1] == 0) {
		map[vir_x][vir_y - 1] = 2;
		dfs_virus(vir_x, vir_y - 1);
	}
	if (isMap(vir_x - 1, vir_y) && map[vir_x - 1][vir_y] == 0) {
		map[vir_x - 1][vir_y] = 2;
		dfs_virus(vir_x - 1, vir_y);
	}

}

void addWall(int x, int y) {
	if (map[x][y] != 0) {
		return;
	}
	
	//벽 일때만 수행
	wall_counter++;
	map[x][y] = 1;

	if (wall_counter == 3) {
		for (int i = 0; i < virus_position.size(); i++) {
			dfs_virus(virus_position[i].first , virus_position[i].second);
		}

		int tmp_map_count = 0;

		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				if (map[j][k] == 0) tmp_map_count++;
				else if (map[j][k] == 2) map[j][k] = 0;
			}
		}

		if (max_map_size < tmp_map_count) max_map_size = tmp_map_count;

		//cout << "-------------------------" << endl;
		//for (int i = 1; i <= N; i++) {
		//	for (int j = 1; j <= M; j++) {
		//		cout << map[i][j];
		//	}
		//	cout << endl;
		//}
		
		for (int i = 0; i < virus_position.size(); i++) {
			map[virus_position[i].first][virus_position[i].second] = 2;
		}

		map[x][y] = 0;
		wall_counter--;
		return;
	}

	for (int i = x; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (i == x && j == y) continue;
			addWall(i, j);
		}
	}

	map[x][y] = 0;
	wall_counter--;
	return;
}


int main() {

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				virus_position.push_back(make_pair(i,j)); // !!!!!!!!!!!!!!!!!!!!!!!!1
			}
		}
	}

	//-----------------------------------------

	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++) {
			addWall(i, j);
		}
	}
	cout << max_map_size << endl;

	return 0;
}