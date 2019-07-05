#include <iostream>
using namespace std;

int N = 0, M = 0; // 세로 , 가로
int arr[1000][1000] = { 0, };
int now_robot_x = 0, now_robot_y = 0, now_robot_dir = 0;
int next_robot_x = 0, next_robot_y = 0;

int round_val[4][2] = { { -1, 0 },{ 0, 1 },{ 1, 0 },{ 0, -1 } };
int cnt = 0; // 청소한 칸 개수


int isBackPossible() {
	//뒤쪽 값
	next_robot_x = now_robot_x + round_val[(now_robot_dir + 2) % 4][0];
	next_robot_y = now_robot_y + round_val[(now_robot_dir + 2) % 4][1];

	//뒤쪽이 없다
	if (next_robot_x < 0 || next_robot_x >= N || next_robot_y < 0 || next_robot_y >= M) return 0;
	//뒤쪽이 벽이다
	else if (arr[next_robot_x][next_robot_y] == 1) return 0;
	//뒤쪽으로 갈 수 있다
	else return 1;
}
int isRoundEmpty() {
	int roundFull = 0;
	for (int i = 0; i < 4; i++) {
		//왼쪽 값
		next_robot_x = now_robot_x + round_val[(now_robot_dir + i + 3) % 4][0];
		next_robot_y = now_robot_y + round_val[(now_robot_dir + i + 3) % 4][1];

		//왼쪽이 없다
		if (next_robot_x < 0 || next_robot_x >= N || next_robot_y < 0 || next_robot_y >= M) roundFull++;

		//왼쪽이 이미 청소되어있다
		else if (arr[next_robot_x][next_robot_y] == 7) roundFull++;
		
		//왼쪽이 벽이다
		else if (arr[next_robot_x][next_robot_y] == 1) roundFull++;
		
		//왼쪽이 청소되어있지 않다
		else if (arr[next_robot_x][next_robot_y] == 0) return i;
	}

	if (roundFull == 4) return 0;
}

int howStatusLeft() {
	//왼쪽 값
	next_robot_x = now_robot_x + round_val[(now_robot_dir + 3) % 4][0];
	next_robot_y = now_robot_y + round_val[(now_robot_dir + 3) % 4][1];

	//왼쪽이 없다
	if (next_robot_x < 0 || next_robot_x >= N || next_robot_y < 0 || next_robot_y >= M) return 2;
	
	//왼쪽이 이미 청소되어있다
	else if (arr[next_robot_x][next_robot_y] == 7) return -1;
	
	//왼쪽이 벽이다
	else if (arr[next_robot_x][next_robot_y] == 1) return 1;
	
	//왼쪽이 청소되어있지 않다
	else if (arr[next_robot_x][next_robot_y] == 0) return 0;
}
int clean() {
	if (arr[now_robot_x][now_robot_y] == 0) {
		arr[now_robot_x][now_robot_y] = 7; // 청소하면 7
		cnt++;
	}

	int left_status = howStatusLeft();
	int is_round_empty = isRoundEmpty();

	if (left_status == 0) {
		//왼쪽으로 회전
		now_robot_dir = (now_robot_dir + 3) % 4;
		now_robot_x = next_robot_x;
		now_robot_y = next_robot_y;
	}
	//네 방향 모두가 청소되어 있거나 벽인 경우
	else if (!is_round_empty) {
		//바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
		if (isBackPossible()) {
			now_robot_x = now_robot_x + round_val[(now_robot_dir + 2) % 4][0];
			now_robot_y = now_robot_y + round_val[(now_robot_dir + 2) % 4][1];
		}
		// 뒤쪽이 벽이라 후진할 수 없음 (==possible 결과가 0인 경우) -> 작동을 멈춘다.
		else return 0;
	}
	//왼쪽 방향에 청소할 공간이 없는 경우 그 방향으로 회전하고 2번으로 돌아간다.
	else if (left_status == 1 || left_status == -1) {
		//왼쪽으로 회전
		now_robot_dir = (now_robot_dir + 3) % 4;
	}
	return 1;
}
int main() {
	cin >> N >> M;
	cin >> now_robot_x >> now_robot_y>>now_robot_dir;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	while (clean()) {
	}

	cout << cnt;


	////---------------------------------
	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < M; j++) {
	//		cout << arr[i][j];
	//	}
	//	cout << endl;
	//}
	////---------------------------------
	return 0;
}