#include <iostream>
using namespace std;

int main() {

	int N, M, L,num = 0; // num : �� �� �Ѱ��� Ƚ��.
	int table[1001] = { 0, }; // �� �ڸ����� ���� �� Ƚ��
	int ballnum = 1; // �� �����Ͱ� ����Ű�� �迭 ���� M�� �Ǹ� stop 
	cin >> N >> M >> L;

	table[ballnum]++;
	num++;

	while (table[ballnum] < M) {

		if (table[ballnum] % 2 == 0) {
			(ballnum % N - L > 0) ? (ballnum = ballnum % N - L) : (ballnum = (ballnum % N) - L + N);
		}
		else {
			(ballnum % N + L <= N) ? (ballnum = ballnum % N + L) : (ballnum = (ballnum + L) % N);
		}

		table[ballnum]++;
		num++;

	}
	cout << num - 1;
	return 0;
}