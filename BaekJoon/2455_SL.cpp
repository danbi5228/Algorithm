#include <iostream>
using namespace std;

int main() {

	int peopleArr[4][2] = { 0, };
	int max = 0;
	int sumP = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> peopleArr[i][j];
		}
	}

	for (int i = 0; i < 4; i++) {
		sumP += peopleArr[i][1] - peopleArr[i][0];
		if (sumP > max) max = sumP;
	}

	cout << max;



	return 0;
}

//굳이 배열에 저장하지 말고, 변수 두개로 바로 저장하도록
//algorithm 헤더 추가해서 max 함수로 더욱 짧게 만들 수 있다!