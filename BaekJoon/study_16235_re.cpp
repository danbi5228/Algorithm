#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> tree[11][11]; // 살아있는 친구들
vector<int> die_tree[11][11]; // 죽은나무
int food[11][11]; // 기계가 추가할 양분
int map[11][11]; // 땅땅땅

int N = 0, M = 0, K = 0;
int tree_x = 0, tree_y = 0, tree_age = 0;

int alive_tree = 0;

bool isMap(int x, int y) {
	if (x<1 || x>N || y<1 || y>N) return false;
	else return true;
}
void new_tree(int a, int b) {
	if (isMap(a - 1, b - 1)) tree[a - 1][b - 1].push_back(1);
	if (isMap(a - 1, b)) tree[a - 1][b].push_back(1);
	if (isMap(a - 1, b + 1)) tree[a - 1][b + 1].push_back(1);
	if (isMap(a, b - 1)) tree[a][b - 1].push_back(1);
	if (isMap(a, b + 1)) tree[a][b + 1].push_back(1);
	if (isMap(a + 1, b - 1)) tree[a + 1][b - 1].push_back(1);
	if (isMap(a + 1, b)) tree[a + 1][b].push_back(1);
	if (isMap(a + 1, b + 1)) tree[a + 1][b + 1].push_back(1);
}

int main() {
	
	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> food[i][j];
			map[i][j] = 5;
		}
	}

	for (int z = 0; z < M; z++) {
		cin >> tree_x >> tree_y >> tree_age;
		tree[tree_x][tree_y].push_back(tree_age);
	}

	while (K--) { //!!!!!!!

		//spring
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				sort(tree[i][j].begin(), tree[i][j].end());
				for (int k = 0; k < tree[i][j].size(); k++) {
					if (map[i][j] >= tree[i][j][k]) {
						map[i][j] -= tree[i][j][k];
						tree[i][j][k]++;
					}
					else {
						die_tree[i][j].push_back(tree[i][j][k]);
						//tree[i][j][k] = 0;
					}
				}
			}
		}

		//summer
		int tmp_erase = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (int z = 0; z < die_tree[i][j].size(); z++) {
						map[i][j] += (die_tree[i][j][z] / 2);
				}
				tmp_erase = tree[i][j].size() - die_tree[i][j].size();
				while (tree[i][j].size() > tmp_erase) {
					tree[i][j].pop_back();
				}
				die_tree[i][j].clear();
			}
		}

		//fall
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (int k = 0; k < tree[i][j].size(); k++) {
					if (tree[i][j][k] % 5 == 0) new_tree(i, j);
				}
			}
		}

		//winter
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				map[i][j] += food[i][j];
			}
		}

	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < tree[i][j].size(); k++) {
				if (tree[i][j][k] != 0) alive_tree++;
			}
		}
	}

	cout << alive_tree << endl;

	
	return 0;
}