#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;

int map[100][100] = { 0, };
bool visit[100][100] = { 0, };
bool isflag = 1;
int N=0, L=0, R = 0;
queue <pair<int, int>> Queue;
vector<pair<int, int>> Save;

int move_sum = 0, move_sum_count = 0, move_count = 0;
int x = 0, y = 0;

bool isMap(int map_x, int map_y) {
	if (map_x < 0 || map_x >= N || map_y < 0 || map_y >= N) return false;
	else return true;
}

void bfs_map() {


	while (Queue.size() > 0) {

		x = Queue.front().first;
		y = Queue.front().second;
		Queue.pop();

		if (visit[x][y] != 0) continue;

		move_sum_count++;
		move_sum += map[x][y];
		Save.push_back(make_pair(x, y));
		visit[x][y] = 1;

		if (isMap(x, y + 1) && (R >= (abs(map[x][y] - map[x][y + 1]))) && (L <= (abs(map[x][y] - map[x][y + 1]))) && visit[x][y + 1] == 0) {
			Queue.push(make_pair(x, y + 1));
		}
		if (isMap(x + 1, y) && (R >= (abs(map[x + 1][y] - map[x][y]))) && (L <= (abs(map[x][y] - map[x + 1][y]))) && visit[x + 1][y] == 0) {
			Queue.push(make_pair(x + 1, y));
		}
		if (isMap(x, y - 1) && (R >= (abs(map[x][y] - map[x][y - 1]))) && (L <= (abs(map[x][y] - map[x][y - 1]))) && visit[x][y - 1] == 0) {
			Queue.push(make_pair(x, y - 1));
		}
		if (isMap(x - 1, y) && (R >= (abs(map[x][y] - map[x - 1][y]))) && (L <= (abs(map[x][y] - map[x - 1][y]))) && visit[x - 1][y] == 0) {
			Queue.push(make_pair(x - 1, y));
		}
	}
}
int main() {
	cin >> N >> L >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	while (isflag == 1) {
		isflag = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visit[i][j] == 0) {
					Queue.push(make_pair(i,j));
					bfs_map();

					move_sum /= move_sum_count;
					for(int k = 0; k < Save.size(); k++) {
						if (map[Save[k].first][Save[k].second] != move_sum) isflag = 1;
						map[Save[k].first][Save[k].second] = move_sum;
					}

					//cout << "move_sum_count :"<<move_sum_count << endl;

					Save.clear();
					move_sum = 0;
					move_sum_count = 0;
				}
			}
		}


		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << map[i][j] <<" ";
			}
			cout << endl;
		}
	
		cout << "---------------------------------" << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visit[i][j] = 0;
			}
		}
		
		if (isflag == 1) move_count++;
	}


	cout << move_count;
	return 0;
}