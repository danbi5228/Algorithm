#include <iostream>
using namespace std;

bool hanNum(int x);

int main() {
	int N;
	int num = 99;
	bool isHan;

	cin >> N;

	if (N >= 100) {
		if (N < 111) {
			cout << num << endl;
			return 0;
		}

		for (int i = 111; i <= N; i++) {
			isHan = hanNum(i);
			if (isHan) num++;
		}
		cout << num << endl;
		return 0;
	}
	else cout << N << endl;

	return 0;
}


bool hanNum(int x) {
	int a, b, c, d;
	a = x / 1000;
	b = x / 100;
	c = x / 10;
	d = x % 10;

	if (a == 0) {
		(b - c == c - d ? a = 1 : a = 0);
		if (a == 1) return true;
	}
	else
		return false;
}