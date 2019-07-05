#include <iostream>
using namespace std;

int main() {
	
	int arrT[101] = { 0, };
	int A, B, C;
	int x, y;
	int result = 0;

	cin >> A >> B >> C;

	for (int i = 0; i < 3; i++) {
		cin >> x >> y;

		for (int j = x + 1; j <= y; j++) {
			arrT[j] += 1;
		}
	}

	for (int i = 0; i < 101; i++) {
		if (arrT[i] == 1)  result += arrT[i] * A;
		else if (arrT[i] == 2) result += arrT[i] * B;
		else if (arrT[i] == 3) result += arrT[i] * C;
	}

	cout << result;
	return 0;
}