#include <iostream>
using namespace std;

int main() {

	int N, M, L,num = 0; // num : 총 공 넘겨진 횟수.
	int table[1001] = { 0, }; // 각 자리에서 받은 공 횟수
	int ballnum = 1; // 이 포인터가 가리키는 배열 값이 M이 되면 stop 
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