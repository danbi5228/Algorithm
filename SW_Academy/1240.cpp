#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

//get char 로 받아와야함 ?

void findNum(int *x) {
	switch (*x)
	{
	case 3211:
		*x = 0; break;
	case 2221:
		*x = 1; break;
	case 2122:
		*x = 2; break;
	case 1411:
		*x = 3; break;
	case 1132:
		*x = 4; break;
	case 1231:
		*x = 5; break;
	case 1114:
		*x = 6; break;
	case 1312:
		*x = 7; break;
	case 1213:
		*x = 8; break;
	case 3112:
		*x = 9; break;
	default:
		*x = -1; break;
	}
}
int main(void) {
	int caseN, idx = 1, codeNum = 0, result = 0;
	int resultA[8];
	cin >> caseN;
	while (caseN > 0) {
		int N, M, codeN, codeM, height = 1, flag = 0, Allidx = 56, tmp = 0;
		codeNum = 0; result = 0;
		// 세로, 가로크기, 코드의 맨 오른쪽 맨 위 값, 코드 높이

		bool arr[51][101] = { 0 };
		char arrtmp = 0;
		cin >> N >> M;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%1d", &arr[i][j]);
			}
		}


		for (int i = 0; i < N; i++) {
			for (int j = M-1; j >= 0; j--) {
				if (arr[i][j] == 1) {
					codeM = j;
					codeN = i;
					for (int k = i+1; k < N; k++) {
						if (arr[k][j] == 1) { height++; }
						else break;
					}
				}
				if (height > 1) break;
			}
			if (height > 1) break;
		}

		if (height < 5) {
			cout << "#" << idx << " " << 0 << endl;
			idx++;
			caseN--;
			continue;
		}

		for (int i = codeN; i < height; i++) {
			for (int j = codeM; j-56 >= 0; j--) {
				for (int k = 1; k < height; k++) {
					if (arr[codeN][codeM] != arr[codeN + k][codeM]) flag = 1;
				}					
			}
		}
		
		if (flag == 1) {
			cout << "#" << idx << " " << 0 << endl;
			idx++;
			caseN--;
			continue;
		}

		while (tmp != 8) {
			int sumN = 1, power10 = 1, isOne = 1;
			for (int j = 1; j < 8; j++) { 
				if (tmp == 7 && j == 7) {
					codeNum = codeNum + sumN*power10;
					break;
				}
				if (isOne == arr[codeN][codeM - j]) {
					sumN++; continue;
				}
				else {
					codeNum = codeNum + sumN*power10;
					power10 *= 10;
					sumN = 1;
					
					if (isOne == 1) isOne = 0;
					else isOne = 1;
				}
			}
			findNum(&codeNum);
			resultA[7 - tmp] = codeNum;
			tmp++;
			codeM -= 7;
			codeNum = 0;
		}

		codeNum = (resultA[0] + resultA[2] + resultA[4] + resultA[6]) * 3
			+ resultA[1] + resultA[3] + resultA[5] + resultA[7];
		if (codeNum % 10 == 0) {
			for (int i = 0; i < 8; i++) {
				result += resultA[i];
			}
			cout << "#" << idx << " " << result << endl;
		}
		else {
			cout << "#" << idx << " " << 0 << endl;
		}

		idx++;
		caseN--;
	}
}