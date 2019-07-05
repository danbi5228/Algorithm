#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

//vector<vector<int>> A_block; // 양분 값 입력받은거 저장. 기계가 넣을 양분
//vector<vector<int>> for_K_block; //초기 양분 상황 저장 후~'

//vector<vector<vector<int>>> K_block; // 이거 말고 
vector<int> K_block[12][12];
/*
int food[11][11];
int cur_food[11][11];
vector<int> live[12][12];
live[i][j][k];
*/ // 이 방법으로 다시


bool isBlock(int a, int b, int block_size) {
	if (a < 1 || a >= block_size || b < 1 || b >= block_size) return 0;
	else return 1;
}

void new_tree(int i, int j,int N) {
	if(isBlock(i-1,j-1,N)) K_block[i-1][j-1].push_back(1);
	if (isBlock(i-1, j,N)) K_block[i - 1][j].push_back(1);
	if (isBlock(i-1, j+1,N)) K_block[i - 1][j + 1].push_back(1);
	if (isBlock(i, j-1,N)) K_block[i][j - 1].push_back(1);
	if (isBlock(i, j+1, N)) K_block[i][j + 1].push_back(1);
	if (isBlock(i+1, j-1, N)) K_block[i + 1][j - 1].push_back(1);
	if (isBlock(i+1, j, N)) K_block[i + 1][j].push_back(1);
	if (isBlock(i+1, j+1, N)) K_block[i + 1][j + 1].push_back(1);
}


int main() {
	int N = 0, M = 0, K = 0;
	cin >> N >> M >> K; // 땅 크기, 나무 수, 년도
	N++;

	//K_block = vector<vector<vector<int>>>(N, vector<vector<int>>(N, vector<int>()));
	
	int tree_x = 0,tree_y = 0, tree_age = 0;
	int num_tree = 0;
	
	int A_block[11][11]; // 기계 양분
	int for_K_block[11][11]; // 땅

	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			cin >> A_block[i][j];
			for_K_block[i][j] = 5;
		}
	}

	for (int i = 0; i < M; i++) {
		cin >> tree_x >> tree_y >> tree_age;
		K_block[tree_x][tree_y].push_back( tree_age );
	}

	while (K > 0) {

		//spring
		for (int i = 1; i < N; i++) {
			for (int j = 1; j < N; j++) {
				if (K_block[i][j].size() > 0) {
					sort(K_block[i][j].begin(), K_block[i][j].end());
					for (int z = 0; z < K_block[i][j].size(); z++) {
						if (for_K_block[i][j] >= K_block[i][j][z]) {
							for_K_block[i][j] -= K_block[i][j][z]; // 나이만큼 양분 먹기
							K_block[i][j][z]++; // 나이+1 먹음
						}
						else K_block[i][j][z] = (-1*(K_block[i][j][z] / 2)); // -(반으로 나눈 값)이 저장되게 함
					}
				}
			}
		}

		//summer
		for (int i = 1; i < N; i++) {
			for (int j = 1; j < N; j++) {
					for (int x = K_block[i][j].size()-1; x > 0; x--) {
						if (K_block[i][j][x] > 0) break;
						else {
							for_K_block[i][j] += fabs(K_block[i][j][x]);
							K_block[i][j].pop_back();
						}
					}

					//for (int z = 0; z < K_block[i][j].size(); z++) {
					//	if (K_block[i][j][z] < 0) {
					//		for_K_block[i][j] += fabs(K_block[i][j][z]);
					//		//K_block[i][j].erase(K_block[i][j].begin() + z) ;
					//	}
					//}

					//K_block[i][j].clear();
					//for (int x = 0; x < tmp.size(); x++) {
					//	K_block[i][j].push_back(tmp[x]);
					//}

					//sort(K_block[i][j].begin(), K_block[i][j].end());
					//for (int z = 0; z < K_block[i][j].size; z++) {
					//	if(K_block[i][j][])
					//}

					//for (int z = K_block[i][j].size()-1; z > 0; z--) {
					//	if (K_block[i][j][z] > 0) break;
					//	else {
					//		for_K_block[i][j] += fabs(K_block[i][j][z]);
					//		K_block[i][j].pop_back();
					//	}
					//}

					//int idx = K_block.size() - 1;
				

			}
		}

		//fall
		for (int i = 1; i < N; i++) {
			for (int j = 1; j < N; j++) {
				for (int z = 0; z < K_block[i][j].size(); z++) {
					if (K_block[i][j][z] % 5 == 0) {
						new_tree(i, j, N);
					}
				}
			}
		}

		//winter
		for (int i = 1; i < N; i++) {
			for (int j = 1; j < N; j++) {
				for_K_block[i][j] += A_block[i][j];
			}
		}

		K--;
	}
	//------------------------------------------

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int z = 0; z < K_block[i][j].size(); z++) {
				if (K_block[i][j][z] > 0) {
					num_tree++;
				}
			}
		}
	}

	cout << num_tree << endl;

	return 0;
}



//vector<vector<int>> K_tmp_block;
//vector<vector<vector<int>>> K_block(3, K_tmp_block); // 나무 나이 저장



//class Tree {
//public:
//	int x;
//	int y;
//	int age;
//	Tree* next_child;
//
//	Tree(int t_x, int t_y, int t_age) {
//		x = t_x;
//		y = t_y;
//		age = t_age;
//		next_child = NULL;
//	}
//};

//void spring_feed(int i, int j, int food) {
//	sort(K_block[i][j].begin(), K_block[i][j].end());
//	for (int z = 0; z < K_block[i][j].size(); z++) {
//		if(food>=K_block[i][j][z])
//	}
//}
