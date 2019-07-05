#include <iostream>
using namespace std;



int isNum(int x) {
	int a, b, c, d,isSame;
	a = x / 1000;
	b = x / 100;
	c = (x % 100) / 10;
	d = x % 10;

	int tmp1 = b - c;
	int tmp2 = c - d;
	if (a == 0) {
		(tmp1 == tmp2 ? isSame = 1 : isSame = 0);
		return isSame;
	}
	else
		return 0;
}

int main() {
	int N;
	int num = 99;
	cin >> N;

	if (N >= 100) {
		if (N < 111) {
			cout << num << endl;
			return 0;
		}

		for (int i = 111; i <= N; i++) {
			num = num + isNum(i);
		}
		cout << num << endl;
		return 0;
	}
	else cout << N << endl;

	return 0;
}


