//4
//4 3 2 1
//0 0 0 0
//0 0 9 0
//1 2 3 4

//위의 예제만 가능. 같은 크기라면 지나갈 수만 있다거나 하는 경우가 제외됨...ㅎㅎㅎ

#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;

int map[21][21] = { 0, };
int N = 0;

int babyShark = 2; // 처음 아기상어 크기 2
pair<int, int> shark_p;
vector<pair<int, int>> food_position;
bool isFlag = 1;
int time_counter = 0;

int shark_counter = 0;

int min_x = 30000, min_y = 30000;
int min_distance = 30000;
int tmp_min = 0;
int erase_food = 0; // 먹은 것 food_position에서 제거


void find_map(int p_x, int p_y) {
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


		time_counter += tmp_min;
		shark_p.first = min_x;
		shark_p.second = min_y;
		food_position.erase(food_position.begin() + erase_food);
		map[shark_p.first][shark_p.second] = 0;
		min_distance = 30000;

		cout << shark_p.first << " " << shark_p.second << " ------" << endl;
		
		shark_counter++;
		if (shark_counter == babyShark) {
			babyShark++;
			shark_counter = 0;
		}

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
		find_map(0, 0);
	}

	cout << time_counter << endl;



	return 0;

}