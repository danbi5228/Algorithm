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

//���� �迭�� �������� ����, ���� �ΰ��� �ٷ� �����ϵ���
//algorithm ��� �߰��ؼ� max �Լ��� ���� ª�� ���� �� �ִ�!