//SW Expert Academy
//1954. 달팽이 숫자

#include <iostream>
using namespace std;

int main() {
	int caseNum, num = 1, isFirst = 1,tmp,dir1 = -1,dir2 = -1;
	int result[10][10] = { 0, };
	pair<int, int> crnt;
	make_pair(crnt.first = 0, crnt.second = 0);
	int arrInput[10] = { 0, };

	cin >> caseNum;

	for (int i = 0; i < caseNum; i++) {
		cin >> arrInput[i];
	}

	for (int k = 0; k < caseNum; k++) {
		tmp = arrInput[k];
		while (tmp != 0) {

			if (isFirst == 1) {
				isFirst = 0;
				for (int i = 0; i < tmp; i++) {
					result[crnt.first][crnt.second + i] = num;
					if (i == tmp - 1) crnt.second += i;
					num++;
				}
				tmp--;
			}

			dir1 *= -1;
			for (int i = 0; i < tmp; i++) {
				result[crnt.first + dir1][crnt.second] = num;
				num++;
				crnt.first += dir1;
			}

			for (int i = 0; i < tmp; i++) {
				result[crnt.first][crnt.second + dir2] = num;
				num++;
				crnt.second += dir2;
			}
			dir2 *= -1;

			tmp--;
		}

		cout << "#" << k + 1 << endl;
		for (int i = 0; i < arrInput[k]; i++) {
			for (int j = 0; j < arrInput[k]; j++) {
				cout << result[i][j] << " ";
			}
			cout << endl;
		}

		crnt.first = 0;
		crnt.second = 0;
		dir1 = -1;
		dir2 = -1;
		num = 1;
		tmp = 0;
		isFirst = 1;
	}

	return 0;
}