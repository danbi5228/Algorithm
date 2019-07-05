#include <iostream>
using namespace std;

int N = 0, M = 0; // ���� , ����
int arr[1000][1000] = { 0, };
int now_robot_x = 0, now_robot_y = 0, now_robot_dir = 0;
int next_robot_x = 0, next_robot_y = 0;

int round_val[4][2] = { { -1, 0 },{ 0, 1 },{ 1, 0 },{ 0, -1 } };
int cnt = 0; // û���� ĭ ����


int isBackPossible() {
	//���� ��
	next_robot_x = now_robot_x + round_val[(now_robot_dir + 2) % 4][0];
	next_robot_y = now_robot_y + round_val[(now_robot_dir + 2) % 4][1];

	//������ ����
	if (next_robot_x < 0 || next_robot_x >= N || next_robot_y < 0 || next_robot_y >= M) return 0;
	//������ ���̴�
	else if (arr[next_robot_x][next_robot_y] == 1) return 0;
	//�������� �� �� �ִ�
	else return 1;
}
int isRoundEmpty() {
	int roundFull = 0;
	for (int i = 0; i < 4; i++) {
		//���� ��
		next_robot_x = now_robot_x + round_val[(now_robot_dir + i + 3) % 4][0];
		next_robot_y = now_robot_y + round_val[(now_robot_dir + i + 3) % 4][1];

		//������ ����
		if (next_robot_x < 0 || next_robot_x >= N || next_robot_y < 0 || next_robot_y >= M) roundFull++;

		//������ �̹� û�ҵǾ��ִ�
		else if (arr[next_robot_x][next_robot_y] == 7) roundFull++;
		
		//������ ���̴�
		else if (arr[next_robot_x][next_robot_y] == 1) roundFull++;
		
		//������ û�ҵǾ����� �ʴ�
		else if (arr[next_robot_x][next_robot_y] == 0) return i;
	}

	if (roundFull == 4) return 0;
}

int howStatusLeft() {
	//���� ��
	next_robot_x = now_robot_x + round_val[(now_robot_dir + 3) % 4][0];
	next_robot_y = now_robot_y + round_val[(now_robot_dir + 3) % 4][1];

	//������ ����
	if (next_robot_x < 0 || next_robot_x >= N || next_robot_y < 0 || next_robot_y >= M) return 2;
	
	//������ �̹� û�ҵǾ��ִ�
	else if (arr[next_robot_x][next_robot_y] == 7) return -1;
	
	//������ ���̴�
	else if (arr[next_robot_x][next_robot_y] == 1) return 1;
	
	//������ û�ҵǾ����� �ʴ�
	else if (arr[next_robot_x][next_robot_y] == 0) return 0;
}
int clean() {
	if (arr[now_robot_x][now_robot_y] == 0) {
		arr[now_robot_x][now_robot_y] = 7; // û���ϸ� 7
		cnt++;
	}

	int left_status = howStatusLeft();
	int is_round_empty = isRoundEmpty();

	if (left_status == 0) {
		//�������� ȸ��
		now_robot_dir = (now_robot_dir + 3) % 4;
		now_robot_x = next_robot_x;
		now_robot_y = next_robot_y;
	}
	//�� ���� ��ΰ� û�ҵǾ� �ְų� ���� ���
	else if (!is_round_empty) {
		//�ٶ󺸴� ������ ������ ä�� �� ĭ ������ �ϰ� 2������ ���ư���.
		if (isBackPossible()) {
			now_robot_x = now_robot_x + round_val[(now_robot_dir + 2) % 4][0];
			now_robot_y = now_robot_y + round_val[(now_robot_dir + 2) % 4][1];
		}
		// ������ ���̶� ������ �� ���� (==possible ����� 0�� ���) -> �۵��� �����.
		else return 0;
	}
	//���� ���⿡ û���� ������ ���� ��� �� �������� ȸ���ϰ� 2������ ���ư���.
	else if (left_status == 1 || left_status == -1) {
		//�������� ȸ��
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