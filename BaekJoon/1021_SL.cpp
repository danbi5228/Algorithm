#include <iostream>
#include <deque> // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!덱 쓰는게 포인트!!!
using namespace std;

int N, M, cnt = 0;
int point = 1;
int sum = 0;
int arr[51] = { 0, };
deque <int> dq;

int ToLeftarr(int a) {
	if (a == 0) {
		dq.pop_front();
		return cnt;
	}

	cnt++;
	dq.push_back(dq.front());
	dq.pop_front();
	a--;
	return ToLeftarr(a);
}

int ToRightarr(int b) {
	if (b == N-1) {
		dq.pop_back();
		return cnt+1;
	}

	cnt++;
	dq.push_front(dq.back());
	dq.pop_back();
	b++;
	return ToRightarr(b);
}
int main() {

	cin >> N >> M;

	for (int i = 1; i <= N; ++i) {
		dq.push_back(i);
	}


	for (int i = 1; i <= M; i++) {
		cin >> arr[i];
	}

	while (M > 0) {
		for (int j = 0; j < N; j++) {
			if (dq[j] == arr[point]) {
				(j <= N / 2 ? sum += ToLeftarr(j) : sum += ToRightarr(j));
				break;
			}
		}
		point++;
		M--;
		N--;
		cnt = 0;
	}

	cout << sum;
	return 0;
}