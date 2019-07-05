#include <iostream>
using namespace std;
//1의자리 수 부터 10으로 나누고 %10으로 하면서 3,6,9면 ㄱㄱ

int isClap(int x) {
	if (x == 3 || x == 6 || x == 9) return 1;
	else return 0;
}

void printNum(int Num, int x) {
	if (Num == 0) cout << x << " ";
	else {
		while (Num) {
			cout << "-";
			Num--;
		}
		cout << " ";
	}
}

int main(void) {
	int num;
	cin >> num;

		for (int i = 1; i <= num; i++) {
			int tmp = 0;
			if (i < 100) {
				int a, b;
				a = i / 10;
				b = i % 10;

				tmp = isClap(a) + isClap(b);
				printNum(tmp,i);
				continue;
			}
			else {
				int x, y, z;
				x = i / 100;
				y = (i%100) / 10;
				z = i % 10;

				tmp = isClap(x) + isClap(y) + isClap(z);
				printNum(tmp, i);
				continue;
			}
		}
}